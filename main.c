/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalissa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 23:00:31 by aalissa           #+#    #+#             */
/*   Updated: 2024/03/22 16:44:04 by aalissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	if (((2 == argc) && (!(ft_strncmp(argv[1], "mandelbrot", 10))))
		|| (4 == argc && !ft_strncmp(argv[1], "julia", 5)))
	{
		fractol.name = argv[1];
		if (!ft_strncmp(argv[1], "julia", 5))
		{
			fractol.julia_x = altodbl(argv[2]);
			fractol.julia_y = altodbl(argv[3]);
		}
		fractol_init(&fractol);
		fractol_render(&fractol);
		mlx_loop(fractol.mlx_conn);
	}
	else
	{
		putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}
