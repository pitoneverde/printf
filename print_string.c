/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabruma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:14:36 by sabruma           #+#    #+#             */
/*   Updated: 2025/01/29 17:14:37 by sabruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_string_flags(char *str, t_flags flags)
{
	int	len;
	int	padding;
	int	printed;

	printed = 0;
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (flags.prec >= 0 && flags.prec < len)
		len = flags.prec;
	if (flags.prec == 0)
		str = "";
	padding = flags.width - len;
	if (padding > 0 && !flags.left)
		printed += pad(padding, ' ');
	printed += print_string_len(str, len);
	if (padding > 0 && flags.left)
		printed += pad(padding, ' ');
	return (printed);
}

int	print_string_len(char *str, int len)
{
	int	printed;
	int	i;

	i = 0;
	printed = 0;
	if (!str)
		return (0);
	while (i < len && str[i])
	{
		printed += print_char(str[i]);
		i++;
	}
	return (printed);
}

int	print_string(char *str)
{
	int	printed;
	int	i;

	i = 0;
	printed = 0;
	if (!str)
		str = "(null)";
	while (str[i])
		printed += print_char(str[i++]);
	return (printed);
}
