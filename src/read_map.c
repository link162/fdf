/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybuhai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 12:13:12 by ybuhai            #+#    #+#             */
/*   Updated: 2019/04/11 17:02:20 by ybuhai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		len_width(char *line, int i)
{
	int z;
	int res;

	res = 0;
	i = 0;
	while (line[i])
	{
		z = 0;
		while (line[i] == ' ' || line[i] == '\t')
			i++;
		while (line[i] != ' ' && line[i] != '\t' && line[i])
		{
			z++;
			i++;
		}
		if (z)
			res++;
	}
	if (res < 1)
		error_case(ERR_FILE);
	return (res);
}

int		mod_atoi(char *str, int *i)
{
	(*i)++;
/*	int			res;
	int			minus;

	res = 0;
	minus = str[*i] == '-' ? -1 : 1;
	if (minus)
		(*i)++;
	while (!ft_isdigit(str[*i]))
	{
	printf("$$$%i\n", *i);
		res = res * 10 + str[*i] - 48;
		(*i)++;
		if (res > 2147483648)
			error_case(ERR_MAP);
	}*/
//	printf("$$$%i\n", res);
//	if ((res == 2147483648 && minus == 1) || (str[j] == '\0' || str[j] == ' ' ||
//				str[j] == ',' || str[j] == '\t'))
//		error_case(ERR_MAP);
//	return (res * minus);
	return (str[*i - 1] - 48);
}

void	cut_line(t_point *row, char *str)
{
	int i;
	int c;

	i = 0;
	c = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		if (!ft_isdigit(str[i]))
			row->z = mod_atoi(str, &i);
		ft_printf("%i ", row->z);
	}
}

void	read_map(t_fdf *fdf, int fd)
{
	char 		*line;
	t_point		*row;
	static int	i;

	while (get_next_line(fd, &line) > 0)
	{
		if (i == 0)
			fdf->width = len_width(line, i++);
		if (fdf->width != len_width(line, 0))
			error_case(ERR_FILE);
		row = (t_point *)malloc(sizeof(t_point));
		cut_line(row, line);
		free(line);
	}
}
