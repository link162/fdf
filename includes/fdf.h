/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybuhai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 19:32:24 by ybuhai            #+#    #+#             */
/*   Updated: 2019/12/28 11:59:34 by ybuhai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libftprintf/libftprintf.h"
# include <mlx.h>
# include <math.h>

# define ERR_FILE "Error file"
# define ERR_MAP "Error map"
# define WINDOW_SIZE_X 1920
# define WINDOW_SIZE_Y 1080
# define FIELD_COLOR 0x222222
# define MENU_COLOR 0x1E1E1E
# define TEXT_COLOR 0xFF0000
# define BACK_1 0xFF7300
# define BACK_2 0x0016FF
# define BACK_3 0x00ff8b
# define BACK_4 0xFF0000
# define BACK_5 0xe400ff
# define BACK_6 0x0016ff
# define BACK_7 0x00fff7
# define BACK_8 0x49FF00
# define BACK_9 0xFBFF00
# define MENU_SIZE 250
# define M_L	1
# define M_S_U	4
# define M_S_D	5
# define K_U			126
# define K_D			125
# define K_L			123
# define K_R			124
# define K_E			53
# define K_I			34
# define K_P			35
# define CLR_MIN (unsigned)(0L)
# define CLR_MAX (int)(~CLR_MIN >> 1)
# define FT_ABS(X) (((X) < 0) ? (-(X)) : (X))
# define MINIMUM(x, y) (((x) > (y)) ? (y) : (x))
# define FT_MIN(A, B) (((A) < (B)) ? (A) : (B))

typedef struct	s_point
{
	int			x;
	int			y;
	int			z;
	int			color;
}				t_point;

typedef struct	s_mouse
{
	char		is_pressed;
	int			x;
	int			y;
	int			last_x;
	int			last_y;
}				t_mouse;

typedef struct	s_cam
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

typedef struct	s_fdf
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
	int			min_h;
	int			max_h;
	t_cam		cam;
	t_mouse		mouse;
	t_point		**map;
}				t_fdf;

void			read_map(int fd, t_fdf *fdf);
void			error_case(char *str, t_fdf *fdf);
int				mod_atoi(char *line, int *i, t_fdf *fdf);
int				mod_atoi_baze(char *line, int *i);
void			write_data_to_window(t_fdf *fdf);
t_point			new_point(t_fdf *fdf, int x, int y);
t_point			projection(t_fdf *fdf, t_point point);
void			put_pixel(t_fdf *fdf, int x, int y, int color);
double			percent(int s, int e, int c);
void			control(t_fdf *fdf);
void			zoom(int key, t_fdf *fdf);
int				button_push(int key, t_fdf *fdf);
void			change_proj(int key, t_fdf *fdf);
void			print_menu(t_fdf *fdf);
#endif
