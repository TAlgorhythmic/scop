#include "renderer_opengl/renderer.h"
#include "renderer_vulkan/renderer.h"
#include "scop_types.h"
#include "win_handler/win_handler.h"
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ScopRenderer choose_renderer(const char* renderer) {
	if (!renderer) return OPENGL;

	if (strcmp(renderer, "vulkan") == 0 && glfwVulkanSupported())
		return VULKAN;

	return OPENGL;
}

bool is_fullscreen(const char* fullscreen) {
	if (!fullscreen) return false;

	if (strcmp(fullscreen, "0") == 0)
		return false;

	return true;
}

void exit_error(const char* err) {
	fprintf(stderr, "Fatal error: %s\n", err);
	exit(1);
}

ScopSetup parse_setup(char** argv) {
	bool fullscreen = is_fullscreen(getenv(ENV_FULLSCREEN));
	ScopRenderer renderer = choose_renderer(getenv(ENV_RENDERER));
	u32 width = WIDTH;
	u32 height = HEIGHT;

	++argv; // Discard executable name
	for (; *argv; ++argv) {
		if (strcmp(*argv, "--width") == 0 || strcmp(*argv, "-w") == 0) {
			const char* value = argv[1];
			if (strlen(value) > 5)
				exit_error("Param specified is too large");

			width = atoi(value);
		}
		if (strcmp(*argv, "--height") == 0 || strcmp(*argv, "-h") == 0) {
			const char* value = argv[1];
			if (strlen(value) > 5)
				exit_error("Param specified is too large");

			height = atoi(value);
		} else {
			fprintf(stderr, "Failed to parse option: %s\n", *argv);
			exit(1);
		}
	}

	return (ScopSetup){
		.renderer = renderer,
		.fullscreen = fullscreen,
		.width = width,
		.height = height,
	};
}

void loop(ScopContext* ctx) {
	ScopBackend r = *ctx->rend;

	r.renderer_reset_color();
	while (!glfwWindowShouldClose(ctx->win)) {
		r.renderer_reset();
		glfwSwapBuffers(ctx->win);
		glfwWaitEvents();
	}
}

int main(int argc, char** argv) {
	(void) argc;
	if (!scop_window_preinit()) {
		fprintf(stderr, "Failed to initialize glfw\n");
		return 1;
	}
	ScopBackend rend;
	/*if (setup.renderer == VULKAN)
		rend = create_vk_backend();*/
	/*else */rend = create_gl_backend();
	rend.renderer_preinit();

	ScopSetup setup = parse_setup(argv);
	GLFWwindow* window = scop_window_create(&setup);
	if (!window) {
		fprintf(stderr, "Failed to initialize window\n");
		return 1;
	}

	ScopContext ctx = {
		.win = window,
		.setup = &setup,
		.rend = &rend,
	};

	rend.renderer_init(&ctx);

	loop(&ctx);

	rend.renderer_destroy();
	scop_glfw_destroy(ctx.win);
}
