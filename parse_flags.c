#include "ft_printf.h"

static int	parse_width(const char *f, int *i);
static int	parse_precision(const char *f, int *i);
static void	parse(const char *f, int *i, t_flags *flags);

// '0', ' ' and '-' are mutually exclusive
void	parse_flags(const char *f, int *i, t_flags *flags)
{
	flags->left = 0;
	flags->plus = 0;
	flags->zero = 0;
	flags->space = 0;
	flags->prec = -1;
	flags->neg = 0;
	flags->hash = 0;
	parse(f, i, flags);
	flags->width = parse_width(f, i);
	flags->prec = parse_precision(f, i);
}

static void	parse(const char *f, int *i, t_flags *flags)
{
	char	c;

	c = f[*i];
	while (c == '-' || c == '+' || c == '0' || c == ' ' || c == '#')
	{
		if (c == '-')
			flags->left = 1;
		if (c == '+')
			flags->plus = 1;
		if (c == '0')
			flags->zero = 1;
		if (c == ' ')
			flags->space = 1;
		if (c == '#')
			flags->hash = 1;
		(*i)++;
		c = f[*i];
	}
}

static int	parse_width(const char *f, int *i)
{
	int	tmp;

	if (ft_isdigit(f[*i]))
	{
		if (f[*i] == '0')
			(*i)++;
		tmp = ft_atoi(&f[*i]);
		while (ft_isdigit(f[*i]))
			(*i)++;
		return (tmp);
	}
	return (-1);
}

static int	parse_precision(const char *f, int *i)
{
	int	tmp;

	if (f[*i] == '.')
	{
		(*i)++;
		tmp = ft_atoi(&f[*i]);
		while (ft_isdigit(f[*i]))
			(*i)++;
		return (tmp);
	}
	return (-1);
}
