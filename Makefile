# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flplace <flplace@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/22 12:20:26 by flplace           #+#    #+#              #
#    Updated: 2022/06/25 17:40:37 by flplace          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
# COLORS

GREEN		:= \033[0;92m
YELLOW		:= \033[0;93m
BLUE		:= \033[0;94m
END_COLOR	:= \033[0;39m

# **************************************************************************** #
# VARIABLES

SRCS	=	src/main.c \
			src/parsing.c \
			src/mapbuilder.c \
			src/mem_utilities.c \
			src/parsing_utilities.c \
			src/print_utilities.c \
			src/mlx_utilities.c \
			src/moves_utilities.c \
			src/game_process.c \
			src/lvl_building.c \
			library/ft_strcmp.c \
			library/ft_strncmp.c \
			library/ft_itoa.c \
			gnl/get_next_line.c \
			gnl/get_next_line_utils.c
LIB		=	ft_printf/libftprintf.a \
			mlx/libmlx.a
OBJ		=	${SRCS:.c=.o}
NAME	=	so_long
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror

# **************************************************************************** #
# RULES

%.o:	%.c
	@${CC} ${CFLAGS} -c -g $< -o $@
	@echo "$(BLUE)Compiling $<...$(END_COLOR)"

$(NAME):	${OBJ} Makefile
	@make --no-print-directory -C ft_printf
	@make --no-print-directory -C mlx
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIB) -lXext -lX11
	@echo "$(GREEN)Compiled $(NAME) :)$(END_COLOR)"

all:	${NAME}

clean:
	@rm -f ${OBJ}
	@echo "$(YELLOW)Removed object files.$(END_COLOR)"

fclean: clean
	@make fclean --no-print-directory -C ft_printf
	@make clean --no-print-directory -C mlx
	@rm -f ${NAME}
	@echo "$(YELLOW)Cleaned libraries and $(NAME) executable.$(END_COLOR)"

re:		fclean all
	@echo "$(GREEN)Cleaned all and rebuilt $(NAME) and $(LIB)!$(END_COLOR)"

.PHONY:	all clean fclean re
