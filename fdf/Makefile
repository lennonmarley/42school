NAME = fdf
CC = gcc
SRCS = main.c \
	listing.c \
	window.c  \
	pixel_put.c\
	bresenham.c\
	event.c
CFLAGS = -Wall -Wextra -Werror -ggdb -g
FLAGS = -framework OpenGL -framework AppKit -L ./libft -lft -L minilibx_macos -lmlx
OBJS = $(SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./libft
	make -C minilibx_macos
	$(CC) $(FLAGS) -o  $(NAME) $^ ./libft/libft.a
	gcc $(FLAGS) -o $(NAME) $(OBJS)  -L./libft -lft -framework OpenGL -framework AppKit -L ./libft -lft -L minilibx_macos -lmlx

clean:
	rm $(OBJS)

fclean: clean
	rm $(NAME)

re: fclean all
