#include "ft_printf.h"

int print_hex_lower(unsigned int n, t_flags flags)
{
	char *num;
	char *digits;
	int len;
	int printed;
	int padding;

	digits = "0123456789abcdef";
	num = build_hex(n, digits);
	len = ft_strlen(num);
	printed = 0;
	padding = 0;
	if (flags.hash)
		printed += print_string("0x");
	if (flags.prec > len)
	{
		padding = flags.prec - len;
		len = padding;
	}
	printed += pad_hex(padding, len, &flags);
	printed += pad(padding, '0');
	printed += print_string(num);
	free(num);
	return (printed);
}

int print_hex_upper(unsigned int n, t_flags flags)
{
	char *num;
	int len;
	int printed;
	int padding;

	num = build_hex(n, "0123456789ABCDEF");
	len = ft_strlen(num);
	printed = 0;
	padding = 0;
	if (flags.hash)
		printed += print_string("0X");
	if (flags.prec > len)
	{
		padding = flags.prec - len;
		len = padding;
	}
	printed += pad_hex(padding, len, &flags);
	printed += pad(padding, '0');
	printed += print_string(num);
	free(num);
	return (printed);
}
