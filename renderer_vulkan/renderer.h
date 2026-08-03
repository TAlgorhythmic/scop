#ifndef RENDERER_VULKAN_H
# define RENDERER_VULKAN_H

#include "scop_types.h"

void renderer_vk_load_symbols(GLFWglproc fn);
ScopBackend create_vk_backend();

#endif
