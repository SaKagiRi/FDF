NAME		= fdf
TARGET		= $(BUILD_DIR)/$(NAME)
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g3

OBJ_DIR		= $(BUILD_DIR)/obj
BUILD_DIR	= build
LIBFT_DIR	= ./lib/KML
MLX_DIR		= ./lib/MLX42

HEADER		= -I ./include -I $(LIBFT_DIR)/include -I $(MLX_DIR)/include
LIBS		= $(LIBFT_DIR)/build/libft.a $(MLX_DIR)/build/libmlx42.a -ldl -lglfw -pthread -lm

SRC			= src/main.c

# delete pathfile(notdie) and delete.c(basname) and add.o(addsuffix) and add obj/(addprefix)
OBJ			= $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(basename $(notdir $(SRC)))))

all: $(NAME)

$(NAME): lib $(TARGET)

$(TARGET): $(OBJ) | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) $(HEADER) -o $@ && printf "\033[38;5;46m\033[1m⟪ Complete ⟫\033[0m\n" 

lib:
	@make -C $(LIBFT_DIR)
	@cmake $(MLX_DIR) -B $(MLX_DIR)/build && make -C $(MLX_DIR)/build -j4

$(OBJ): $(SRC) Makefile | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ $(HEADER)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

clean_lib:
	@rm -rf $(LIBFT_DIR)/obj
	@rm -rf $(MLX_DIR)/build

fclean_lib:
	@rm -rf $(LIBFT_DIR)/build

clean: clean_lib
	@rm -rf $(OBJ_DIR)

fclean: clean fclean_lib
	@rm -rf $(BUILD_DIR)

re: fclean $(NAME)

.PHONY: all clean fclean re clean_lib fclean_lib lib
