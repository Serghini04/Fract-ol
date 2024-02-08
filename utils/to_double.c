/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_double.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meserghi <meserghi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:38:25 by meserghi          #+#    #+#             */
/*   Updated: 2024/02/08 19:57:05 by meserghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"


void	check_point(char *str)
{
	int	i;
	int	d;

	i = 0;
	d = 0;
	while (str[i])
	{
		if (str[i] == '.')
			d++;
		i++;
	}
	if (d == 2)
	{
		perror("not a valid numerical representation!!");
		exit(1);
	}
}

double _add(char *str, double res)
{
	int		i;
	double	a;

	a = 0.1;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res += (str[i] - 48) * a;
		a *= 0.1;
		i++;
	}
	return (res);
}

double	to_double(char *str)
{
	int		i;
	double	res;
	int		s;

	i = 0;
	res = 0;
	s = 1;
	check_point(str);
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			s *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	if (!str[i] || str[i] != '.')
		return (s * res);
	res = _add(&str[i + 1], res);
	return (s * res);
}
