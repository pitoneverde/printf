/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabruma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:13:43 by sabruma           #+#    #+#             */
/*   Updated: 2025/01/29 17:13:47 by sabruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pad_hex(int padding, int len, t_flags flags)
{
	int	printed;

	printed = 0;
	if (flags.width > len + padding && flags.zero && !flags.left)
		printed += pad(flags.width - len - padding - 2, '0');
	else
		printed += pad(flags.width - len - padding - 2, ' ');
	return (printed);
}

// change order to not get +       144 unstead of          +144
int	handle_flags_num(char *num, int padding, int len, t_flags flags)
{
	int		printed;
	char	pad_char;

	printed = 0;
	pad_char = ' ';
	if (flags.prec > len)
	{
		padding = flags.prec - len;
		len += padding;
	}
	else if (flags.zero && !flags.prec)
		pad_char = '0';
	if (flags.width > len + flags.neg && !flags.left)
		printed += pad(flags.width - len - flags.neg, pad_char);
	printed += print_num_string(num, len, flags);
	return (printed);
}

int	print_num_string(char *num, int len, t_flags flags)
{
	int		printed;

	printed = 0;
	if (flags.space && !flags.zero)
	{
		printed += print_char(' ');
	}
	else if (flags.plus && !flags.neg)
	{
		printed += print_char('+');
	}
	printed += print_string(num);
	if (flags.width > len + flags.neg && flags.left)
		printed += pad(flags.width - len - flags.neg, ' ');
	return (printed);
}

int	pad(int padding, char with)
{
	int	printed;

	printed = 0;
	while (padding > 0)
	{
		print_char(with);
		printed++;
		padding--;
	}
	return (printed);
}

char	*utoa(unsigned int n)
{
	char			*str;
	int				len;
	unsigned int	num;

	num = n;
	len = 0;
	if (!n || n == 0)
		return (ft_strdup("0"));
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len > 0)
	{
		str[--len] = (num % 10) + '0';
		num /= 10;
	}
	return (str);
}
