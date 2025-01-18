#include "ft_printf.h"

int print_string_flags(char *str, t_flags flags)
{
	int len;
	int padding;
	int printed;

	printed = 0;
	len = ft_strlen(str);
	if (flags.prec >= 0 && flags.prec < len)
		len = flags.prec;
	if (!str)
		str = "(null)";
	padding = flags.width - len;
	if (padding > 0 && !flags.left)
		printed += pad(padding, ' ');
	printed += print_string(str);
	if (padding > 0 && flags.left)
		printed += pad(padding, ' ');
	return (printed);
}
int print_string(char *str)
{
	int printed;
	int i;

	i = 0;
	printed = 0;
	while (str[i])
		printed += print_char(str[i++]);
	return (printed);
}