/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalissa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 23:01:05 by aalissa           #+#    #+#             */
/*   Updated: 2024/03/21 20:06:21 by aalissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(char *s1, char *s2, int n)
{
	if (NULL == s1 || NULL == s2 || n <= 0)
		return (0);
	while (*s1 == *s2 && n > 0 && *s1)
	{
		++s1;
		++s2;
		--n;
	}
	return (*s1 - *s2);
}

void	putstr_fd(char *s, int fd)
{
	if (NULL == s || 0 > fd)
		return ;
	if (*s)
	{
		write (fd, s, 1);
		putstr_fd(s + 1, fd);
	}
}

double	altodbl(char *s)
{
	long	integer_part;
	double	fraction_part;
	double	power;
	int		sign;

	integer_part = 0;
	fraction_part = 0.0;
	power = 1;
	sign = 1;
	while ((*s >= 9 && *s <= 13) || *s == 32)
		++s;
	while ('+' == *s || '-' == *s)
		if ('-' == *s++)
			sign = -sign;
	while (*s != '.' && *s)
		integer_part = (integer_part * 10) + (*s++ - 48);
	if (*s == '.')
		++s;
	while (*s)
	{
		power /= 10;
		fraction_part = fraction_part + (*s++ - 48) * power;
	}
	return (((integer_part + fraction_part) * sign));
}
