/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 20:59:43 by nhanafi           #+#    #+#             */
/*   Updated: 2022/05/22 23:06:40 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

long double	ft_abs(long double k)
{
	if (k < 0)
		return (-k);
	return (k);
}

t_doublec	multi(t_doublec a, long double b)
{
	t_doublec	c;

	c.real = a.real * b;
	c.imag = a.imag * b;
	return (c);
}

t_doublec	ft_square(t_doublec z)
{
	t_doublec	z2;

	z2.real = z.real * z.real - z.imag * z.imag;
	z2.imag = 2 * z.imag * z.real;
	return (z2);
}

t_doublec	ft_cube(t_doublec z)
{
	t_doublec	z2;

	z2.real = z.real * z.real * z.real - z.real * z.imag * z.imag * 3;
	z2.imag = 3 * z.imag * z.real * z.real - z.imag * z.imag * z.imag;
	return (z2);
}

long	ft_color(t_doublec c, t_vars *vars)
{
	int	i;

	i = 0;
	if (c.real >= 0 && c.imag >= 0)
		return (vars->color);
	if (c.real >= 0 && c.imag < 0)
		return (vars->color * 2);
	if (c.real < 0 && c.imag >= 0)
		return (vars->color * 5);
	if (c.real < 0 && c.imag < 0)
		return (vars->color * 10);
	return (0);
}
