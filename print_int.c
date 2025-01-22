#include "ft_printf.h"

static int handle_flags(char *num, int padding, int len, t_flags *flags);
int print_int(int n, t_flags flags)
{
	char *num;
	char *original;
	int len;
	int printed;
	int padding;

	num = ft_itoa(n);
	original = num;
	len = ft_strlen(num);
	printed = 0;
	padding = 0;
	if (n < 0)
		flags.neg = 1;
	printed += handle_flags(num, padding, len, &flags);
	free(original);
	return (printed);
}
static int handle_flags(char *num, int padding, int len, t_flags *flags)
{
	int printed;

	printed = 0;
	if (flags->neg)
	{
		num++;
		printed += print_char('-');
		len--;
	}
	else if (flags->plus)
		printed += print_char('+');
	else if (flags->space)
		printed += print_char(' ');
	printed += print_num_string(num, padding, len, flags);
	return (printed);
}