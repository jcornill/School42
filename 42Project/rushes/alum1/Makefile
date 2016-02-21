#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcornill <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/27 12:48:49 by jcornill          #+#    #+#              #
#    Updated: 2015/12/20 17:02:28 by jcornill         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME=alum1
SRC=alum1.c get_next_line.c is_valid_file.c ft_putstrcolor.c \
create_file_from_input.c init.c convert_buf.c display_board.c \
game.c computer.c
OBJ=$(SRC:.c=.o)
FLAG=-Wall -Wextra -Werror
INCLUDE=-I includes
LIBFT=libft.a

$(NAME): $(OBJ)
	gcc -o $(NAME) $(FLAG) $(INCLUDE) $(LIBFT) $(OBJ)

m: re
	@echo "==========OUTPUT=========="
	@./$(NAME) file.txt

save: fclean
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
