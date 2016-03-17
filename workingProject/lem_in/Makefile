# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcornill <jcornill@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/24 18:32:00 by jcornill          #+#    #+#              #
#    Updated: 2016/03/17 12:58:01 by jcornill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=lem-in
SRC=lem_in.c check_entry.c check_entry2.c link_checker.c path_process.c
OBJ=$(SRC:.c=.o)
FLAG=-Wall -Wextra -Werror
INCLUDE=-I includes

$(NAME): $(OBJ)
	Make -C libft/
	gcc $(FLAG) -o $(NAME) $(OBJ) libft/libft.a

cleanwitlib:
	@rm -f $(OBJ)
	@rm -f $(NAME)

rewitlib: cleanwitlib $(OBJ)
	gcc $(FLAG) -o $(NAME) $(OBJ) libft/libft.a

m: rewitlib eclean #norme
	@echo "==========PROG=========="
	@./$(NAME) < test.map

save:fclean eclean
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

eclean:
	@rm -f *~
	@rm -f includes/*~

re:fclean all

%.o:%.c
	gcc -c $< $(FLAG) $(INCLUDE) -o $@

.PHONY: $(NAME) all clean fclean re save m
