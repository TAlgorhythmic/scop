#include "scop_types.h"
#include "win_handler/win_handler.h"
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void loop() {

}

ScopRenderer choose_renderer(const char* renderer) {
	if (!renderer) return VULKAN;

	if (strcmp(renderer, "opengl") == 0)
		return OPENGL;

	return VULKAN;
}

bool is_fullscreen(const char* fullscreen) {
	if (!fullscreen) return false;

	if (strcmp(fullscreen, "0"))
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
		if (strcmp(*argv, "--width") || strcmp(*argv, "-w")) {
			const char* value = argv[1];
			if (strlen(value) > 5)
				exit_error("Param specified is too large");

			width = atoi(value);
		}
		if (strcmp(*argv, "--height") || strcmp(*argv, "-h")) {
			const char* value = argv[1];
			if (strlen(value) > 5)
				exit_error("Param specified is too large");

			height = atoi(value);
		}
	}

	return (ScopSetup){
		.renderer = renderer,
		.fullscreen = fullscreen,
		.width = width,
		.height = height,
	};
}

int main(int argc, char** argv) {
	(void) argc;
	ScopSetup setup = parse_setup(argv);
	GLFWwindow* window = scop_window_create(&setup);
}
