# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcornill <jcornill@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/21 13:08:23 by jcornill          #+#    #+#              #
#    Updated: 2016/03/21 14:28:22 by jcornill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fdf
SRC=fdf.c utils.c graphics.c
OBJ=$(SRC:.c=.o)
FLAG=-Wall -Wextra -Werror
INCLUDE=-I includes
MINILIBX=-lmlx -framework OpenGL -framework AppKit

$(NAME): $(OBJ)
	Make -C libft/
	gcc $(FLAG) -o $(NAME) $(OBJ) libft/libft.a $(MINILIBX)

exec: $(NAME)
	./fdf

all:$(NAME)

clean:
	make -C libft/ clean
	rm -f $(OBJ)

fclean:clean
	make -C libft/ fclean
	rm -f $(NAME)

re:fclean all

%.o:%.c
	gcc -c $< $(FLAG) $(INCLUDE) -o $@

.PHONY: all clean fclean re save
