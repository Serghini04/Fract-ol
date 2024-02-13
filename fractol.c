/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meserghi <meserghi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 11:09:48 by meserghi          #+#    #+#             */
/*   Updated: 2024/02/12 10:50:07 by meserghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_draw(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			if (data->v == 1)
				my_mandelbrot(i, j, data);
			else
				my_julai(i, j, data);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.p_img, 0, 0);
}

int	keyb(int k, t_data *data)
{
	if (k == 53)
		exit(1);
	else if (k == 124)
		data->s.x += 0.05;
	else if (k == 123)
		data->s.x -= 0.05;
	else if (k == 125)
		data->s.y -= 0.05;
	else if (k == 126)
		data->s.y += 0.05;
	else if (k == 78)
		data->max_itra -= 10;
	else if (k == 69)
		data->max_itra += 10;
	my_draw(data);
	return (0);
}

int	mouse(int k, int x, int y, t_data *data)
{
	double	map_x;
	double	map_y;

	map_x = to_onther_rang(x, data->dir.x_n, data->dir.x_p, WIDTH);
	map_y = to_onther_rang(y, data->dir.y_p, data->dir.y_n, HEIGHT);
	if (k == 4)
		data->z = 0.9;
	else if (k == 5)
		data->z = 1.1;
	else
		return (0);
	data->dir.x_p = map_x + (data->dir.x_p - map_x) * data->z;
	data->dir.x_n = map_x + (data->dir.x_n - map_x) * data->z;
	data->dir.y_p = map_y + (data->dir.y_p - map_y) * data->z;
	data->dir.y_n = map_y + (data->dir.y_n - map_y) * data->z;
	my_draw(data);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac == 2 && !ft_strcmp(av[1], "mandelbrot"))
	{
		data = start("mandelbrot", av);
		data->v = 1;
	}
	else if (ac == 4 && !ft_strcmp(av[1], "julia"))
	{
		data = start("julia", av);
		data->v = 2;
	}
	else
		exit(1);
	my_draw(data);
	mlx_key_hook(data->mlx_win, keyb, data);
	mlx_mouse_hook(data->mlx_win, mouse, data);
	mlx_loop(data->mlx);
	return (0);
}
