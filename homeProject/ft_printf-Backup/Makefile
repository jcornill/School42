#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcornill <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/27 12:48:49 by jcornill          #+#    #+#              #
#    Updated: 2016/01/21 16:10:41 by jcornill         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME=libftprintf.a
SRC=ft_printf.c ft_putstrprintf.c ft_putnbr_long.c ft_putaddr.c \
ft_putnbr_base.c ft_putwchar.c ft_putnbr_base_long.c \
ft_putnbr_ulong.c ft_putonewchar.c process_flag.c print_arg.c process_color.c \
process_arg_norme.c ft_write_space.c ft_get_nbr_from_back.c process_arg_2.c
OBJ=$(SRC:.c=.o)
FLAG=-Wall -Wextra -Werror
INCLUDE=-I includes

$(NAME): $(OBJ)
	make -C libft/ re
	ar -rcs $(NAME) $(OBJ) libft/ft_*.o

m: re
	@gcc -c $(FLAG) $(INCLUDE) main.c
	@gcc $(FLAG) main.o $(NAME) -o test
	@rm main.o
	@echo "==========PROG=========="
	@./test

save:
	git add --all
	git commit -m "Autosaving on printf"
	git push

all:$(NAME)

clean:
	rm -f $(OBJ)

fclean:clean
	rm -f $(NAME)

re:fclean all

%.o:%.c
	gcc -c $(FLAG) $(INCLUDE) $(SRC)

.PHONY: $(NAME) all clean fclean re
