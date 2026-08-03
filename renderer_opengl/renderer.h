#ifndef RENDERER_OPENGL_H
# define RENDERER_OPENGL_H

#include "scop_types.h"

void renderer_gl_load_symbols(GLFWglproc fn);
ScopBackend create_gl_backend();

#endif
