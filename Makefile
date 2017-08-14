# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aviau <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/11 11:02:36 by aviau             #+#    #+#              #
#    Updated: 2017/08/11 07:35:02 by aviau            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fdf

SRC_NAME =	c_pattern.c\
			disp_data.c\
			draw_grid.c\
			draw_line.c\
			draw_triangle.c\
			get_next_line.c\
			hook.c\
			k_press.c\
			k_rel.c\
			key_apply.c\
			main.c\
			mouse.c\
			parse.c\
			rotate.c

OBJ_NAME = $(SRC_NAME:.c=.o)
SRC_PATH = ./src/
OBJ_PATH = ./obj/
SRC=$(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ=$(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC=-I ./include -I./libft -I ./libmlx
ARG=-L ./libft -lft -lmlx\
	-framework OpenGl -framework AppKit
CFLAGS = -Wall -Wextra
all: $(NAME)

$(NAME): lib $(OBJ)
	@gcc $(CFLAGS) $(ARG) $(INC) $(OBJ) -o $@

lib:
	@make -C ./libft

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	-@mkdir -p $(OBJ_PATH)
	@gcc $(CFLAGS) -c -o $@ $< $(INC)

clean:
	-@rm -rf $(OBJ_PATH)
	@make -C ./libft $@

fclean: clean
	-@rm $(NAME)
	@make -C ./libft $@

re: fclean all

.PHONY: fclean clean
