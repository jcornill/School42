#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcornill <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/27 12:48:49 by jcornill          #+#    #+#              #
#    Updated: 2015/12/03 18:26:35 by jcornill         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME=fillit
SRC=check_file.c check_tetris.c fill_grid.c fillit.c grid.c process_file.c \
shift_tetris.c
OBJ=$(SRC:.c=.o)
FLAG=-Wall -Wextra -Werror
LIBFT=-L . -lft

$(NAME): $(OBJ)
	gcc $(FLAG) $(OBJ) -o $(NAME) $(LIBFT)

all:$(NAME)

clean:
	rm -f $(OBJ)

fclean:clean
	rm -f $(NAME)

re:fclean all

%.o:%.c
	gcc -c $(FLAG) $(SRC)

.PHONY: $(NAME) all clean fclean re