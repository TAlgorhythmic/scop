#include <GLFW/glfw3.h>
#include <stdio.h>
#include "scop_types.h"

static void error_callback(int code, const char* description) {
	fprintf(stderr, "Error code %d: %s\n", code, description);
}

bool scop_window_preinit() {
	glfwSetErrorCallback(error_callback);
	if (!glfwInit()) return false;

	// Generic hints
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
	glfwWindowHint(GLFW_FLOATING, GLFW_FALSE);

	return true;
}

GLFWwindow* scop_window_create(const ScopSetup* setup) {
	if (setup->fullscreen) {
		GLFWmonitor* monitor = glfwGetPrimaryMonitor();
		if (!monitor) return NULL;

		const GLFWvidmode* vidmode = glfwGetVideoMode(monitor);
		if (!vidmode) return NULL;

		return glfwCreateWindow(vidmode->width, vidmode->height, APP_TITLE, monitor, NULL);
	}
	GLFWwindow* win = glfwCreateWindow(setup->width, setup->height, APP_TITLE, NULL, NULL);
	if (!win) return NULL;

	return win;
}

void scop_glfw_destroy(GLFWwindow* win) {
	glfwDestroyWindow(win);
	glfwTerminate();
}
