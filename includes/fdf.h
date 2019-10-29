/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybuhai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 16:45:34 by ybuhai            #+#    #+#             */
/*   Updated: 2019/10/29 21:16:26 by ybuhai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libftprintf/libftprintf.h"
# include <mlx.h>
# include <math.h>
#include <stdio.h>

#define ERR_FILE "Error file"
#define ERR_MAP "Error map"
#define WINDOW_SIZE_X 2000
#define WINDOW_SIZE_Y 1000
#define SCALE 50

typedef struct s_point
{
	int			x;
	int			y;
	int			z;
	int			h;
	int			color;
}				t_point;

typedef struct s_fdf
{
	void		*mlx;
	void		*window;
	void		*img;
	char		*name;
	int			*data;
	t_point		**map;
	int			width;
	int			heigth;
}				t_fdf;

void			read_map(int fd, t_fdf *fdf);
void			error_case(char *str, t_fdf *fdf);
int				mod_atoi(char *line, int *i, t_fdf *fdf);
int				mod_atoi_baze(char *line, int *i, t_fdf *fdf);
void			write_data_to_window(t_fdf *fdf);
#endif
