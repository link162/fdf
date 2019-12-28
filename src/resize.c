/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybuhai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 21:24:44 by ybuhai            #+#    #+#             */
/*   Updated: 2019/12/28 12:00:43 by ybuhai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom(int key, t_fdf *fdf)
{
	if (key == M_S_U)
		fdf->cam.zoom++;
	else if (key == M_S_D)
		fdf->cam.zoom--;
	if (fdf->cam.zoom < 1)
		fdf->cam.zoom = 1;
	write_data_to_window(fdf);
}

double	percent(int s, int e, int c)
{
	double	p;
	double	d;

	p = c - s;
	d = e - s;
	return ((d == 0) ? 1.0 : (p / d));
}

int		button_push(int key, t_fdf *fdf)
{
	if (key == K_L || key == K_R || key == K_U || key == K_D)
	{
		if (key == K_L)
			fdf->cam.x -= 10;
		else if (key == K_R)
			fdf->cam.x += 10;
		else if (key == K_U)
			fdf->cam.y -= 10;
		else
			fdf->cam.y += 10;
		write_data_to_window(fdf);
	}
	else if (key == K_I || key == K_P)
		change_proj(key, fdf);
	else if (key == K_E)
		exit(0);
	return (1);
}

void	print_menu(t_fdf *fdf)
{
	int		y;
	void	*mlx;
	void	*win;

	y = 0;
	mlx = fdf->mlx;
	win = fdf->window;
	mlx_string_put(mlx, win, 65, y += 20, TEXT_COLOR, "How to Use");
	mlx_string_put(mlx, win, 15, y += 35, TEXT_COLOR, "Zoom: Scroll");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Move: Arrows");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Rotate: Press & Move");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Projection");
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, "ISO: I Key");
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, "Parallel: P Key");
}
