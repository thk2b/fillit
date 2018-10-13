NAME = fillit
LIBFT = libft/libft.a

SRC =\
	validate_piece.c\
	standardize_piece.c\
	pieces.c\
	main.c\
	grid.c\
	llist.c\
	fillit.c\

OBJ = $(SRC:.c=.o)

CC = gcc
FLAGS = -Wall -Wextra -Werror
INCLUDES = -I libft/includes

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(FLAGS) $(INCLUDES) $(LIBFT) $(OBJ) -o $(NAME)

$(LIBFT):
	make -C libft

%.o: %.c
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

clean:
	make clean -C libft
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all
