/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalissa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 22:59:02 by aalissa           #+#    #+#             */
/*   Updated: 2024/03/22 18:39:59 by aalissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia_track(int x, int y, t_fractol *fractol)
{
	if (!ft_strncmp(fractol->name, "julia", 5))
	{
		fractol->julia_x = map (x, -2, 2, WIDTH)
			* fractol->zoom + fractol->shift_x;
		fractol->julia_y = map (y, 2, -2, HEIGHT)
			* fractol->zoom + fractol->shift_y;
		fractol_render(fractol);
	}
	return (0);
}

int	close_handler(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx_conn, fractol->img.img_ptr);
	mlx_destroy_window(fractol->mlx_conn, fractol->mlx_win);
	mlx_destroy_display(fractol->mlx_conn);
	free(fractol->mlx_conn);
	exit(EXIT_SUCCESS);
}

int	mouse_handler(int button, int x,
		int y, t_fractol *fractol)
{
	if (button == Button5)
		fractol->zoom *= 1.05;
	else if (button == Button4)
		fractol->zoom *= 0.95;
	fractol_render(fractol);
	x += 1;
	y += 1;
	x -= 1;
	y -= 1;
	return (0);
}

int	key_handler(int keysym, t_fractol *fractol)
{
	if (keysym == XK_Escape)
		close_handler(fractol);
	else if (keysym == XK_Left)
		fractol->shift_x -= (0.5 * fractol->zoom);
	else if (keysym == XK_Right)
		fractol->shift_x += (0.5 * fractol->zoom);
	else if (keysym == XK_Up)
		fractol->shift_y += (0.5 * fractol->zoom);
	else if (keysym == XK_Down)
		fractol->shift_y -= (0.5 * fractol->zoom);
	else if (keysym == XK_o)
		fractol->iteration_def += 10;
	else if (keysym == XK_p)
		fractol->iteration_def -= 10;
	fractol_render(fractol);
	return (0);
}
