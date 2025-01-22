#include "ft_printf.h"

static int parse_width(const char *fmt, int *i);
static int parse_precision(const char *fmt, int *i);

void parse_flags(const char *fmt, int *i, t_flags *flags)
{
	flags->left = 0;
	flags->plus = 0;
	flags->zero = 0;
	flags->space = 0;
	flags->prec = -1;
	flags->neg = 0;
	flags->hash = 0;

	while (fmt[*i] == '-' || fmt[*i] == '+' || fmt[*i] == '0' || fmt[*i] == ' ' || fmt[*i] == '#')
	{
		if (fmt[*i] == '-')
			flags->left = 1;
		if (fmt[*i] == '+')
			flags->plus = 1;
		if (fmt[*i] == '0')
			flags->zero = 1;
		if (fmt[*i] == ' ')
			flags->space = 1;
		if (fmt[*i] == '#')
			flags->hash = 1;			
		(*i)++;
	}
	flags->width = parse_width(fmt, i);
	flags->prec = parse_precision(fmt, i);
}

static int parse_width(const char *fmt, int *i)
{
	int tmp;

	if (ft_isdigit(fmt[*i]))
	{
		tmp = ft_atoi(&fmt[*i]);
		while (ft_isdigit(fmt[*i]))
			(*i)++;
		return (tmp);
	}
	return (0);
}

static int parse_precision(const char *fmt, int *i)
{
	int tmp;

	if (fmt[*i] == '.')
	{
		(*i)++;
		tmp = ft_atoi(&fmt[*i]);
		while (ft_isdigit(fmt[*i]))
			(*i)++;
		return (tmp);
	}
	return (0);
}