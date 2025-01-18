#include "ft_printf.h"

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
	{
		flags.neg = 1;
		num++;
		len--;
	}
	printed += print_num_string(num, padding, len, &flags);
	free(original);
	return (printed);
}