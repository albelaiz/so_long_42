NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -L ./minilibx -lmlx -framework OpenGL -framework AppKit

SRC = checker_map.c\
	  get_next_line.c\
	  get_next_line_utils.c\
	  main.c\
	  read_map.c\
	  ft_strlen1.c\
	  put_imag.c\
	  link.c\
	  key.c\

OBJ = $(SRC:.c=.o)
LIB = so_long.a

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLX_FLAGS) -o $(NAME)

$(LIB): $(OBJ)
	ar rcs $(LIB) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) $(LIB)

re: fclean all
