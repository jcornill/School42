#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcornill <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/27 12:48:49 by jcornill          #+#    #+#              #
#    Updated: 2015/12/20 12:29:58 by jcornill         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME=alum1
SRC=alum1.c
OBJ=$(SRC:.c=.o)
FLAG=-Wall -Wextra -Werror
INCLUDE=-I includes

$(NAME):
	gcc -o $(NAME) $(FLAG) $(INCLUDE) $(OBJ)

m: re
	@echo "==========OUTPUT=========="
	@./$(NAME)

save:
	git add --all
	git commit -m "Autosaving on rushes"
	git push

all:$(NAME)

clean:
	rm -f $(OBJ)

fclean:clean
	rm -f $(NAME)

re:fclean all

%.o:%.c
	gcc -c $(FLAG) $(INCLUDE) -o $@ -c $<

.PHONY: $(NAME) all clean fclean re
