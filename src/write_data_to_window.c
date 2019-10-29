/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_data_to_window.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybuhai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 20:03:33 by ybuhai            #+#    #+#             */
/*   Updated: 2019/10/29 21:12:39 by ybuhai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	write_data_to_window(t_fdf *fdf)
{
	for (int j = 0; j < fdf->heigth; j++)
		for (int i = 0; i < fdf->width * SCALE; i++)
		{
			fdf->data[i + (j * WINDOW_SIZE_X * SCALE)] = 0x000ff;
			if (i % SCALE == 0) 
			fdf->data[i + (j * WINDOW_SIZE_X * SCALE)] = 0xff0000;
		}/*	
	for (int j = 0; j < fdf->heigth * SCALE; j++)
		for (int i = 0; i < fdf->width; i++)
		{
			fdf->data[j + (i * WINDOW_SIZE_X
		}*/
	mlx_put_image_to_window(fdf->mlx, fdf->window, fdf->img, SCALE, SCALE);
}
