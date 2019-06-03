/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybuhai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 12:13:12 by ybuhai            #+#    #+#             */
/*   Updated: 2019/06/03 14:11:38 by ybuhai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void	check_point(char *line, int *i, t_point *p, t_fdf *fdf, int y)
{
	int t = *i;
	p->h = mod_atoi(line, i, fdf);
	if (!ft_strncmp(&line[*i], ",0x", 3))
		p->color = mod_atoi_baze(line, i, fdf);
}

void	cut_line(char *line, int y, t_fdf *fdf)
{
	int i;
	int n;

	n = 0;
	i = 0;
	fdf->map[y] = (t_point *)malloc(sizeof(t_point) * fdf->width);
	while (line[i])
	{
		while (line[i] == ' ' || line[i] == '\t')
			i++;
		if (line[i])
			check_point(line, &i, &fdf->map[y][n], fdf, y);
		n++;
	}
}

void	full_fdf(t_fdf *fdf)
{
	int i;
	int j;

	i = 0;
	while (i < fdf->heigth)
	{
		j = 0;
		while (j < fdf->width)
		{
			ft_printf("%i", fdf->map[i][j].h);
			if (fdf->map[i][j].color)
				ft_printf("x%i", fdf->map[i][j].color);
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	read_map(int fd, t_fdf *fdf)
{
	char	*line;
	int		y;

	y = 0;
	fdf->map = (t_point **)malloc(sizeof(t_point *) * fdf->heigth);
	ft_bzero(fdf->map, sizeof(t_point *) * fdf->heigth);
	while (get_next_line(fd, &line) > 0)
	{
		cut_line(line, y++, fdf);
		free(line);
	}
	full_fdf(fdf);
	error_case(NULL, fdf);
	close(fd);
}
