/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybuhai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 20:20:56 by ybuhai            #+#    #+#             */
/*   Updated: 2019/12/28 11:46:55 by ybuhai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(int *y, int *z, double alpha)
{
	int last_y;

	last_y = *y;
	*y = last_y * cos(alpha) + *z * sin(alpha);
	*z = -last_y * sin(alpha) + *z * cos(alpha);
}

void	rotate_y(int *x, int *z, double beta)
{
	int last_x;

	last_x = *x;
	*x = last_x * cos(beta) + *z * sin(beta);
	*z = -last_x * sin(beta) + *z * cos(beta);
}

void	rotate_z(int *x, int *y, double gamma)
{
	int last_x;
	int last_y;

	last_x = *x;
	last_y = *y;
	*x = last_x * cos(gamma) - last_y * sin(gamma);
	*y = last_x * sin(gamma) + last_y * cos(gamma);
}

t_point	projection(t_fdf *fdf, t_point p)
{
	int last_x;
	int last_y;

	p.x *= fdf->cam.zoom;
	p.y *= fdf->cam.zoom;
	p.z *= fdf->cam.zoom / fdf->cam.z;
	p.x -= (fdf->width * fdf->cam.zoom) / 2;
	p.y -= (fdf->heigth * fdf->cam.zoom) / 2;
	rotate_x(&p.y, &p.z, fdf->cam.a);
	rotate_y(&p.x, &p.z, fdf->cam.b);
	rotate_z(&p.x, &p.y, fdf->cam.g);
	if (!fdf->cam.iso)
	{
		last_x = p.x;
		last_y = p.y;
		p.x = (last_x - last_y) * cos(0.523599);
		p.y = -p.z + (last_x + last_y) * sin(0.523599);
	}
	p.x += (WINDOW_SIZE_X - MENU_SIZE) / 2 + fdf->cam.x + MENU_SIZE;
	p.y += (WINDOW_SIZE_Y + fdf->heigth * fdf->cam.zoom) / 2
												+ fdf->cam.y;
	return (p);
}
