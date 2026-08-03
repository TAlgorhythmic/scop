#include <GLFW/glfw3.h>
#include <stdio.h>
#include "scop_types.h"

static void error_callback(int code, const char* description) {
	fprintf(stderr, "Error code %d: %s\n", code, description);
}

bool scop_window_preinit(ScopSetup* setup) {
	glfwSetErrorCallback(error_callback);
	if (!glfwInit()) return false;

	// Generic hints
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
	glfwWindowHint(GLFW_DECORATED, GLFW_TRUE);
	glfwWindowHint(GLFW_FOCUS_ON_SHOW, GLFW_TRUE);
	glfwWindowHint(GLFW_FOCUSED, GLFW_TRUE);
	glfwWindowHint(GLFW_FLOATING, GLFW_FALSE);

	switch (setup->renderer) {
		case VULKAN: {
			glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
			if (glfwVulkanSupported())
				break;
			fprintf(stderr, "Vulkan not supported on this system, falling back to opengl...\n");
			setup->renderer = OPENGL;
		}
		case OPENGL:
		default: {
			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
			glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_API);
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
			glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
			break;
		}
	}

	return true;
}

GLFWwindow* scop_window_create(const ScopSetup* setup) {
	GLFWwindow* win = glfwCreateWindow(setup->width, setup->height, APP_TITLE, NULL, NULL);
	if (!win) return NULL;

	return win;
}

void scop_glfw_destroy(GLFWwindow* win) {
	glfwDestroyWindow(win);
	glfwTerminate();
}
