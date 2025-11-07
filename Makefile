# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsao-pay <rsao-pay@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/07 16:35:35 by rsao-pay          #+#    #+#              #
#    Updated: 2025/11/07 16:49:15 by rsao-pay         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= libftprintf.a

SRC 		= 

OBJS 		= ${SRC:.c=.o}

CC 			= cc
RM 			= rm -f
CFLAGS 		= -Wall -Wextra -Werror
LIBFTDIR	= ./libft
LIBFT		= ${LIBFTDIR}/libft.a

%.o: %.c
	@${CC} ${CFLAGS} ${INCLUDE} -c $< -o $@
	@echo "Compiling $< ... done!"

${NAME}: ${LIBFT} ${OBJS}
	@ar rcs ${NAME} ${OBJS} libft/*.o
	@echo "printf compiled"

${LIBFT}:
	@(MAKE) -C ${LIBFTDIR}

all: ${NAME}

clean:
	@${RM} ${OBJS}
	@(MAKE) -C ${LIBFTDIR} clean
	@echo "cleaning complete"

fclean: clean
	@${RM} ${NAME}
	@(MAKE) -C ${LIBFTDIR} fclean
	@echo "fclean is done"

re: fclean all
	@echo "full rebuild complete"

.PHONY: all clean fclean re