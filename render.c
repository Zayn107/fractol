/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalissa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 23:01:33 by aalissa           #+#    #+#             */
/*   Updated: 2024/03/22 18:00:08 by aalissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixel_ptr + offset) = color;
}

static void	mandel_vs_julia(t_complex *z, t_complex *c, t_fractol *fractol)
{
	if (!ft_strncmp(fractol->name, "julia", 5))
	{
		c->x = fractol->julia_x;
		c->y = fractol->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

static void	handle_pixel(int x, int y, t_fractol *fractol)
{
	int			color;
	int			i;
	t_complex	z;
	t_complex	c;

	i = 0;
	z.x = (map(x, -2.0, 2.0, WIDTH) * fractol->zoom) + fractol->shift_x;
	z.y = (map(y, 2.0, -2.0, HEIGHT) * fractol->zoom) + fractol->shift_y;
	mandel_vs_julia(&z, &c, fractol);
	while (i <= fractol->iteration_def)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractol->escaped)
		{
			color = map (i, BLACK, WHITE, fractol->iteration_def);
			my_pixel_put(x, y, &fractol->img, color);
			return ;
		}
		++i;
	}
	my_pixel_put(x, y, &fractol->img, LAVA_RED);
}

void	fractol_render(t_fractol *fractol)
{
	int	y;
	int	x;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			handle_pixel(x, y, fractol);
	}
	mlx_put_image_to_window(fractol->mlx_conn,
		fractol->mlx_win, fractol->img.img_ptr, 0, 0);
}
