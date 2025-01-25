#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

# ifndef MAX_BUFFER_SIZE
#  define MAX_BUFFER_SIZE 1024
# endif

typedef struct s_flags
{
	int	left;
	int	zero;
	int	plus;
	int	space;
	int	width;
	int	prec;
	int	neg;
	int	hash;
}	t_flags;

// main
int		ft_printf(const char *format, ...);
int		ft_printformat(const char *format, int *i, va_list args);

// utils
int		pad(int padding, char with);
int		print_num_string(char *num, int len, t_flags flags);
int		handle_flags_num(char *num, int padding, int len, t_flags flags);
char	*utoa(unsigned int n);
int		pad_hex(int padding, int len, t_flags flags);

// helpers
void	parse_flags(const char *fmt, int *i, t_flags *flags);
int		print_char_flags(int c, t_flags flags);
int		print_char(int c);
int		print_hex_lower(unsigned int n, t_flags flags);
int		print_hex_upper(unsigned int n, t_flags flags);
int		print_int(int n, t_flags flags);
int		print_pointer(void *ptr, t_flags flags);
int		print_string_flags(char *str, t_flags flags);
int		print_string_len(char *str, int len);
int		print_string(char *str);
int		print_unsigned(unsigned int n, t_flags flags);

#endif