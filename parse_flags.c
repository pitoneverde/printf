#include "ft_printf.h"

static int parse_width(const char **fmt);
static int parse_precision(const char **fmt);

void parse_flags(const char **fmt, t_flags *flags)
{
	flags->left = 0;
	flags->plus = 0;
	flags->zero = 0;
	flags->space = 0;
	flags->prec = -1;
	flags->neg = 0;

	while (**fmt == '-' || **fmt == '+' || **fmt == '0' || **fmt == ' ')
	{
		if (**fmt == '-')
			flags->left = 1;
		if (**fmt == '+')
			flags->plus = 1;
		if (**fmt == '0')
			flags->zero = 1;
		if (**fmt == ' ')
			flags->space = 1;
		if (**fmt == '#')
			flags->hash = 1;			
		(*fmt)++;
	}
	flags->width = parse_width(fmt);
	flags->prec = parse_precision(fmt);
}

static int parse_width(const char **fmt)
{
	int tmp;

	if (ft_isdigit(**fmt))
	{
		tmp = ft_atoi(*fmt);
		while (ft_isdigit(**fmt))
			(*fmt)++;
		return (tmp);
	}
	return (0);
}

static int parse_precision(const char **fmt)
{
	int tmp;

	if (**fmt == '.')
	{
		(*fmt)++;
		tmp = ft_atoi(*fmt);
		while (ft_isdigit(**fmt))
			(*fmt)++;
		return (tmp);
	}
	return (0);
}