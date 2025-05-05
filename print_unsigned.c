/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabruma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:15:17 by sabruma           #+#    #+#             */
/*   Updated: 2025/01/29 17:15:18 by sabruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_unsigned(unsigned int n, t_flags flags)
{
	char	*num;
	int		len;
	int		printed;
	int		padding;

	printed = 0;
	padding = 0;
	if (n <= INT_MAX)
		num = ft_itoa(n);
	else
		num = utoa(n);
	len = ft_strlen(num);
	printed += handle_flags_num(num, padding, len, flags);
	free(num);
	return (printed);
}
