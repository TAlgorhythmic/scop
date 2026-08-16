#include "renderer.h"
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>

void renderer_gl_preinit() {
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_API);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
}

void renderer_gl_init(ScopContext* ctx) {
	glfwMakeContextCurrent(ctx->win);
	if (!renderer_gl_load_symbols()) {
		fprintf(stderr, "Failed to get opengl functions\n");
		exit(1);
	}
}

void renderer_gl_destroy() {
	
}

void renderer_gl_reset_color() {
	glClearColor(0, 0, 0, 1.0f);
}

void renderer_gl_reset() {
	glClear(GL_COLOR_BUFFER_BIT);
}

ScopBackend create_gl_backend() {
	return (ScopBackend){
		.renderer_preinit = renderer_gl_preinit,
		.renderer_init = renderer_gl_init,
		.renderer_destroy = renderer_gl_destroy,
		.renderer_reset = renderer_gl_reset,
		.renderer_reset_color = renderer_gl_reset_color,
	};
}
