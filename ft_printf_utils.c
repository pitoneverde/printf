#include "ft_printf.h"

// alloca 17 perché un unsigned long long è max 16 cifre hex
int pad_hex(char *num, int padding, int len, t_flags *flags)
{
	int printed;

	printed = 0;
	if (flags->width > len + padding && flags->zero && !flags->left)
		printed += pad(flags->width - len - padding, '0');
	else
		printed += pad(flags->width - len - padding, ' ');
	return(printed);
}

char *build_hex(unsigned long long n, const char *digits)
{
	char *hex;
	int len;
	unsigned long long num;

	num = n;
	len = 0;
	if (n == 0)
		return ft_strdup(&digits[0]);
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	hex = (char*)malloc(17);
	if (!hex)
		return (NULL);
	hex[len] = '\0';
	while (len > 0)
	{
		hex[--len] = digits[num % 16];
		num /= 10;
	}
	return (hex);
}

char *utoa(unsigned int n)
{
	char *str;
	int len;
	unsigned int num;

	num = n;
	len = 0;
	if (n == 0)
		return ft_strdup("0");
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	str = (char *)malloc(len + 1);
	if  (!str)
		return (NULL);
	str[len] = '\0';
	while (len > 0)
	{
		str[--len] = (num % 10) + '0';
		num /= 10;
	}
	return (str);
}

int print_num_string(char *num, int padding, int len, t_flags *flags)
{
	int printed;

	printed = 0;
	if (flags->prec > len)
	{
		padding = flags->prec - len;
		len = padding;
	}
	if (flags->width > len + padding + flags->neg && flags->zero && !flags->left)
		printed += pad(flags->width - len - padding - flags->neg, '0');
	else
		printed += pad(flags->width - len - padding - flags->neg, ' ');
	if (flags->neg)
		printed += print_char('-');
	printed += pad(padding, '0');
	printed += print_string(num);
	return(printed);
}

int pad(int padding, char with)
{
	int printed;

	printed = 0;
	if (padding <= 0)
		return (0);
	while (padding--)
	{
		print_char(with);
		printed++;
	}
	return (printed);
}