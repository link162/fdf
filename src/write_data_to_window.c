/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_data_to_window.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybuhai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 20:03:33 by ybuhai            #+#    #+#             */
/*   Updated: 2019/10/30 20:35:06 by ybuhai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	write_data_to_window(t_fdf *fdf)
{
	for(int x = 0; x < fdf->width; x++)
		for (int y = 0; y < (fdf->heigth - 1) * SCALE; y++)
			fdf->data[WINDOW_SIZE_X * y + x * SCALE] = 0xff;
	for (int j = 0; j < fdf->heigth; j++)
		for (int i = 0; i <= (fdf->width - 1) * SCALE; i++)
			if (i % SCALE == 0) 
				fdf->data[i + (j * WINDOW_SIZE_X * SCALE)] = 0xff0000;
			else
				fdf->data[i + (j * WINDOW_SIZE_X * SCALE)] = 0xff;
	mlx_put_image_to_window(fdf->mlx, fdf->window, fdf->img, SCALE, SCALE);
}
