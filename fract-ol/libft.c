/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:52:15 by nhanafi           #+#    #+#             */
/*   Updated: 2022/05/18 16:10:56 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	check_negative(char *str, int *i)
{
	int	neg;

	neg = 0;
	while (str[*i] == ' ' || str[*i] == '\r' || str[*i] == '\n' || \
			str[*i] == '\v' || str[*i] == '\f' || str[*i] == '\t')
		*i += 1;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			neg++;
		*i += 1;
	}
	return (neg);
}

int	ft_atoimax(long a, int neg)
{
	if (a > 2147483648 && neg)
		return (0);
	if (a == 2147483648 && neg)
		return (-2147483648);
	return (-1);
}

int	ft_atoi(char *str)
{
	int				i;
	unsigned int	a;
	int				neg;

	i = 0;
	neg = check_negative(str, &i);
	a = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		a *= 10;
		a += str[i] - 48;
		i++;
		if (a >= 2147483648)
			return (ft_atoimax(a, neg));
	}
	if (neg)
		return ((int) -1 * a);
	return ((int) a);
}

int	ft_putchar(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
