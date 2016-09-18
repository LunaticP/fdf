# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aviau <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/11 11:02:36 by aviau             #+#    #+#              #
#    Updated: 2016/09/18 10:53:46 by aviau            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	gcc -g -o fdf libft/libft.a main.c draw_line.c get_next_line.c parse.c -lmlx -framework OpenGL -framework AppKit

re: fclean all

clean:
	@rm -rf $(OBJ_PATH)
	@(cd $(LIB) && $(MAKE) $@)

fclean: clean
	@rm -rf $(NAME)
	@(cd $(LIB) && $(MAKE) $@)

norme:
	@norminette $(SRC) $(addprefix $(INC_PATH),$(INC_NAME))
