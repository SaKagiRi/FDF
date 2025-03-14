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
FILE_S2		= bind.c key.c readconfig.c variable.c default.c
FILE_S3		= drawline.c mlxinit.c texture.c projection.c math.c cache.c control_function.c utils_function.c set_color.c default.c check_in_window.c

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
	@rm -rf $(LIBFT_DIR)/kml.a
	@rm -rf ~/.kconf

clean: clean_lib
	@rm -rf $(OBJ)

fclean: clean fclean_lib
	@rm -rf $(BUILD_DIR)

re: fclean $(NAME)

config:
	@printf 'set -v default 0\nset -b ESCAPE ft_escape\nset -b x ft_zoom_out\nset -b z ft_zoom_in\nset -b w ft_rotate_x_up\nset -b s ft_rotate_x_down\nset -b e ft_rotate_y_up\nset -b q ft_rotate_y_down\nset -b d ft_rotate_z_up\nset -b a ft_rotate_z_down\nset -b UP ft_move_up\nset -b DOWN ft_move_down\nset -b LEFT ft_move_left\nset -b RIGHT ft_move_right\n\n# --wtf config-- #\n# set -v move 30\n# set -v rotate 30\n# set -v zoom 20\n\n# set -v start_x 1\n# set -v start_y 1\n\n# set -v color #0\n# set -v background #FFFFFF\n\nset -v move 2\nset -v rotate 2\nset -v zoom 1\n\nset -b <L_CTRL-a> birdview\nset -b <L_CTRL-d> iso\n\n# set -v disco 1\n# set -v enable_rot_color 1\n# set -v rot_color_mode 2' > ~/.kconf

.PHONY: all clean fclean re clean_lib fclean_lib lib config
