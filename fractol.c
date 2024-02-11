/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meserghi <meserghi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 11:09:48 by meserghi          #+#    #+#             */
/*   Updated: 2024/02/11 11:24:04 by meserghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double to_onther_rang(double x, double n_rang0, double n_rang1, double o_rang)
{
	return ((x - n_rang0) * (n_rang1 - n_rang0) / o_rang + n_rang0);
}
void	my_pixel_put(t_img *img, int x, int y, int color)
{
	int pos;

	if (x > WIDTH || y > HEIGHT)
		exit(1);
	pos = (img->len * y) + (x * (img->bit_pixel / 8));
	*(unsigned int *)(img->p_pixel + pos) = color;
}

t_data	*start(char *name, char **av)
{
	t_data *data;

	data = malloc(sizeof(t_data));
	if (!data)
		exit(1);
	data->mlx = mlx_init();
	if (!data->mlx)
		exit(1);
	data->mlx_win = mlx_new_window(data->mlx, WIDTH, HEIGHT, name);
	if (!data->mlx_win)
		exit(1);
	data->img.p_img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->img.p_img)
		exit(1);
	data->img.p_pixel = mlx_get_data_addr(data->img.p_img, &data->img.bit_pixel,\
										 &data->img.len, &data->img.endian);
	if (!data->img.p_pixel)
		exit(1);
	data->p = 4;
	data->s.x = 0;
	data->s.y = 0;
	data->max_itra = 42;
	data->z = 1;
	data->dir.x_n = -2;
	data->dir.x_p = 2;
	data->dir.y_n = -2;
	data->dir.y_p = 2;
	data->av = av;
	return (data);
}

t_nb_cmp	squar_cmp(t_nb_cmp nb)
{
	t_nb_cmp 	res;

	res.r = pow(nb.r, 2) - pow(nb.i, 2);
	res.i = 2 * nb.r * nb.i;
	return (res);
}
t_nb_cmp small_equa(t_nb_cmp z, t_nb_cmp c)
{
	t_nb_cmp res;

	res = squar_cmp(z);
	res.r += c.r;
	res.i += c.i;
	return (res);
}

void	part_render(int x, int y, t_data *data)
{
	t_nb_cmp z;
	t_nb_cmp c;
	int		i;
	int		color;

	z.r = 0;
	z.i = 0;
	i = 0;
	c.r = (to_onther_rang(x, data->dir.x_n, data->dir.x_p, WIDTH) + data->s.x);
	c.i = (to_onther_rang(y, data->dir.y_p, data->dir.y_n, HEIGHT) + data->s.y);
	while (i < data->max_itra)
	{
		z = small_equa(z, c);
		if ((pow(z.r, 2) + pow(z.i, 2)) > data->p)
		{
			color = to_onther_rang(i, BLACK, RED, data->max_itra);
			my_pixel_put(&data->img, x, y, color);
			return ;
		}
		i++;
	}
	my_pixel_put(&data->img, x, y,  DOMAIN);
}

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
				part_render(i, j, data);
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

int mouse(int k, int x, int y, t_data *data)
{
	double map_x = to_onther_rang(x, data->dir.x_n, data->dir.x_p, WIDTH);
	double map_y = to_onther_rang(y, data->dir.y_n, data->dir.y_p, HEIGHT);
	if (k == 4)
		data->z = 1.2;
	else if (k == 5)
		data->z = 0.8;
	else
		return (0);
	data->dir.x_p = map_x + (data->dir.x_p - map_x) * data->z;
	data->dir.x_n = map_x + (data->dir.x_n - map_x) * data->z;
	data->dir.y_p = map_y + (data->dir.x_p - map_y) * data->z;
	data->dir.y_n = map_y + (data->dir.x_n - map_y) * data->z;
	my_draw(data);
	return 0;
}

int main(int ac, char **av)
{
	t_data *data;

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
