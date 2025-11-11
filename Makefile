# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsao-pay <rsao-pay@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/07 16:35:35 by rsao-pay          #+#    #+#              #
#    Updated: 2025/11/11 21:03:27 by rsao-pay         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= libftprintf.a

SRC 		= ft_printf.c ft_utils.c ft_utils_2.c

OBJS 		= ${SRC:.c=.o}

CC 			= cc
RM 			= rm -f
CFLAGS 		= -Wall -Wextra -Werror -I.

%.o: %.c
	@${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
	@ar rcs ${NAME} ${OBJS}
	@echo "printf compiled"

all: ${NAME}

clean:
	@${RM} ${OBJS}
	@echo "cleaning complete"

fclean: clean
	@${RM} ${NAME}
	@echo "fclean is done"

re: fclean all
	@echo "full rebuild complete"

.PHONY: all clean fclean re