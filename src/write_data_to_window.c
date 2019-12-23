/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_data_to_window.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybuhai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 20:03:33 by ybuhai            #+#    #+#             */
/*   Updated: 2019/12/23 21:50:00 by ybuhai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_color(t_point current, t_point start, t_point end, t_point delta)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	ft_printf("curr-%i\nstart-%i\nend-%i\n", current.color, start.color, end.color);
	if (current.color == end.color)
		return (current.color);
	if (delta.x > delta.y)
		percentage = current.x / CLR_MAX;
	else
		percentage = current.y / CLR_MAX;
	red = (1 - percentage) * ((start.color >> 16) & 0xFF) + percentage *
		((end.color >> 16) & 0xFF);
	green = (1 - percentage) * ((start.color >> 8) & 0xFF) + percentage *
		((end.color >> 8) & 0xFF);
	blue = (1 - percentage) * (start.color & 0xFF) + percentage * (end.color & 0xFF);
	return ((red << 16) | (green << 8) | blue);
}

void	draw_line(t_fdf *fdf, t_point *f)
{
	t_point curr;
	int err[2];

	curr = f[0];
	err[0] = f[2].x - f[2].y;
	while (curr.x != f[1].x || curr.y != f[1].y)
	{
		put_pixel(fdf, curr.x, curr.y, get_color(curr, f[0], f[1], f[2]));
		if ((err[1] = err[0] * 2) > -f[2].y)
		{
			err[0] -= f[2].y;
			curr.x += f[3].x;
			ft_printf("here\n");
		}
		if (err[1] < f[2].x)
		{
			err[0] += f[2].x;
			curr.y += f[3].y;
			ft_printf("bye\n");
		}
	}
}

void	prepate_two_points(t_fdf *fdf, int x, int y, int x_or_y)
{
	t_point f[4];
  	
	f[0] = projection(fdf, new_point(fdf, x, y));
	if (x_or_y)
		f[1] = projection(fdf, new_point(fdf, x, y + 1));
	else
		f[1] = projection(fdf, new_point(fdf, x + 1, y));
	f[2].x = FT_ABS(f[1].x - f[0].x);
	f[2].y = FT_ABS(f[1].y - f[0].y);
	f[3].x = f[0].x < f[1].x ? 1 : -1;
	f[3].y = f[0].y < f[1].y ? 1 : -1;
	draw_line(fdf, (t_point *)f);
}

void	draw_background(t_fdf *fdf)
{
	int i;
	int *disp;

	i = 0;
	ft_bzero(fdf->data, WINDOW_SIZE_X * WINDOW_SIZE_Y * (fdf->bits_per_pixel / 8));
	disp = (int *)(fdf->data);
	while (i < WINDOW_SIZE_X * WINDOW_SIZE_Y)
	{
		disp[i] = i % WINDOW_SIZE_X < MENU_SIZE ? MENU_COLOR : FIELD_COLOR;
		i++;
	}
}

void	write_data_to_window(t_fdf *fdf)
{
	int x;
	int y;

	draw_background(fdf);
	y = 0;
	while (y < fdf->heigth)
	{
		x = 0;
		while (x < fdf->width)
		{
			if (x != fdf->width - 1)
				prepate_two_points(fdf, x, y, 0);
			if (y != fdf->heigth - 1)
				prepate_two_points(fdf, x, y, 1);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->window, fdf->img, 0, 0);
}
