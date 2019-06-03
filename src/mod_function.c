#include "fdf.h"

int		values(int c)
{
	if (ft_islower(c))
		return (c - 'a' + 10);
	else if (ft_isupper(c))
		return (c - 'A' + 10);
	return (c - 48);
}

int		mod_atoi_baze(char *str, int *i, t_fdf *fdf)
{
	int res;

	res = 0;
	(*i) += 3;
	while (ft_isdigit(str[*i]) || (str[*i] >= 'A' && str[*i] <= 'F') || (str[*i] >= 'a' && str[*i] <= 'f'))
		res = res * 16 + values(str[(*i)++]);
	return (res);
}

int		mod_atoi(char *str, int *i, t_fdf *fdf)
{
	int			t;
	int			minus;
	long long	res;

	t = 0;
	res = 0;
	minus = str[*i] == '-' ? -1 : 1;
	if (minus == -1)
		(*i)++;
	while (str[*i] && ft_isdigit(str[*i]))
	{
		res = res * 10 + str[*i] - 48;
		t++;
		(*i)++;
		if (res > 2147483648)
			error_case(ERR_MAP, fdf);
	}
	if ((res > 2147483647 && minus == 1))
		error_case(ERR_MAP, fdf);
	return ((int)res * minus);
}
