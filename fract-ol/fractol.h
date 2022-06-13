/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 10:36:03 by nhanafi           #+#    #+#             */
/*   Updated: 2022/05/22 20:08:24 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_doublec {
	long double	real;
	long double	imag;
}				t_doublec;

typedef struct s_vars {
	void		*mlx;
	void		*win;
	t_data		img;
	int			weight;
	int			height;
	int			itar;
	t_doublec	begin;
	t_doublec	center;
	long double	zoom;
	char		type;
	long		color;
	int			in;
	t_doublec	racing[3];
	int			r;
	t_doublec	cst;
}				t_vars;
long double	ft_abs(long double k);
int			max(int a, int b);
t_doublec	ft_add(t_doublec a, t_doublec b);
t_doublec	ft_sub(t_doublec a, t_doublec b);
t_doublec	ft_prod(t_doublec a, t_doublec b);
t_doublec	ft_div(t_doublec a, t_doublec b);
int			ft_atoi(char *str);
int			ft_putchar(char *str);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int			absc(t_doublec c);
t_doublec	ft_coj(t_doublec a);
int			ft_comp(t_doublec a, t_doublec b, long double er);
int			len(char *str);
int			ft_close(t_vars *vars);
void		creat_mat(t_vars *vars);
int			move_mouse(int x, int y, t_vars *vars);
void		zoom(t_vars *vars, int x, int y, int cas);
void		change_color(t_vars *vars);
int			mouse_hook(int key, int x, int y, t_vars *vars);
int			key_hook(int key, t_vars *vars);
long		ft_ftype(t_vars *vars, t_doublec val);
int			ft_calcul(t_vars *vars);
int			ft_draw(t_vars *vars);
long		ft_fract1(t_doublec c, t_doublec num, int cas, t_vars *vars);
long		ft_fract2(t_doublec c, t_doublec num, int cas, t_vars *vars);
long		ft_fract3(t_doublec c, t_doublec num, t_vars *vars, int cas);
void		init_vars(t_vars *vars);
char		*fract_name(t_vars *vars);
t_doublec	multi(t_doublec a, long double b);
t_doublec	ft_square(t_doublec z);
t_doublec	ft_cube(t_doublec z);
long		ft_color(t_doublec c, t_vars *vars);
#endif