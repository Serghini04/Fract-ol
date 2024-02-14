# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meserghi <meserghi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/03 11:20:23 by meserghi          #+#    #+#              #
#    Updated: 2024/02/14 10:23:42 by meserghi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES= fractol.c  my_mandelbrot.c my_julia.c utils/fill_struct.c utils/ft_strcmp.c utils/math_part.c utils/to_double.c

OBJ = ${FILES:.c=.o}

FLAGS = -Wall -Wextra -Werror

F_MLX = -lmlx -framework OpenGL -framework AppKit -O3

NAME = fractol

all : ${NAME}

${NAME} : ${OBJ}
	cc ${FLAGS} ${OBJ} ${F_MLX} -o ${NAME}

%.o : %.c fractol.h
	cc ${FLAGS} -O3 -c $< -o $@

clean :
	rm -f ${OBJ}

fclean : clean
	rm -f ${NAME}

re : fclean all