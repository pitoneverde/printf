NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c ft_printf_utils.c \
		parse_flags.c print_char.c print_string.c \
		print_hex.c print_int.c print_unsigned.c \
		print_pointer.c

OBJ = $(SRC:.c=.o)

LIBFT = libft

all: $(NAME)

$(LIBFT)/libft.a:
	$(MAKE) all -C $(LIBFT)

$(NAME): $(LIBFT)/libft.a $(OBJ)
	cp $(LIBFT)/libft.a $(NAME)
	ar rcs $(NAME) $(OBJ)
	
$(OBJ): $(SRC)
	cc -c $^ $(CFLAGS)

clean:
	rm -f $(OBJ)
	$(MAKE) clean -C $(LIBFT)

fclean:
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT)

re: clean all

bonus: all

.PHONY: all clean fclean re bonus
