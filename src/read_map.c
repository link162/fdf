/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybuhai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 12:13:12 by ybuhai            #+#    #+#             */
/*   Updated: 2019/12/26 20:59:36 by ybuhai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	check_point(char *line, int *i, t_point *p, t_fdf *fdf, int y)
{
	int t = *i;
	p->z = mod_atoi(line, i, fdf);
	if (!ft_strncmp(&line[*i], ",0x", 3))
		p->color = mod_atoi_baze(line, i, fdf);
	else
		p->color = -1;
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
		{
			check_point(line, &i, &fdf->map[y][n], fdf, y);
			if (fdf->map[y][n].z > fdf->max_h)
				fdf->max_h = fdf->map[y][n].z;
			if (fdf->map[y][n].z < fdf->min_h)
				fdf->min_h = fdf->map[y][n].z == -1 ? 0 : fdf->map[y][n].z;
		}
		n++;
	}
}

void	full_fdf(t_fdf *fdf)
{
	int x;
	int y;
	int z;

	fdf->mlx = mlx_init();
	if (!fdf->mlx)
		error_case("global_error\n", fdf);
	fdf->window = mlx_new_window(fdf->mlx, WINDOW_SIZE_X, WINDOW_SIZE_Y, fdf->name);
	if (!fdf->window)
		error_case("global_error\n", fdf);
	fdf->img = mlx_new_image(fdf->mlx, WINDOW_SIZE_X, WINDOW_SIZE_Y);
	if (!fdf->img)
		error_case("global_error\n", fdf);
	fdf->data = mlx_get_data_addr(fdf->img, &fdf->bits_per_pixel, &fdf->size_line, &fdf->endian);
	fdf->cam.zoom = (int)MINIMUM(((WINDOW_SIZE_X - MENU_SIZE) / fdf->width / 2), (WINDOW_SIZE_Y / fdf->heigth / 2));
	fdf->cam.z = 1;
	fdf->cam.iso = 0;
	write_data_to_window(fdf);
	mlx_loop(fdf->mlx);
}

void	read_map(int fd, t_fdf *fdf)
{
	char	*line;
	int		y;

	y = 0;
	fdf->min_h = CLR_MAX;
	fdf->max_h = CLR_MIN;
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
