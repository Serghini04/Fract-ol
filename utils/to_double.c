/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_double.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meserghi <meserghi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:38:25 by meserghi          #+#    #+#             */
/*   Updated: 2024/02/13 13:55:39 by meserghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	error_input(t_data *data)
{
	perror("not a valid numerical representation!!");
	free(data);
	exit(1);
}

void	check_point(char *str, t_data *data)
{
	int	i;
	int	d;

	i = 0;
	d = 0;
	if (str[i] == '.')
		error_input(data);
	while (str[i])
	{
		if (str[i] == '.')
			d++;
		i++;
	}
	if (d >= 2)
		error_input(data);
}

double	_add(char *str, double res, t_data *data)
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
	if (str[i] != '\0')
		error_input(data);
	return (res);
}

double	to_double(char *str, t_data *data)
{
	int		i;
	double	res;
	int		s;

	i = 0;
	res = 0;
	s = 1;
	check_point(str, data);
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
	if (str[i] == '\0')
		return (s * res);
	else if (str[i] != '.')
		error_input(data);
	res = _add(&str[i + 1], res, data);
	return (s * res);
}
