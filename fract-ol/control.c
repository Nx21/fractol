/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 16:07:27 by nhanafi           #+#    #+#             */
/*   Updated: 2022/05/22 21:14:39 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	move_mouse(int x, int y, t_vars *vars)
{
	if (vars->in < 0)
		return (9);
	vars->cst.real = (double)(x - vars->weight * .5) / vars->zoom \
	- vars->begin.real;
	vars->cst.imag = (double)(y - vars->height * .5) / vars->zoom \
	- vars->begin.imag;
	ft_calcul(vars);
	return (0);
}

void	zoom(t_vars *vars, int x, int y, int cas)
{
	if (cas)
	{
		vars->center.real = (vars->center.real - x) * 1.2 + x;
		vars->center.imag = (vars->center.imag - y) * 1.2 + y;
		vars->zoom *= 1.2;
	}
	else
	{
		vars->center.real = (vars->center.real - x) / 1.2 + x;
		vars->center.imag = (vars->center.imag - y) / 1.2 + y;
		vars->zoom /= 1.2;
	}
}

void	change_color(t_vars *vars)
{
	if (vars->color == 0x0e0e0e)
		vars->color = 0xff0801;
	else if (vars->color == 0xff0801)
		vars->color = 0x0A0103;
	else if (vars->color == 0x0A0103)
		vars->color = 0x070209;
	else if (vars->color == 0x070209)
		vars->color = 0x050201;
	else if (vars->color == 0x050201)
		vars->color = 0x151221;
	else if (vars->color == 0x151221)
		vars->color = 0x0f0103;
	else if (vars->color == 0x0f0103)
		vars->color = 0x00000e;
	else if (vars->color == 0x00000e)
		vars->color = 0xff0808;
	else
		vars->color = 0x0e0e0e;
}

int	mouse_hook(int key, int x, int y, t_vars *vars)
{
	if (key == 1 && (vars->type == '8' || vars->type % 2))
		vars->in *= -1;
	if (key == 2)
		change_color(vars);
	if (key == 4)
		zoom(vars, x, y, 0);
	if (key == 5)
		zoom(vars, x, y, 1);
	if (key == 3 && vars->itar <= 600)
		vars->itar += 100;
	ft_calcul(vars);
	return (0);
}

int	key_hook(int key, t_vars *vars)
{
	if (key == 53)
		ft_close(vars);
	if (key == 49)
		change_color(vars);
	if (key == 126)
		vars->begin.imag += 10 / vars->zoom;
	if (key == 125)
		vars->begin.imag -= 10 / vars->zoom;
	if (key == 124)
		vars->begin.real -= 10 / vars->zoom;
	if (key == 123)
		vars->begin.real += 10 / vars->zoom;
	if (key == 15)
		init_vars(vars);
	if (key == 6)
		vars->itar *= 2;
	ft_calcul(vars);
	return (0);
}
