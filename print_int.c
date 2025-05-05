/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabruma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:14:53 by sabruma           #+#    #+#             */
/*   Updated: 2025/01/29 17:14:55 by sabruma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_int(int n, t_flags flags)
{
	char	*num;
	char	*original;
	int		len;
	int		printed;
	int		padding;

	num = ft_itoa(n);
	original = num;
	len = ft_strlen(num);
	printed = 0;
	padding = 0;
	if (n < 0)
		flags.neg = 1;
	printed += handle_flags_num(num, padding, len, flags);
	free(original);
	return (printed);
}
