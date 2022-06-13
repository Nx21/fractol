/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 16:13:40 by nhanafi           #+#    #+#             */
/*   Updated: 2022/05/22 20:08:51 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

long	ft_fract1(t_doublec c, t_doublec num, int cas, t_vars *vars)
{
	t_doublec	z;
	t_doublec	z2;
	int			i;

	z = num;
	i = 0;
	while (i < vars->itar)
	{
		if (cas)
			z.imag *= -1;
		z2.real = z.real * z.real - z.imag * z.imag + c.real;
		z2.imag = 2 * z.imag * z.real + c.imag;
		z = z2;
		if (z.imag * z.imag + z.real * z.real >= 4)
			return ((i + 1) * vars->color);
		i++;
	}
	return (0);
}

long	ft_fract2(t_doublec c, t_doublec num, int cas, t_vars *vars)
{
	t_doublec	z;
	t_doublec	z2;
	int			i;

	z = num;
	i = 0;
	while (i < vars->itar)
	{
		if (cas)
		{
			z2.real = z.real * z.real - z.imag * z.imag + c.real;
			z2.imag = ft_abs(2 * z.real * z.imag) + c.imag;
		}
		else
			z2 = ft_add(ft_cube(z), c);
		z = z2;
		i++;
		if (z.real * z.real + z.imag * z.imag > 4)
			return ((i + 1) * vars->color);
	}
	return (0);
}

long	ft_fract3(t_doublec c, t_doublec num, t_vars *vars, int cas)
{
	t_doublec	z;
	t_doublec	fonc;
	t_doublec	div;
	int			i;

	z = num;
	i = 0;
	while (i < vars->itar)
	{
		fonc = ft_add(ft_cube(z), c);
		div = multi(ft_square(z), 3);
		i++;
		if (fonc.real * fonc.real + fonc.imag * fonc.imag < .0000001)
		{
			if (cas)
				return (vars->color * ft_color(z, vars));
			return (vars->color * i);
		}
		if (z.real == 0 && z.imag == 0)
			return (0);
		z = ft_sub(z, ft_div(fonc, div));
	}
	return (0);
}

char	*fract_name(t_vars *vars)
{
	if (vars->type == '0')
		return ("Mandelbrot set  : z^2 + c");
	if (vars->type == '1')
		return ("Julia set  : z^2 + c");
	if (vars->type == '2')
		return ("Mandelbrot set  : conj(z)^2 + c");
	if (vars->type == '3')
		return ("Julia set  : conj(z)^2 + c");
	if (vars->type == '4')
		return ("Mandelbrot set  : z^3 + c");
	if (vars->type == '5')
		return ("Julia set  : z^3 + c");
	if (vars->type == '6')
		return ("Mandelbrot set  : |z|^2 + c (burning ship)");
	if (vars->type == '7')
		return ("Julia set  : |z|^2 + c");
	if (vars->type == '8')
		return ("Newton fractal  : z^3 + c");
	if (vars->type == '9')
		return ("Newton fractal  : z^3 + c");
	return (0);
}
