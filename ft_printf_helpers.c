#include "ft_printf.h"

int print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int print_hex_lower(int n, t_flags flags)
{
	
}

int print_hex_upper(int n, t_flags flags)
{
	
}

int print_int(int n, t_flags flags)
{

}

int print_unsigned(unsigned int n, t_flags flags)
{

}

int print_pointer(void *ptr, t_flags flags)
{
	
}

int print_string(char *str, t_flags flags)
{
	int len;
	int printed;
	int i;

	i = 0;
	printed = 0;
	len = ft_strlen(str);
	if (!str)
		str = "(null)";

	while (str[i] && (flags.prec == -1 || i < flags.prec))
		write(1, &str[i++], 1);
	return (i);	
}