/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meserghi <meserghi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 11:10:17 by meserghi          #+#    #+#             */
/*   Updated: 2024/02/09 21:26:14 by meserghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL
# define FRACTOL
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "minilibx-linux/mlx.h"
# include <stdlib.h>

#define WIDTH 900
#define HEIGHT 900

#define BLACK 0x000000
#define WHITE 0xFFFFFF
#define RED 0xFF0000
#define GREEN 0x00FF00
#define BLUE 0x0000FF
#define YELLOW 0xFFFF00
#define CYAN 0x00FFFF
#define MAGENTA 0xFF00FF
#define ORANGE 0xFFA500
#define PURPLE 0x800080



typedef struct s_nb_cmp
{
	double	r;
	double	i;
}	t_nb_cmp;

typedef struct s_img
{
	void	*p_img;		//malx_new_image()
	char	*p_pixel;
	int		len;
	int		bit_pixel;
	int 	endian;
}t_img;

typedef struct s_shift
{
	double	x;
	double	y;
}	t_shift;

typedef struct	s_direction
{
	double	x_p;
	double	x_n;
	double	y_p;
	double	y_n;
}	t_direction;

typedef struct s_data
{
	void		*mlx;		// mlx_init();
	void		*mlx_win;	//mlx_new_window()
	t_img		img;		//malx_new_image()
	t_shift		s;
	t_direction	dir;
	int			p;
	double		z;
	int			v;
	char		**av;
	int			max_itra;
}	t_data;

int			ft_strcmp(char *s1,char *s2);

double		to_onther_rang(double x, double n_rang0, double n_rang1, double o_rang);
void		my_pixel_put(t_img *img, int x, int y, int color);
t_data		*start(char *name, char **av);
t_nb_cmp	squar_cmp(t_nb_cmp nb);
t_nb_cmp 	small_equa(t_nb_cmp z, t_nb_cmp c);
void		part_render(int x, int y, t_data *data);
void		my_draw(t_data *data);
double		to_double(char *str);
void		my_julai(int x, int y, t_data *data);

#endif