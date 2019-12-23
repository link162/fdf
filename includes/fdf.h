/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybuhai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 19:32:24 by ybuhai            #+#    #+#             */
/*   Updated: 2019/12/23 20:54:41 by ybuhai           ###   ########.fr       */
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
#define WINDOW_SIZE_X 1920
#define WINDOW_SIZE_Y 1080
#define FIELD_COLOR 0x222222
#define MENU_COLOR 0x1E1E1E
#define BACK_1 0x09661A
#define BACK_2 0x0B7E20
#define BACK_3 0x0E9827
#define BACK_4 0x0FA72A
#define BACK_5 0x0CBF2C
#define BACK_6 0x0BCE2E
#define BACK_7 0x0BDC31
#define BACK_8 0x0BE833
#define BACK_9 0x07F533
#define MENU_SIZE 250
#define CLR_MIN (unsigned)(0L)
#define CLR_MAX (unsigned)(~CLR_MIN)
#define FT_ABS(X) (((X) < 0) ? (-(X)) : (X))
#define MINIMUM(x, y) (((x) > (y)) ? (y) : (x))
#define FT_MIN(A, B) (((A) < (B)) ? (A) : (B))

typedef struct s_point
{
	int			x;
	int			y;
	int			z;
	int			color;
}				t_point;

typedef struct s_mouse
{
	char		is_pressed;
	int			x;
	int 		y;
	int			last_x;
	int			last_y;
}				t_mouse;

typedef struct s_cam
{
	int			iso;
	int			zoom;
	double		a;
	double		b;
	double		g;
	float		z;
	int			x;
	int			y;
}				t_cam;

typedef struct s_fdf
{
	void		*mlx;
	void		*window;
	void		*img;
	char		*name;
	char		*data;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	int			width;
	int			heigth;
	t_cam		cam;
	t_mouse		mouse;
	t_point		**map;
}				t_fdf;

void			read_map(int fd, t_fdf *fdf);
void			error_case(char *str, t_fdf *fdf);
int				mod_atoi(char *line, int *i, t_fdf *fdf);
int				mod_atoi_baze(char *line, int *i, t_fdf *fdf);
void			write_data_to_window(t_fdf *fdf);
t_point			new_point(t_fdf *fdf, int x, int y);
t_point			projection(t_fdf *fdf, t_point point);
void			put_pixel(t_fdf *fdf, int x, int y, int color);
#endif
