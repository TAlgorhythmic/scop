#include <GLFW/glfw3.h>
#include <stdio.h>
#include "scop_types.h"

static void error_callback(int code, const char* description) {
	fprintf(stderr, "Error code %d: %s\n", code, description);
}

GLFWwindow* scop_window_create(const ScopSetup* setup) {
	if (!glfwInit()) return NULL;
	glfwSetErrorCallback(error_callback);

	GLFWwindow* win = glfwCreateWindow(setup->width, setup->height, APP_TITLE, NULL, NULL);
	if (!win) return NULL;
	glfwMakeContextCurrent(win);

	return win;
}

void scop_glfw_destroy(GLFWwindow* win) {
	glfwDestroyWindow(win);
	glfwTerminate();
}
