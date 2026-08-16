#include "renderer.h"
#include <GLFW/glfw3.h>

#define GL_DECL_DEF(type, name) type gl##name;
GL_FUNCS(GL_DECL_DEF)

#define GL_LOAD_FUNCS(type, name) \
	gl##name = (type)glfwGetProcAddress("gl" #name); \
	if (!gl##name) return false;

bool renderer_gl_load_symbols() {
	GL_FUNCS(GL_LOAD_FUNCS)
	return true;
}
