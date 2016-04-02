# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcornill <jcornill@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/01 12:47:21 by jcornill          #+#    #+#              #
#    Updated: 2016/04/02 12:02:04 by jcornill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC=filler.c process_input.c init_piece.c process.c
SRCBONUS=bonus.c
NAME=filler
OBJ=$(SRC:.c=.o)
OBJBONUS=$(SRCBONUS:.c=.o)
FLAG=-Wall -Wextra -Werror -g
INCLUDE=-I includes

$(NAME): $(OBJ)
	Make -C libft/
	gcc $(FLAG) -o $(NAME) $(OBJ) libft/libft.a

save:fclean
	git add --all
	git commit -m "Autosaving on filler"
	git push

bonus: $(OBJBONUS) $(NAME)
	gcc $(FLAG) -o bonus $(OBJBONUS) libft/libft.a

all:$(NAME)

clean:
	make -C libft/ clean
	rm -f $(OBJ)
	rm -f bonus.o

fclean:clean
	make -C libft/ fclean
	rm -f $(NAME)
	rm -f bonus

re:fclean all

%.o:%.c
	gcc -c $< $(FLAG) $(INCLUDE) -o $@

.PHONY: all clean fclean re save m
