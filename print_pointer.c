#include "ft_printf.h"

static char	*build_pointer(unsigned long n, const char *digits);

int	print_pointer(void *ptr, t_flags flags)
{
	char			*str;
	int				len;
	int				printed;
	int				padding;
	unsigned long	mem;

	if (!ptr)
		return (print_string("(nil)"));
	mem = (unsigned long)ptr;
	str = build_pointer(mem, "0123456789abcdef");
	len = ft_strlen(str);
	printed = 0;
	padding = 0;
	if (flags.prec > len)
	{
		padding = flags.prec - len;
		len = padding;
	}
	printed += pad_hex(padding, len, flags);
	printed += print_string("0x");
	printed += pad(padding, '0');
	printed += print_string(str);
	free(str);
	return (printed);
}

static char	*build_pointer(unsigned long n, const char *digits)
{
	char			*hex;
	int				len;
	unsigned long	num;

	len = 0;
	if (!n || n == 0)
		return (ft_strdup("0"));
	num = n;
	while (n > 0)
	{
		n /= 16;
		len++;
	}
	hex = (char *)malloc(len + 1);
	if (!hex)
		return (NULL);
	hex[len] = '\0';
	while (len > 0)
	{
		hex[--len] = digits[num % 16];
		num /= 16;
	}
	return (hex);
}
