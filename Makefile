NAME		= libft.a
TARGET		= $(BUILD_DIR)/$(NAME)
CC			= cc
AR			= ar -rcs
CFLAGS		= -Wall -Wextra -Werror -g3

OBJ_DIR		= obj
INC			= include
BUILD_DIR	= build

SRC			= src/linkedList/ft_lstadd_back_bonus.c \
			  src/linkedList/ft_lstadd_front_bonus.c \
			  src/linkedList/ft_lstclear_bonus.c \
			  src/linkedList/ft_lstdelone_bonus.c \
			  src/linkedList/ft_lstiter_bonus.c \
			  src/linkedList/ft_lstlast_bonus.c \
			  src/linkedList/ft_lstmap_bonus.c \
			  src/linkedList/ft_lstnew_bonus.c \
			  src/linkedList/ft_lstsize_bonus.c \
			  src/memmory/ft_bzero.c \
			  src/memmory/ft_calloc.c \
			  src/memmory/ft_memchr.c \
			  src/memmory/ft_memcmp.c \
			  src/memmory/ft_memcpy.c \
			  src/memmory/ft_memmove.c \
			  src/monitor/ft_printf.c \
			  src/monitor/ft_printf_fd.c \
			  src/monitor/ft_putchar_fd.c \
			  src/monitor/ft_putendl_fd.c \
			  src/monitor/ft_putnbr_fd.c \
			  src/monitor/ft_putstr_fd.c \
			  src/number/ft_atoi.c \
			  src/number/ft_itoa.c \
			  src/string/argstr.c \
			  src/string/fjoin.c \
			  src/string/fsplit.c \
			  src/string/ft_split.c \
			  src/string/ft_strchr.c \
			  src/string/ft_strdup.c \
			  src/string/ft_striteri.c \
			  src/string/ft_strjoin.c \
			  src/string/ft_strlcat.c \
			  src/string/ft_strlcpy.c \
			  src/string/ft_strlen.c \
			  src/string/ft_strmapi.c \
			  src/string/ft_strncmp.c \
			  src/string/ft_strnstr.c \
			  src/string/ft_strrchr.c \
			  src/string/ft_strtrim.c \
			  src/string/ft_substr.c \
			  src/string/gnl.c \
			  src/utilsFunction/ft_isalnum.c \
			  src/utilsFunction/ft_isalpha.c \
			  src/utilsFunction/ft_isascii.c \
			  src/utilsFunction/ft_isdigit.c \
			  src/utilsFunction/ft_isprint.c \
			  src/utilsFunction/ft_tolower.c \
			  src/utilsFunction/ft_toupper.c \
# delete pathfile(notdie) and delete.c(basname) and add.o(addsuffix) and add obj/(addprefix)
OBJ			= $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(basename $(notdir $(SRC)))))

all: $(NAME)

$(NAME): $(TARGET)

$(TARGET): $(OBJ) | $(BUILD_DIR)
	@$(AR) $@ $(OBJ)
	@printf "\033[38;5;46m\033[1mCompliling \033[38;5;226m\033[1m⟪"
	@for i in $$(seq 1 60); do echo -n "⏹"; sleep 0.055; done; printf "⟫\033[0m\n"

$(OBJ): $(SRC) Makefile | $(OBJ_DIR) #████▒▒▒▒▒▒  ⏹ ⌋ᒧ ᒥ 〈〉 ┫┣ ⟪⟫
	@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(BUILD_DIR)

re: fclean all

.PHONY: clean fclean re
