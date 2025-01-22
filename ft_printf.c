#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
	int i;
	int len;
	va_list args;

	i = 0;
	len = 0;
	va_start(args, format);
	while(format[i])
	{
		if (format[i] == '%')
		{
			i++;
			len += ft_printformat(format, &i, args);
		}
		else
		{
			len += print_char(format[i]);
		}
		i++;
	}
	va_end(args);
	return (len);
}

int ft_printformat(const char *format, int *i, va_list args)
{
	t_flags flags;
	
	parse_flags(format, i, &flags);
	if (format[*i] == 's')
		return(print_string_flags(va_arg(args, char *), flags));
	else if (format[*i] == 'c')
		return (print_char(va_arg(args, int)));
	else if (format[*i] == 'p')
		return (print_pointer(va_arg(args, void *), flags));
	else if (format[*i] == 'd' || format[*i] == 'i')
		return (print_int(va_arg(args, int), flags));
	else if (format[*i] == 'u')
		return (print_unsigned(va_arg(args, unsigned int), flags));
	else if (format[*i] == 'x')
		return (print_hex_lower(va_arg(args, unsigned int), flags));
	else if (format[*i] == 'X')
		return (print_hex_upper(va_arg(args, unsigned int), flags));
	else
		return (print_char(format[*i]));
	return (0);
}