/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_part.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meserghi <meserghi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 09:47:27 by meserghi          #+#    #+#             */
/*   Updated: 2024/02/12 10:44:46 by meserghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

double	to_onther_rang(double x, double n_rang0, double n_rang1, double o_rang)
{
	return ((n_rang1 - n_rang0) * x / (o_rang) + n_rang0);
}

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	int	pos;

	pos = (img->len * y) + (x * (img->bit_pixel / 8));
	*(unsigned int *)(img->p_pixel + pos) = color;
}

t_nb_cmp	squar_cmp(t_nb_cmp nb)
{
	t_nb_cmp	res;

	res.r = pow(nb.r, 2) - pow(nb.i, 2);
	res.i = 2 * nb.r * nb.i;
	return (res);
}

t_nb_cmp	small_equa(t_nb_cmp z, t_nb_cmp c)
{
	t_nb_cmp	res;

	res = squar_cmp(z);
	res.r += c.r;
	res.i += c.i;
	return (res);
}
