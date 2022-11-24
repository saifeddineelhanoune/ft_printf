NAME = libft_printf.a
SRC = $(shell ls ft_*.c)
HEADER = ft_printf.h 
all : $(NAME)
	@echo "compiling targets $(shell ls ft_*.c) "