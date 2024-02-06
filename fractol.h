/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meserghi <meserghi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 11:10:17 by meserghi          #+#    #+#             */
/*   Updated: 2024/02/06 22:16:50 by meserghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL
# define FRACTOL
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
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
	float	r;
	float	i;
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
	float	x;
	float	y;
}	t_shift;

typedef struct s_data
{
	void	*mlx;		// mlx_init();
	void	*mlx_win;	//mlx_new_window()
	t_img	img;		//malx_new_image()
	int		map;
	t_shift	s;
	float	z;
	int max_itra;
}	t_data;

int	ft_strcmp(char *s1,char *s2);


#endif