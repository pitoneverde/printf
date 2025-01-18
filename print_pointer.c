#include "ft_printf.h"

int print_pointer(void *ptr, t_flags flags)
{
	char *str;
	int len;
	int printed;
	int padding;
	unsigned long long	mem;

	mem = (unsigned long long)ptr;
	str = build_hex(mem, "0123456789abcdef");
	len = ft_strlen(str);
	printed = 0;
	padding = 0;
	if (flags.prec > len)
	{
		padding = flags.prec - len;
		len = padding;
	}
	printed += pad_hex(str, padding, len, &flags);
	printed += print_string("0x");
	printed += pad(padding, '0');
	printed += print_string(str);
	free(str);
	return (printed);
}