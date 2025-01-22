#include "ft_printf.h"

// alloca 17 perché un unsigned long long è max 16 cifre hex
int pad_hex(int padding, int len, t_flags *flags)
{
	int printed;

	printed = 0;
	if (flags->width > len + padding && flags->zero && !flags->left)
		printed += pad(flags->width - len - padding, '0');
	else
		printed += pad(flags->width - len - padding, ' ');
	return(printed);
}

char *build_hex(unsigned int n, const char *digits)
{
	char *hex;
	int len;
	unsigned int num;

	len = 0;
	if (!n || n == 0)
		return (ft_strdup("0"));
	num = n;
	while (n > 0)
	{
		n /= 16;
		len++;
	}
	hex = (char*)malloc(len + 1);
	if (!hex)
	 	return (NULL);
	hex[len] = '\0';
	while (len > 0)
	{
		// ft_printf("len=%i\n", len);
		hex[--len] = digits[num % 16];
		num /= 16;
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
	char pad_char;

	printed = 0;
	if (flags->prec > len)
	{
		padding = flags->prec - len;
		len += padding;
	}
	else if (flags->zero)
		pad_char = '0';
	else
		pad_char = ' ';
	
	if (flags->width > len + flags->neg && !flags->left)
		printed += pad(flags->width - len + flags->neg, pad_char);
	printed += pad(padding, '0');
	printed += print_string(num);
	if (flags->width > len + flags->neg && flags->left)
		printed += pad(flags->width - len + flags->neg, ' ');
	return(printed);
}

int pad(int padding, char with)
{
	int printed;

	printed = 0;
	if (padding > 0)
	{
		while (padding--)
		{
			print_char(with);
			printed++;
		}
	}
	return (printed);
}