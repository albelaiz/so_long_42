NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -L ./minilibx -lmlx -framework OpenGL -framework AppKit

SRC = checker_map.c\
	  get_next_line/get_next_line.c\
	get_next_line/get_next_line_utils.c\
	ft_printf.c\
		ft_putstr.c\
		ft_putchar.c\
		ft_putnbr.c\
		ft_unbr.c\
		ft_puthex.c\
		ft_putaddres.c\
		ft_strlen.c\
	  main.c\
	  read_map.c\
	  ft_strlen1.c\
	  put_imag.c\
	  link.c\
	  key.c\
	  flood_fill.c\
	  checker_map.c\

OBJ = $(SRC:.c=.o)
# LIB = so_long.a

all: $(NAME)

$(NAME): $(OBJ) so_long.h ./get_next_line/get_next_line.h
	$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) -o $(NAME)

# $(LIB): $(OBJ)
# 	ar rcs $(LIB) $(OBJ)

# %.o: %.c
# 	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) 

re: fclean all
