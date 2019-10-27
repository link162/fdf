/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybuhai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 12:13:12 by ybuhai            #+#    #+#             */
/*   Updated: 2019/10/27 22:19:23 by ybuhai           ###   ########.fr       */
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
	void *ptr = mlx_init();
	if (!ptr)
		error_case("global_error\n", fdf);
	mlx_new_window(ptr, WINDOW_SIZE_X, WINDOW_SIZE_Y, "Link");
	mlx_new_image(ptr, WINDOW_SIZE_X, WINDOW_SIZE_Y);
	mlx_loop(ptr);
	while(1);
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
