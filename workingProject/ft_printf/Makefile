#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcornill <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/27 12:48:49 by jcornill          #+#    #+#              #
#    Updated: 2015/12/10 23:18:47 by jcornill         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME=libftprintf.a
SRC=ft_printf.c
OBJ=$(SRC:.c=.o)
FLAG=-Wall -Wextra -Werror
INCLUDE=-I includes

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) libft.a -shared

m: re
	@gcc -c $(FLAG) $(INCLUDE) main.c
	@gcc $(FLAG) main.o $(NAME) -o test
	@rm main.o
	@echo "==========OUTPUT=========="
	@./test

all:$(NAME)

clean:
	rm -f $(OBJ)

fclean:clean
	rm -f $(NAME)

re:fclean all

%.o:%.c
	gcc -c $(FLAG) $(INCLUDE) $(SRC)

.PHONY: $(NAME) all clean fclean re
