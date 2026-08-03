NAME		= scop
CC			= cc
FLAGS		= -Wall -Wextra -Werror -MMD -O3 -std=gnu17

SRC_OPENGL_DIR			= renderer_opengl
SRC_VULKAN_DIR			= renderer_vulkan
SRC_WIN_HANDLER_DIR		= win_handler
SRC_UTILS_DIR			= utils
HDRS					= header

SRC = main.c $(wildcard $(SRC_WIN_HANDLER_DIR)/*.c) \
	  $(wildcard $(SRC_OPENGL_DIR)/*.c) \
	  $(wildcard $(SRC_VULKAN_DIR)/*.c) \
	  $(wildcard $(SRC_UTILS_DIR)/*.c)

OBJ_DIR	= .build
OBJ		= $(SRC:%.c=$(OBJ_DIR)/%.o)
DEPS	= $(OBJ:.o=.d)

INCLUDES	= -I$(HDRS)
LIBS		= -lglfw -lm -lGL

all: $(NAME)

$(OBJ_DIR)/%.o: %.c Makefile
	@mkdir -p $(dir $@)
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(LIBS) -o $(NAME)

debug:
	$(MAKE) FLAGS="-Wall -Wextra -Werror -MMD -MP -g3 -fsanitize=address,undefined"

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re debug

-include $(DEPS)
