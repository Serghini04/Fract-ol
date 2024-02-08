/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meserghi <meserghi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 19:34:42 by meserghi          #+#    #+#             */
/*   Updated: 2024/02/08 19:55:41 by meserghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_julai(int x, int y, t_data *data)
{
	t_nb_cmp z;
	t_nb_cmp c;
	int		i;
	int		color;

	c.r = to_double(data->av[2]);
	c.i = to_double(data->av[3]);
	i = 0;
	z.r = (to_onther_rang(x, (double []){-2, 2}, (double []){0, WIDTH}) + data->s.x) * data->z;
	z.i = (to_onther_rang(y, (double []){2, -2}, (double []){0, HEIGHT}) + data->s.y) * data->z;
	while (i < data->max_itra)
	{
		z = small_equa(z, c);
		if ((pow(z.r, 2) + pow(z.i, 2)) > data->p)
		{
			color = to_onther_rang(i, (double []){BLACK, RED}, (double []){0, data->max_itra});
			my_pixel_put(&data->img, x, y, color);
			return ;
		}
		i++;
	}
	my_pixel_put(&data->img, x, y,  BLACK);
}
