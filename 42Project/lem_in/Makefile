# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcornill <jcornill@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/24 18:32:00 by jcornill          #+#    #+#              #
#    Updated: 2016/03/31 14:07:02 by jcornill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=lem-in
SRC=lem_in.c check_entry.c check_entry2.c link_checker.c path_process.c \
ants_mover.c utils.c
OBJ=$(SRC:.c=.o)
FLAG=-Wall -Wextra -Werror
INCLUDE=-I includes

$(NAME): $(OBJ)
	Make -C libft/
	gcc $(FLAG) -o $(NAME) $(OBJ) libft/libft.a

m: $(NAME)
	@echo "==========PROG=========="
	@./$(NAME) < test.map

save:fclean
	git add --all
	git commit -m "Autosaving on lem_in"
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

re:fclean all

%.o:%.c
	gcc -c $< $(FLAG) $(INCLUDE) -o $@

.PHONY: all clean fclean re save m
