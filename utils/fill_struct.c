/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meserghi <meserghi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:14:22 by meserghi          #+#    #+#             */
/*   Updated: 2024/02/13 13:56:18 by meserghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	fill(t_data *data, char **av)
{
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
		(perror("mlx: "), free(data->mlx), free(data), exit(1));
	data->img.p_img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->img.p_img)
		(perror("mlx: "), mlx_destroy_window(data->mlx, data->mlx_win), free(data->mlx), free(data), exit(1));
	data->img.p_pixel = mlx_get_data_addr(data->img.p_img, \
						&data->img.bit_pixel, \
						&data->img.len, &data->img.endian);
	if (!data->img.p_pixel)
		(perror("mlx "), mlx_destroy_image(data->mlx, data->img.p_img), mlx_destroy_window(data->mlx, data->mlx_win), free(data->mlx), free(data), exit(1));
	fill(data, av);
	return (data);
}
