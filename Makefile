#SETUP
NAME		=	so_long
CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror
RM			=	rm -rf

#FILES AND PATH
HEADER_SRCS	=	so_long.h 
HEADER_DIR	=	includes/
HEADER		=	$(addprefix $(HEADER_DIR), $(HEADER_SRCS))
SRCS		=	main.c ft_error.c init_game.c \
				init_layer.c init_map.c \
				utility.c parser_input.c floodfill.c\
				init_image.c init_map_texture.c event.c


SRC_DIR		=	src/
SRC_PATH	=	$(addprefix $(SRC_DIR), $(SRCS))
OBJ			=	$(SRC_PATH:.c=.o)

#LIBRARY 1
LIBFT_PATH 	= ./libft
LIBFT		= $(LIBFT_PATH)/libft.a

#LIBRARY 2
MINILIBX_PATH 	= ./minilibx
MINILIBX		= $(MINILIBX_PATH)/libmlx.a

#LIBRARY 3
GIT_MUSIC = git clone https://github.com/mackron/miniaudio miniaudio
MINIAUDIO_PATH 	= ./miniaudio

#COMMANDS
%.o: %.c $(HEADER) Makefile
				@${CC} ${FLAGS} -c $< -o $@

all:			$(LIBFT) $(MINILIBX) download_music $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -L$(LIBFT_PATH) -lft -L$(MINILIBX_PATH) -lmlx -framework OpenGL -framework AppKit -o $(NAME) 
	@echo -e "$(GREEN)$(NAME) created!$(DEFAULT)"

$(LIBFT):
	@$(MAKE) -C libft -f Makefile

$(MINILIBX):
	@$(MAKE) -C minilibx -f Makefile

clean:
				@$(RM) $(OBJ)
#				make -C $(LIBFT_PATH) clean
				@echo -e "$(YELLOW)object files deleted!$(DEFAULT)"

fclean:			clean
				@$(RM) $(NAME)
#				make -C $(LIBFT_PATH) fclean
				@echo -e "$(RED)all deleted!$(DEFAULT)"

re:				fclean all

download_music:
				@if [ ! -d "$(MINIAUDIO_PATH)" ]; then \
				$(GIT_MUSIC); \
				else \
				echo "miniaudio already downloaded"; \
				fi

undownload_music:
				@$(RM) $(MINIAUDIO_PATH)

.PHONY:			all clean fclean re

#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m