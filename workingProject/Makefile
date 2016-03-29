# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcornill <jcornill@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/27 12:48:49 by jcornill          #+#    #+#              #
#    Updated: 2016/03/29 17:52:58 by jcornill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLEAN_LEMIN=make -C lem_in/ fclean
CLEAN_FDF=make -C fdf/ fclean
CLEAN_FILLER=make -C filler/ fclean

clean:
	$(CLEAN_LEMIN)
	$(CLEAN_FDF)
	$(CLEAN_FILLER)

save: clean
	git add --all
	git commit -m "Autosaving"
	git push
