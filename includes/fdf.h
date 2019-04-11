/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybuhai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 16:45:34 by ybuhai            #+#    #+#             */
/*   Updated: 2019/04/11 16:24:24 by ybuhai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libftprintf/libftprintf.h"
# include <mlx.h>
# include <math.h>

#define ERR_FILE "Error file"
#define ERR_MAP "Error map"

typedef struct s_point
{
	int			x;
	int			y;
	int			z;
	int			color;
}				t_point;

typedef struct s_row
{
	t_point		*list;
	
}				t_row;

typedef struct s_fdf
{
	t_point		**map;
	int			width;
	int			heigth;
}				t_fdf;

void			read_map(t_fdf *fdf, int fd);
void			error_case(char *str);

#endif
