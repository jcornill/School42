# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcornill <jcornill@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/01 12:47:21 by jcornill          #+#    #+#              #
#    Updated: 2016/04/01 16:20:55 by jcornill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC=filler.c process_input.c init_piece.c process.c
NAME=filler
OBJ=$(SRC:.c=.o)
FLAG=-Wall -Wextra -Werror -g
INCLUDE=-I includes

$(NAME): $(OBJ)
	Make -C libft/
	gcc $(FLAG) -o $(NAME) $(OBJ) libft/libft.a

m: $(NAME)
	@echo "==========PROG=========="
	@./resources/filler_vm -p1 ./resources/hcao.filler -p2 ./filler -f \
	./resources/sample

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
