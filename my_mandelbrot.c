/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meserghi <meserghi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:09:22 by meserghi          #+#    #+#             */
/*   Updated: 2024/02/14 10:05:58 by meserghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_burning_ship(int x, int y, t_data *data)
{
	t_nb_cmp	z;
	t_nb_cmp	c;
	int			i;
	int			color;

	z.r = 0;
	z.i = 0;
	i = 0;
	c.r = to_another_rang(x, data->dir.x_n, data->dir.x_p, WIDTH) + data->s.x;
	c.i = to_another_rang(y, data->dir.y_p, data->dir.y_n, HEIGHT) + data->s.y;
	while (i < data->max_itra)
	{
		z = small_equa(z, c);
		z.r = fabs(z.r);
		z.i = fabs(z.i);
		if ((pow(z.r, 2) + pow(z.i, 2)) > data->axis)
		{
			color = to_another_rang(i, BLACK, PURPLE, data->max_itra);
			my_pixel_put(&data->img, x, y, color);
			return ;
		}
		i++;
	}
	my_pixel_put(&data->img, x, y, BLACK);
}

void	my_mandelbrot(int x, int y, t_data *data)
{
	t_nb_cmp	z;
	t_nb_cmp	c;
	int			i;
	int			color;

	z.r = 0;
	z.i = 0;
	i = 0;
	c.r = to_another_rang(x, data->dir.x_n, data->dir.x_p, WIDTH) + data->s.x;
	c.i = to_another_rang(y, data->dir.y_p, data->dir.y_n, HEIGHT) + data->s.y;
	while (i < data->max_itra)
	{
		z = small_equa(z, c);
		if ((pow(z.r, 2) + pow(z.i, 2)) > data->axis)
		{
			color = to_another_rang(i, BLACK, PURPLE, data->max_itra);
			my_pixel_put(&data->img, x, y, color);
			return ;
		}
		i++;
	}
	my_pixel_put(&data->img, x, y, BLACK);
}
