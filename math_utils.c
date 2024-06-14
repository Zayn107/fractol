/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalissa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 23:02:26 by aalissa           #+#    #+#             */
/*   Updated: 2024/03/22 18:51:43 by aalissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	map(double unscaled, double new_min, double new_max, double old_max)
{
	return ((new_max - new_min) * (unscaled / old_max) + new_min);
}

t_complex	sum_complex(t_complex z, t_complex c)
{
	t_complex	temp;

	temp.x = z.x + c.x;
	temp.y = z.y + c.y;
	return (temp);
}

t_complex	square_complex(t_complex z)
{
	t_complex	temp;

	temp.x = (z.x * z.x) - (z.y * z.y);
	temp.y = 2 * z.x * z.y;
	return (temp);
}
