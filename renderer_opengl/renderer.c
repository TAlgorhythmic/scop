#include "renderer.h"
#include <GLFW/glfw3.h>

void renderer_gl_preinit(ScopContext* ctx) { (void)ctx; }

void renderer_gl_init(ScopContext* ctx, GLFWglproc fn) {
	renderer_gl_load_symbols(fn);
	glfwMakeContextCurrent(ctx->win);
}

ScopBackend create_gl_backend() {
	return (ScopBackend){
		.renderer_preinit = renderer_gl_preinit,
		.renderer_init = renderer_gl_init,
	};
}
