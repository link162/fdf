/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybuhai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 19:31:51 by ybuhai            #+#    #+#             */
/*   Updated: 2019/12/28 11:46:29 by ybuhai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		values(int c)
{
	if (ft_islower(c))
		return (c - 'a' + 10);
	else if (ft_isupper(c))
		return (c - 'A' + 10);
	return (c - 48);
}

int		mod_atoi_baze(char *str, int *i)
{
	int res;

	res = 0;
	(*i) += 3;
	while (ft_isdigit(str[*i]) || (str[*i] >= 'A' && str[*i] <= 'F') ||
			(str[*i] >= 'a' && str[*i] <= 'f'))
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

int		def_color(int z, t_fdf *fdf)
{
	double p;

	p = percent(fdf->min_h, fdf->max_h, z);
	if (p < 0.1)
		return (BACK_1);
	if (p < 0.2)
		return (BACK_2);
	if (p < 0.3)
		return (BACK_3);
	if (p < 0.4)
		return (BACK_4);
	if (p < 0.5)
		return (BACK_5);
	if (p < 0.6)
		return (BACK_6);
	if (p < 0.7)
		return (BACK_7);
	if (p < 0.8)
		return (BACK_8);
	return (BACK_9);
}

t_point	new_point(t_fdf *fdf, int x, int y)
{
	t_point new;

	new.x = x;
	new.y = y;
	new.z = fdf->map[y][x].z;
	new.color = fdf->map[y][x].color == -1 ? def_color(new.z, fdf) :
		fdf->map[y][x].color;
	return (new);
}
