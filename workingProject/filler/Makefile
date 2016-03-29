# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcornill <jcornill@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/24 18:32:00 by jcornill          #+#    #+#              #
#    Updated: 2016/03/29 17:51:44 by jcornill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=filler
SRC=filler.c
OBJ=$(SRC:.c=.o)
FLAG=#-Wall -Wextra -Werror
INCLUDE=-I includes

$(NAME): $(OBJ)
	Make -C libft/
	gcc $(FLAG) -o $(NAME) $(OBJ) libft/libft.a

m: $(NAME)
	@echo "==========PROG=========="
	@./$(NAME)

save:fclean
	git add --all
	git commit -m "Autosaving on filler"
	git push

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

.PHONY: all clean fclean re save m
