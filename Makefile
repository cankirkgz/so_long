# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkirkgoz <mkirkgoz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/04 14:49:34 by mkirkgoz          #+#    #+#              #
#    Updated: 2023/10/14 09:52:18 by mkirkgoz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

LIBFTDIR = ./libft
MLXDIR = ./minilibx
PRINTFDIR = ./ft_printf

CC = cc

RM = rm -f

FLAGS = -Wall -Wextra -Werror

SRC =	./game/so_long.c ./game/map.c ./get_next_line/get_next_line.c \
		./get_next_line/get_next_line_utils.c ./game/game_management.c \
		./game/player_movements.c ./game/graphics.c ./game/move_helper.c \
		./game/errors.c ./game/game_checkers.c  ./game/libft_func.c \
		./game/error_message.c \

OBJ = ${SRC:.c=.o}
INLIBFT = -L./libft -lft
INMLX = -L./minilibx -lmlx
INPRINTF = -L./ft_printf -lftprintf

.c.o:
	${CC} ${FLAGS} -Imlx -c $< -o $@

${NAME}: ${OBJ}
	@make -C $(LIBFTDIR)
	@make -C $(MLXDIR)
	@make -C $(PRINTFDIR)
	${CC} ${OBJ} ${INLIBFT} ${INMLX} ${INPRINTF} -framework OpenGL -framework AppKit -o ${NAME}

all: ${NAME}

clean:
	${RM} ${OBJ}
	@cd $(LIBFTDIR) && $(MAKE) clean
	@cd $(MLXDIR) && $(MAKE) clean
	@cd $(PRINTFDIR) && $(MAKE) clean

fclean: clean
	${RM} ${NAME}
	@cd $(LIBFTDIR) && $(MAKE) fclean
	@cd $(PRINTFDIR) && $(MAKE) fclean

re: fclean all

.PHONY: all clean fclean re

