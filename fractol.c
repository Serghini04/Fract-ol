/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meserghi <meserghi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 11:09:48 by meserghi          #+#    #+#             */
/*   Updated: 2024/02/06 22:33:55 by meserghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

float to_onther_rang(float x, float n_rang[2], float o_rang[2])
{
	return ((x - o_rang[0]) * (n_rang[1] - n_rang[0]) / (o_rang[1] - o_rang[0]) + n_rang[0]);
}

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	int pos;

	if (x > WIDTH || y > HEIGHT)
		exit(1);
	pos = (img->len * y) + (x * (img->bit_pixel / 8));
	*(unsigned int *)(img->p_pixel + pos) = color;
}

t_data	*start(char *name)
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
	data->map = 4;
	data->s.x = 0;
	data->s.y = 0;
	data->max_itra = 42;
	data->z = 1;
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
	c.r = (to_onther_rang(x, (float []){-2, 2}, (float []){0, WIDTH}) + data->s.x) * data->z;
	c.i = (to_onther_rang(y, (float []){2, -2}, (float []){0, HEIGHT}) + data->s.y) * data->z;
	while (i < data->max_itra)
	{
		z = small_equa(z, c);
		if ((pow(z.r, 2) + pow(z.i, 2)) > data->map)
		{
			color = to_onther_rang(i, (float []){BLACK, WHITE}, (float []){0, data->max_itra});
			my_pixel_put(&data->img, x, y, color);
			return ;
		}
		i++;
	}
	my_pixel_put(&data->img, x, y, WHITE);
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
			part_render(i, j, data);
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
		data->s.x += 0.5;
	else if (k == 123)
		data->s.x -= 0.5;
	else if (k == 125)
		data->s.y -= 0.5;
	else if (k == 126)
		data->s.y += 0.5;
	else if (k == 78)
		data->max_itra -= 10;
	else if (k == 69)
		data->max_itra += 10;
	my_draw(data);
	return (0);
}

int mouse(int k, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (k == 4)
		data->z += 0.2;
	else if (k == 5)
		data->z -= 0.2;
	my_draw(data);
	return 0;
}

int main(int ac, char **av)
{
	t_data *data;

	if (ac != 2)
		(perror("arg error "), exit(1));
	if (!ft_strcmp(av[1], "mandelbrot"))
	{
		data = start("mandelbrot");
	}
	else
		data = start("diha fkark ....");
	my_draw(data);
	mlx_key_hook(data->mlx_win, keyb, data);
	mlx_mouse_hook(data->mlx_win, mouse, data);
	mlx_loop(data->mlx);
	return (0);
}