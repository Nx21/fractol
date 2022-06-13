/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 16:10:20 by nhanafi           #+#    #+#             */
/*   Updated: 2022/05/18 16:00:36 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

int	ft_close(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

long	ft_ftype(t_vars *vars, t_doublec val)
{
	if (vars->type == '0')
		return (ft_fract1(val, vars->cst, 0, vars));
	if (vars->type == '1')
		return (ft_fract1(vars->cst, val, 0, vars));
	if (vars->type == '2')
		return (ft_fract1(val, vars->cst, 1, vars));
	if (vars->type == '3')
		return (ft_fract1(vars->cst, val, 1, vars));
	if (vars->type == '4')
		return (ft_fract2(val, vars->cst, 0, vars));
	if (vars->type == '5')
		return (ft_fract2(vars->cst, val, 0, vars));
	if (vars->type == '6')
		return (ft_fract2(val, vars->cst, 1, vars));
	if (vars->type == '7')
		return (ft_fract2(vars->cst, val, 1, vars));
	if (vars->type == '8')
		return (ft_fract3(vars->cst, val, vars, 0));
	if (vars->type == '9')
		return (ft_fract3(vars->cst, val, vars, 1));
	return (0);
}

int	ft_calcul(t_vars *vars)
{
	int			j;
	int			i;
	t_doublec	val;

	i = 0;
	while (i < vars->weight)
	{
		j = 0;
		while (j < vars->height)
		{
			val.real = ((long double)i - vars->center.real) / vars->zoom \
			- vars->begin.real;
			val.imag = ((long double)j - vars->center.imag) / vars->zoom \
			- vars->begin.imag;
			my_mlx_pixel_put(&(*vars).img, i, j, ft_ftype(vars, val) \
			& 0x00ffffff);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window((*vars).mlx, (*vars).win, (*vars).img.img, 0, 0);
	return (0);
}

int	ft_draw(t_vars *vars)
{
	(*vars).mlx = mlx_init();
	(*vars).win = mlx_new_window((*vars).mlx, vars->weight, vars->height \
	, fract_name(vars));
	(*vars).img.img = mlx_new_image((*vars).mlx, vars->weight, vars->height);
	(*vars).img.addr = mlx_get_data_addr((*vars).img.img, \
	&(*vars).img.bits_per_pixel, &(*vars).img.line_length, &(*vars).img.endian);
	ft_calcul(vars);
	mlx_mouse_hook(vars->win, mouse_hook, vars);
	mlx_key_hook(vars->win, key_hook, vars);
	mlx_hook(vars->win, 17, 0L, ft_close, vars);
	mlx_hook((*vars).win, 6, 0L, move_mouse, vars);
	mlx_loop(vars->mlx);
	return (0);
}
