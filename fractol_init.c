/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalissa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 22:59:43 by aalissa           #+#    #+#             */
/*   Updated: 2024/03/22 16:50:23 by aalissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	malloc_error(void)
{
	perror("problem with malloc");
	exit(EXIT_FAILURE);
}

static void	data_init(t_fractol	*fractol)
{
	fractol->escaped = 4;
	fractol->iteration_def = 42;
	fractol->shift_x = 0.0;
	fractol->shift_y = 0.0;
	fractol->zoom = 1.0;
}

static void	events_init(t_fractol *fractol)
{
	mlx_hook(fractol->mlx_win, KeyPress, KeyPressMask, key_handler, fractol);
	mlx_hook(fractol->mlx_win, ButtonPress,
		ButtonPressMask, mouse_handler, fractol);
	mlx_hook(fractol->mlx_win, DestroyNotify,
		StructureNotifyMask, close_handler, fractol);
	mlx_hook(fractol->mlx_win, MotionNotify,
		PointerMotionMask, julia_track, fractol);
}

void	fractol_init(t_fractol *fractol)
{
	fractol->mlx_conn = mlx_init();
	if (NULL == fractol->mlx_conn)
		malloc_error();
	fractol->mlx_win = mlx_new_window(fractol->mlx_conn,
			WIDTH, HEIGHT, fractol->name);
	if (NULL == fractol->mlx_conn)
	{
		mlx_destroy_display(fractol->mlx_conn);
		free(fractol->mlx_conn);
		malloc_error();
	}
	fractol->img.img_ptr = mlx_new_image(fractol->mlx_conn, WIDTH, HEIGHT);
	if (NULL == fractol->img.img_ptr)
	{
		mlx_destroy_window(fractol->mlx_conn, fractol->mlx_win);
		mlx_destroy_display(fractol->mlx_conn);
		free(fractol->mlx_conn);
		malloc_error();
	}
	fractol->img.pixel_ptr = mlx_get_data_addr(fractol->img.img_ptr,
			&fractol->img.bpp, &fractol->img.line_len, &fractol->img.endian);
	events_init(fractol);
	data_init(fractol);
}
