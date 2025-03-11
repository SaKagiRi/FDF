NAME		= fdf
TARGET		= $(BUILD_DIR)/$(NAME)
CC			= cc
CFLAGS		= -g3#-Wall -Wextra -Werror -g3

OBJ_DIR		= $(BUILD_DIR)/obj
BUILD_DIR	= build
LIBFT_DIR	= ./lib/KML
MLX_DIR		= ./lib/MLX42

HEADER		= -I ./include -I $(LIBFT_DIR)/include -I $(MLX_DIR)/include
LIBS		= $(LIBFT_DIR)/kml.a $(MLX_DIR)/build/libmlx42.a -ldl -lglfw -pthread -lm

FILE_M		= clear.c main.c init.c get_variable.c
FILE_S1		= parser.c store_map.c endstage.c
FILE_S2		= bind.c key.c readconfig.c variable.c
FILE_S3		= drawline.c mlxinit.c texture.c projection.c math.c cache.c

MAIN		= $(addprefix src/main/, $(FILE_M))
STAGE_1		= $(addprefix src/stage_1/, $(FILE_S1))
STAGE_2		= $(addprefix src/stage_2/, $(FILE_S2))
STAGE_3		= $(addprefix src/stage_3/, $(FILE_S3))

SRC			= $(MAIN) $(STAGE_1) $(STAGE_2) $(STAGE_3)

OBJ			= $(SRC:.c=.o)

all: $(NAME)

$(NAME): lib $(TARGET)

$(TARGET): $(OBJ) | $(BUILD_DIR)
		@$(CC) $(CFLAGS) $(OBJ) $(LIBS) $(HEADER) -o $@
		@printf "\033[38;5;46m\033[1m⟪ Complete ⟫\033[0m\n"

lib:
	@make -C $(LIBFT_DIR)
	@cmake $(MLX_DIR) -B $(MLX_DIR)/build && make -C $(MLX_DIR)/build -j4

%.o: %.c Makefile
	@$(CC) $(CFLAGS) -c $< -o $@ $(HEADER)

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
	@rm -rf $(OBJ)

fclean: clean fclean_lib
	@rm -rf $(BUILD_DIR)

re: fclean $(NAME)

.PHONY: all clean fclean re clean_lib fclean_lib lib
