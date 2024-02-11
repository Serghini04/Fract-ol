# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meserghi <meserghi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/03 11:20:23 by meserghi          #+#    #+#              #
#    Updated: 2024/02/10 15:07:45 by meserghi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES= fractol.c utils/ft_strcmp.c utils/to_double.c julia.c

OBJ = ${FILES:.c=.o}

FLAGS = -Wall -Wextra -Werror -O3
F_MLX = -Lminilibx-linux -lmlx -framework OpenGL -framework AppKit -O3
NAME = fractol

all : ${NAME}

${NAME} : ${OBJ}
	cc ${FLAGS} ${OBJ} ${F_MLX} -o ${NAME}

%.o : %.c fractol.h
	cc ${FLAGS} -c $< -o $@

clean :
	rm -f ${OBJ}

fclean : clean
	rm -f ${NAME}

re : fclean all