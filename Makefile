# *======== SOURCES ========*

SRCS_1	=	\
			server.c	\
			utils.c

SRCS_2	=	\
			client.c	\
			utils.c

SRCSD	= srcs/

OBJS_1	= ${SRCS_1:.c=.o}

OBJS_2	= ${SRCS_1:.c=.o}

# *======== INCLUDES ========*

INCLUDES_DIR = -I ./includes
INC = ./includes/minitalk.h

# *======== LIBS ========*

PRINTF_DIR = ./printf
PRINTF_FLAGS = -L$(PRINTF_DIR) -lft

# *======== OTHERS ========*

NAME_1	= server

NAME_2	= client

CC		= clang
LINKER	= ar rcs
RM		= rm -rf

CFLAGS	= -g -Wall -Wextra -Werror

# *======== RULES ========*

all:		${NAME} ${NAME_2}

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME_1}:	${OBJS_1} ${INC}
					make -C ${PRINTF_DIR}
			${CC} ${CFLAGS} ${OBJS_1} ${PRINTF_FLAGS} ${INCLUDES_DIR} -o ${NAME_1}

${NAME_2}:	${OBJS_2} ${INC}
					make -C ${PRINTF_DIR}
			${CC} ${CFLAGS} ${OBJS_2} ${PRINTF_FLAGS} ${INCLUDES_DIR} -o ${NAME_2}

clean:
			${RM} ${OBJS_1} ${OBJS_2}

fclean:		clean
			${RM} ${NAME_1} ${NAME_2}

re:			fclean all

.PHONY:		all clean fclean re