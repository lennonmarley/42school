NAME = fractol
CC = gcc
SRCS = 	main.c \
		mandelbrot.c \
		event.c \
		pixelput.c \
		julia.c \
		julia_atomos.c

CFLAGS = -Wall -Wextra -Werror -Ofast -march=native
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
