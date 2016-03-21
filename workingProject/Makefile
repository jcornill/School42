# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcornill <jcornill@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/27 12:48:49 by jcornill          #+#    #+#              #
#    Updated: 2016/03/21 12:57:05 by jcornill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLEAN_LEMIN=make -C lem_in/ fclean

clean:
	$(CLEAN_LEMIN)

save: clean
	git add --all
	git commit -m "Autosaving on push_swap"
	git push
