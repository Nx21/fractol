/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 00:28:03 by nhanafi           #+#    #+#             */
/*   Updated: 2022/05/22 04:14:17 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_error(void)
{
	ft_putchar("################## Fractols ###################\n");
	ft_putchar("# ./fractol ($TYPE)  ($HEIGHT)  ($WEIGHT)     #\n");
	ft_putchar("# 0 ≤ ($TYPE) ≤ 9                             #\n");
	ft_putchar("# ($HEIGHT) (max:500) (min:40)  (optional)    #\n");
	ft_putchar("# ($WEIGHT) (max:500) (min:40) (optional)     #\n");
	ft_putchar("###############################################\n");
	exit(0);
}

void	ft_instract(void)
{
	ft_putchar("################## Fractols ###################\n");
	ft_putchar("# arrows        - Up Down Right Left          #\n");
	ft_putchar("# mouse wheel   - Zoom                        #\n");
	ft_putchar("# r             - Reset                       #\n");
	ft_putchar("# Space         - Change color                #\n");
	ft_putchar("###############################################\n");
}

void	init_vars(t_vars *vars)
{
	vars->begin.real = 0;
	vars->begin.imag = 0;
	vars->cst.real = 0;
	vars->cst.imag = 0;
	vars->in = -1;
	vars->itar = 100;
	vars->zoom = 100;
	vars->color = 0xff0801;
	vars->center.real = vars->weight / 2;
	vars->center.imag = vars->height / 2 ;
	vars->r = 0;
}

void	ft_readparam(t_vars *vars, int argc, char **argv)
{
	if (len(argv[1]) != 1 || (argv[1][0] < '0' || argv[1][0] > '9'))
		ft_error();
	vars->type = argv[1][0];
	vars->height = 400;
	vars->weight = 400;
	if (argc == 4)
	{
		vars->height = ft_atoi(argv[3]);
		vars->weight = ft_atoi(argv[2]);
		if (vars->weight < 40 || vars->height < 40 || vars->weight > 500 \
		|| vars->height > 500)
			ft_error();
	}
	init_vars(vars);
}

int	main(int argc, char *argv[])
{
	t_vars	vars;

	if (argc != 2 && argc != 4)
		ft_error();
	ft_readparam(&vars, argc, argv);
	ft_instract();
	ft_draw(&vars);
}
