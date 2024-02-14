/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meserghi <meserghi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:14:22 by meserghi          #+#    #+#             */
/*   Updated: 2024/02/14 10:11:47 by meserghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	my_free(t_data *data)
{
	free(data->mlx);
	free(data);
	exit(1);
}

void	fill(t_data *data, char **av)
{
	data->img.p_pixel = mlx_get_data_addr(data->img.p_img, \
						&data->img.bit_pixel, \
						&data->img.len, &data->img.endian);
	if (!data->img.p_pixel)
	{
		(perror("mlx "), mlx_destroy_image(data->mlx, data->img.p_img));
		mlx_destroy_window(data->mlx, data->mlx_win);
		my_free(data);
	}
	data->axis = 4;
	data->s.x = 0;
	data->s.y = 0;
	data->max_itra = 42;
	data->z = 1;
	data->dir.x_n = -2;
	data->dir.x_p = 2;
	data->dir.y_n = -2;
	data->dir.y_p = 2;
	data->av = av;
}

t_data	*start(char *name, char **av, int ac)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		(perror("malloc: "), exit(1));
	if (ac == 4)
	{
		data->input.r = to_double(av[2], data);
		data->input.i = to_double(av[3], data);
	}
	data->mlx = mlx_init();
	if (!data->mlx)
		(perror("mlx: "), free(data), exit(1));
	data->mlx_win = mlx_new_window(data->mlx, WIDTH, HEIGHT, name);
	if (!data->mlx_win)
		(perror("mlx: "), my_free(data));
	data->img.p_img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->img.p_img)
	{
		(perror("mlx: "), mlx_destroy_window(data->mlx, data->mlx_win));
		my_free(data);
	}
	fill(data, av);
	return (data);
}

t_data	*check_fractol(int ac, char **av)
{
	t_data	*data;

	if (ac == 2 && !ft_strcmp(av[1], "mandelbrot"))
	{
		data = start("mandelbrot", av, ac);
		data->v = 1;
	}
	else if (ac == 2 && !ft_strcmp(av[1], "burning_ship"))
	{
		data = start("burning_ship", av, ac);
		data->v = 2;
	}
	else if (ac == 4 && !ft_strcmp(av[1], "julia"))
	{
		data = start("julia", av, ac);
		data->v = 3;
	}
	else
	{
		write(1, "you need :./fractol (mandlbrot)\n", 32);
		write(1, "		 or (burning_ship)\n", 21);
		write(1, "		 or (julia nbr_r nbr_i)\n", 26);
		exit(1);
	}
	return (data);
}
