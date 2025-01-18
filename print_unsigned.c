#include "ft_printf.h"

int print_unsigned(unsigned int n, t_flags flags)
{
	char *num;
	int len;
	int printed;
	int padding;

	printed = 0;
	padding = 0;
	if (n <= INT_MAX)
		num = ft_itoa(n);
	else
	 	num = utoa(n);
	len = ft_strlen(num);
	printed += print_num_string(num, padding, len, &flags);
	free(num);
	return (printed);
}