#ifndef SCOP_TYPES_H
# define SCOP_TYPES_H

#define APP_TITLE "scop"
#define WIDTH 640
#define HEIGHT 480

// envs
#define ENV_FULLSCREEN "SCOP_FULLSCREEN"
#define ENV_RENDERER "SCOP_RENDERER"

// Prevent glfw from pulling gl functions that causes redefinitions
#define GLFW_INCLUDE_NONE

#include <stdint.h>
#include <stdbool.h>
#include <GLFW/glfw3.h>

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef enum e_renderer {
	VULKAN,
	OPENGL
} ScopRenderer;

typedef struct s_setup {
	ScopRenderer renderer;
	bool fullscreen;
	u32 width;
	u32 height;
} ScopSetup;

typedef struct s_ctx ScopContext;
typedef struct s_renderer ScopBackend;

struct s_ctx {
	GLFWwindow* win;
	ScopSetup* setup;
	ScopBackend* rend;
};

struct s_renderer {
	void (*renderer_preinit)();
	void (*renderer_init)(ScopContext*);
	void (*renderer_destroy)();
	void (*renderer_reset)();
};

typedef struct s_model {
	int a;
} Model;

#endif
