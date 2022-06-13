/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opration.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 19:05:23 by nhanafi           #+#    #+#             */
/*   Updated: 2022/05/18 16:13:00 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_doublec	ft_add(t_doublec a, t_doublec b)
{
	t_doublec	c;

	c.imag = a.imag + b.imag;
	c.real = a.real + b.real;
	return (c);
}

t_doublec	ft_sub(t_doublec a, t_doublec b)
{
	t_doublec	c;

	c.imag = a.imag - b.imag;
	c.real = a.real - b.real;
	return (c);
}

t_doublec	ft_prod(t_doublec a, t_doublec b)
{
	t_doublec	c;

	c.imag = a.imag * b.real + a.real * b.imag;
	c.real = a.real * b.real - a.imag * b.imag;
	return (c);
}

t_doublec	ft_div(t_doublec a, t_doublec b)
{
	t_doublec	c;

	c.real = 0;
	c.imag = 0;
	if (!b.imag && !b.real)
		return (c);
	c.imag = (a.imag * b.real - a.real * b.imag) \
	/ (b.real * b.real + b.imag * b.imag);
	c.real = (a.real * b.real + a.imag * b.imag) \
	/ (b.real * b.real + b.imag * b.imag);
	return (c);
}

int	absc(t_doublec c)
{
	return (sqrt(c.imag * c.imag + c.real * c.real));
}
