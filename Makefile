CC = cc 
FLAGS = -Wall -Wextra -Werror
SRC = push_swap.c  tools.c tools2.c tools3.c\
	ft_split.c 
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

.SECONDARY: