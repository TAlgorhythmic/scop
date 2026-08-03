#include "renderer.h"

void* renderer_gl_preinit(ScopContext* ctx) {

}

void* renderer_gl_init(ScopContext* ctx) {
	
}

ScopBackend create_gl_backend() {
	return (ScopBackend){
		.renderer_preinit = renderer_gl_preinit,
		.renderer_init = renderer_gl_preinit,
	};
}
