/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contol.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybuhai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 22:13:02 by ybuhai            #+#    #+#             */
/*   Updated: 2019/12/27 22:37:29 by ybuhai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int mouse_move(int x, int y, void *data)
{
	t_fdf *fdf;

	fdf = (t_fdf *)data;
	fdf->mouse.last_x = fdf->mouse.x;
	fdf->mouse.last_y = fdf->mouse.y;
	fdf->mouse.x = x;
	fdf->mouse.y = y;
	if (fdf->mouse.is_pressed)
	{
		fdf->cam.b += (x - fdf->mouse.last_x) * 0.002;
		fdf->cam.a += (y - fdf->mouse.last_y) * 0.002;
		write_data_to_window(fdf);
	}
	return (1);
}

int mouse_release(int key, int x, int y, t_fdf *fdf)
{
	x = y;
	fdf->mouse.is_pressed = 0;
	return 0;
}

void change_proj(int key, t_fdf *fdf)
{
	fdf->cam.a = 0;
	fdf->cam.b = 0;
	fdf->cam.g = 0;
	if (key == K_I)
		fdf->cam.iso = 1;
	else
		fdf->cam.iso = 0;
	write_data_to_window(fdf);
	
}

int	mouse_push(int key, int x, int y, t_fdf *fdf)
{
	x = y;
	if (key == M_S_U || key == M_S_D)
		zoom(key, fdf);
	else if (key == M_L)
		fdf->mouse.is_pressed = 1;
	return (1);
}
int	button_push(int key, t_fdf *fdf)
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
	{
		system("leaks fdf");
		exit(0);
	}
	return 1;	
}

void	control(t_fdf *fdf)
{
	mlx_hook(fdf->window, 2, 0, button_push, fdf);
	mlx_hook(fdf->window, 4, 0, mouse_push, fdf);
	mlx_hook(fdf->window, 5, 0, mouse_release, fdf);
	mlx_hook(fdf->window, 6, 0, mouse_move, fdf);
}
