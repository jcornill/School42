#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcornill <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/27 12:48:49 by jcornill          #+#    #+#              #
#    Updated: 2016/02/21 16:21:00 by jcornill         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME=push_swap
SRC=push_swap.c init.c action1.c action2.c process.c
OBJ=$(SRC:.c=.o)
FLAG=-Wall -Wextra -Werror -g
INCLUDE=-I includes

$(NAME): $(OBJ)
	Make -C libft/
	gcc $(FLAG) -o $(NAME) $(OBJ) libft/libft.a

cleanwitlib:
	rm -f $(OBJ)
	rm -f $(NAME)

rewitlib: cleanwitlib $(OBJ)
	gcc $(FLAG) -o $(NAME) $(OBJ) libft/libft.a

m: rewitlib eclean norme
	@echo "==========PROG=========="
	@./$(NAME) 8 5 6 3 1 2

save:fclean eclean
	git add --all
	git commit -m "Autosaving on push_swap"
	git push

all:$(NAME)

norme:
	@echo "==========NORME=========="
	@norminette $(SRC) includes
	@echo "==========DONE=========="

clean:
	make -C libft/ clean
	rm -f $(OBJ)

fclean:clean
	make -C libft/ fclean
	rm -f $(NAME)

eclean:clean
	rm -f *~
	rm -f includes/*~

re:fclean all

%.o:%.c
	gcc -c $(FLAG) $(INCLUDE) $(SRC)

.PHONY: $(NAME) all clean fclean re save m
