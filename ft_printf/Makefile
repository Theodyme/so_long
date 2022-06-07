# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flplace <flplace@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/22 12:20:26 by flplace           #+#    #+#              #
#    Updated: 2022/06/07 13:53:04 by flplace          ###   ########.fr        #
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

SRCS	=	srcs/ft_printf.c \
		srcs/ft_printf_wrappers_one.c \
		srcs/ft_printf_wrappers_two.c \
		library/ft_putchar.c \
		library/ft_putstr.c \
		library/ft_putptr.c \
		library/ft_putnbr_base.c \
		library/ft_putnbr_hex.c \
		library/ft_strlen.c \
		library/ft_checkbase.c \
		library/ft_putnbr_uint.c
OBJ		= ${SRCS:.c=.o}
NAME	= libftprintf.a
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

# **************************************************************************** #
# RULES

%.o: 	%.c
	@${CC} ${CFLAGS} -c $< -o $@

$(NAME):	${OBJ}
	@ar rc ${NAME} ${OBJ}
	@echo "$(YELLOW)$(NAME) archive compiled.$(END_COLOR)"

all:	${NAME}

clean:
	@rm -f ${OBJ}
	@echo "$(YELLOW)Removed object files.$(END_COLOR)"

fclean:	clean
	@rm -f ${NAME}
	@echo "$(YELLOW)Cleaned $(NAME) archive.$(END_COLOR)"

re:	fclean all

.PHONY:	all clean fclean re
