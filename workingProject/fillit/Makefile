#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcornill <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/27 12:48:49 by jcornill          #+#    #+#              #
#    Updated: 2015/11/30 22:01:41 by jcornill         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME=fillit
SRC=*.c
OBJ=$(SRC:.c=.o)
FLAG=-Wall -Wextra -Werror
LIBFT=-L libft/ -lft
INCLUDE=-I libft/includes/

$(NAME): $(OBJ)
	gcc $(FLAG) $(OBJ) -o $(NAME) $(LIBFT)

all:$(NAME)

clean:
	rm -f $(OBJ)

fclean:clean
	rm -f $(NAME)

re:fclean all

%.o:%.c
	gcc -c $(FLAG) $(INCLUDE) $(SRC)

.PHONY: $(NAME) all clean fclean re