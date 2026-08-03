#include <GLFW/glfw3.h>
#include <stdio.h>
#include "scop_types.h"

static void error_callback(int code, const char* description) {
	fprintf(stderr, "Error code %d: %s\n", code, description);
}

const GLFWwindow* scop_window_create(int width, int height) {
	if (!glfwInit()) return NULL;
	glfwSetErrorCallback(error_callback);


	GLFWwindow* win = glfwCreateWindow(width, height, APP_TITLE, GLFWmonitor *monitor, GLFWwindow *share);
}

void scop_glfw_destroy(GLFWwindow* win) {
	glfwDestroyWindow(win);
	glfwTerminate();
}
