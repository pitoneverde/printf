NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror -g

SRC = ft_printf.c ft_printf_utils.c \
		parse_flags.c print_char.c print_string.c \
		print_hex.c print_int.c print_unsigned.c \
		print_pointer.c

OBJ = $(SRC:.c=.o)

LIBFT = libft

all: $(NAME)

$(LIBFT):
	$(MAKE) all -C $(LIBFT)

$(NAME): $(LIBFT) $(OBJ)
	cp $(LIBFT)/libft.a $(NAME)
	ar rcs $(NAME) $(OBJ)
	
$(OBJ): $(SRC)
	cc -c $^ $(CFLAGS)

clean:
	rm -f $(OBJ)
	$(MAKE) clean -C $(LIBFT)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT)

re: fclean all

bonus: all

.PHONY: $(LIBFT)