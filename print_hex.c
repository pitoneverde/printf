#include "ft_printf.h"

static char	*build_hex(unsigned int n, const char *digits);

int	print_hex_lower(unsigned int n, t_flags flags)
{
	char	*num;
	int		len;
	int		printed;
	int		padding;

	num = build_hex(n, "0123456789abcdef");
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
	printed += pad_hex(padding, len, flags);
	printed += pad(padding, '0');
	printed += print_string(num);
	free(num);
	return (printed);
}

int	print_hex_upper(unsigned int n, t_flags flags)
{
	char	*num;
	int		len;
	int		printed;
	int		padding;

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
	printed += pad_hex(padding, len, flags);
	printed += pad(padding, '0');
	printed += print_string(num);
	free(num);
	return (printed);
}

static char	*build_hex(unsigned int n, const char *digits)
{
	char			*hex;
	int				len;
	unsigned int	num;

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
