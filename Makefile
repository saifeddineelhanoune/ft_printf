NAME = libft_printf.a
SRC = $(shell ls ft_*.c)
HEADER = ft_printf.h 
OBJ = $(SRC:.c=.o)
CFLAGS += -Wall -Werror -Wextra 
all : $(NAME)
	@echo "compiling targets $(shell ls ft_*.c)"
$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)
%.c : %.o $(HEADER)
	cc -c $(CFLAGS) $<
clean : 
	rm -f $(OBJ)
fclean : 
	rm -f $(NAME)
re : fclean all