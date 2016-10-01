# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aviau <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/11 11:02:36 by aviau             #+#    #+#              #
#    Updated: 2016/10/01 13:09:06 by aviau            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	gcc -g -Wall -Wextra -Werror -o fdf libft/libft.a main.c disp_data.c hook.c c_pattern.c mouse.c k_press.c k_rel.c key_apply.c draw_line.c rotate.c draw_grid.c get_next_line.c parse.c -lmlx -framework OpenGL -framework AppKit

re: fclean all

clean:
	@rm -rf $(OBJ_PATH)
	@(cd $(LIB) && $(MAKE) $@)

fclean: clean
	@rm -rf $(NAME)
	@(cd $(LIB) && $(MAKE) $@)

norme:
	@norminette $(SRC) $(addprefix $(INC_PATH),$(INC_NAME))
