CC = cc 
CFLAGS = -Wall -Wextra -Werror
SRC = push_swap.c  tools.c tools2.c tools3.c tools4.c\
	ft_split.c chunk_sort.c bubble_sort.c small_sort.c\
	op_stack_a.c op_stack_b.c mem_management.c
OBJ = $(SRC:.c=.o)
NAME = push_swap

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: clean fclean all

.PHONY: all clean fclean re

.SECONDARY: $(OBJ)