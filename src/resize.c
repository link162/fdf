/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybuhai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 21:24:44 by ybuhai            #+#    #+#             */
/*   Updated: 2019/12/27 21:30:19 by ybuhai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void zoom(int key, t_fdf *fdf)
{
	if (key == M_S_U)
		fdf->cam.zoom++;
	else if (key == M_S_D)
		fdf->cam.zoom--;
	if (fdf->cam.zoom < 1)
		fdf->cam.zoom = 1;
	write_data_to_window(fdf);
}
