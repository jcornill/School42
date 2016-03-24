# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcornill <jcornill@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/27 12:48:49 by jcornill          #+#    #+#              #
#    Updated: 2016/03/24 16:24:55 by jcornill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLEAN_LEMIN=make -C lem_in/ fclean
CLEAN_FDF=make -C fdf/ fclean

clean:
	$(CLEAN_LEMIN)
	$(CLEAN_FDF)

save: clean
	git add --all
	git commit -m "Autosaving"
	git push
