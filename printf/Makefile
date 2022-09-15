
SRCS	=	\
			ft_printf.c			\
			ft_hexa.c			\
			ft_hexaverrmaj.c	\
			ft_putchar.c		\
			ft_putstr.c			\
			ft_strlen.c			\
			ft_putnbr.c			\
			ft_putunsigned.c	\
			ft_adress.c


SRCSD	= scrs/

OBJS	= ${SRCS:.c=.o}

NAME	= libftprintf.a

CC		= gcc -c -o
LINKER	= ar rcs
RM		= rm -rf

CFLAGS	= -Wall -Wextra -Werror

${NAME}:	${OBJS}
			${LINKER} ${NAME} ${OBJS}

all:		${NAME}

${OBJSD}%.o:    ${SRCSD}%.c
	${CC} $@ $^ ${CFLAGS}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
