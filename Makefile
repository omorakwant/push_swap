CC = cc
FLAGS = -Wall -Wextra -Werror
NAME = pushswap
OBJ = push_swap.o

PRINTF = ft_printf/
LIBFT = libft/
PRINTFA = ft_printf/printf.a
LIBFTA = libft/libft.a

all: $(LIBFTA) $(PRINTFA) $(NAME)

$(LIBFTA):
	make -C $(LIBFT)
$(PRINTFA):
	make -C $(PRINTF)

pushswap: push_swap.o
	$(CC) $(FLAGS) push_swap.o $(PRINTF)printf.a $(LIBFT)libft.a -o pushswap

clean:
	make clean -C $(PRINTF)
	make clean -C $(LIBFT)
	rm -f *.o

fclean: clean
	make fclean -C $(PRINTF)
	make fclean -C $(LIBFT)
	rm -rf $(NAME) $(BONUS)
	
re : fclean all

.SECONDARY: $(OBJ)