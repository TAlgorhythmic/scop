#ifndef WIN_HANDLER_H
# define WIN_HANDLER_H

#include "scop_types.h"
#include <GLFW/glfw3.h>

bool scop_window_preinit();
GLFWwindow* scop_window_create(const ScopSetup* setup);
void scop_glfw_destroy(GLFWwindow* win);

#endif
