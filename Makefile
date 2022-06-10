# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: theophane <theophane@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/22 12:20:26 by flplace           #+#    #+#              #
#    Updated: 2022/06/10 17:23:57 by theophane        ###   ########.fr        #
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

SRCS	=	main.c \
			parsing.c \
			mapbuilder.c \
			print_utilities.c \
			library/ft_calloc.c \
			library/ft_strcmp.c \
			gnl/get_next_line.c \
			gnl/get_next_line_utils.c
LIB		=	ft_printf/libftprintf.a
OBJ		=	${SRCS:.c=.o}
NAME	=	so_long
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

# **************************************************************************** #
# RULES

%.o:	%.c
	@${CC} ${CFLAGS} -c $< -o $@
	@echo "$(BLUE)Compiling $<...$(END_COLOR)"

$(NAME):	${OBJ}
	@make --no-print-directory -C ft_printf
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIB)
	@echo "$(GREEN)Compiled $(NAME) :)$(END_COLOR)"

all:	${NAME}

clean:
	@rm -f ${OBJ}
	@echo "$(YELLOW)Removed object files.$(END_COLOR)"

fclean: clean
	@make fclean --no-print-directory -C ft_printf
	@rm -f ${NAME}
	@echo "$(YELLOW)Cleaned libraries and $(NAME) executable.$(END_COLOR)"

re:		fclean all
	@echo "$(GREEN)Cleaned all and rebuilt $(NAME) and $(LIB)!$(END_COLOR)"

.PHONY:	all clean fclean re