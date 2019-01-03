NAME = wolf3d
SRC = main.c \
	  get_next_line.c\
	  draw.c\
	  rotate.c\
	  checker.c\

LIB	= ./libft/libft.a

OBJ = $(SRC:.c=.o)
CC = gcc
FLAGS = -Wall -Wextra -Werror 


all: $(NAME)

$(NAME): $(OBJ)
	@make -C ./libft/ re
	@$(CC) -g -o $(NAME) $(OBJ) $(FLAGS) -I. $(LIB) -I minilibx_macos -lmlx -framework OpenGL -framework AppKit

 %.o: %.c
	@$(CC) -c -o $@ $(FLAGS) $^

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re:	fclean all
