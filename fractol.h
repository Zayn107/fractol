/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalissa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 23:00:17 by aalissa           #+#    #+#             */
/*   Updated: 2024/03/22 18:23:07 by aalissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "minilibx-linux/mlx.h"

# define HEIGHT	800
# define WIDTH	800

# define BLACK	0x000000
# define WHITE	0xFFFFFF
# define RED	0xFF0000
# define GREEN	0x00FF00
# define BLUE	0x0000FF
# define MAGENTA_BURST	0xFF00FF
# define LIME_SHOCK	0xCCFF00
# define NEON_ORANGE	0xFF6600
# define PSYCHEDELIC_PURPLE	0x660066
# define AQUA_DREAM	0x33CCCC
# define HOT_PINK	0xFF66B2
# define ELECTRIC_BLUE	0x0066FF
# define LAVA_RED	0xFF3300

# define ERROR_MESSAGE "please enter\n\t\"mandelbrot or julia <v1> <v2>\"\n"

////// complex
typedef struct s_complex
{
	// real
	double	x;
	// image
	double	y;
}	t_complex;

//// image struct

typedef struct s_img
{
	void	*img_ptr;
	char	*pixel_ptr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;
//// fractol struct

typedef struct s_fractol
{
	void	*mlx_conn;
	void	*mlx_win;
	t_img	img;
	char	*name;
	double	escaped;
	int		iteration_def;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
}	t_fractol;

//////    string utils

int			ft_strncmp(char *s1, char *s2, int n);
void		putstr_fd(char *s, int fd);
double		altodbl(char *s);

//////     init

void		fractol_init(t_fractol *fractol);

////// render

void		fractol_render(t_fractol *fractol);
//////     math
double		map(double unscaled, double new_min,
				double new_max, double old_max);
t_complex	sum_complex(t_complex z, t_complex c);
t_complex	square_complex(t_complex z);

//////	   events

int			close_handler(t_fractol *fractol);
int			key_handler(int keysym, t_fractol *fractol);
int			mouse_handler(int button, int x,
				int y, t_fractol *fractol);
int			julia_track(int x, int y, t_fractol *fractol);

#endif
