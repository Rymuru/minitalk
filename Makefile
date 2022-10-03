# *======== SOURCES ========*

SRCS_1	=	\
			server.c	\
			servers_utils.c

SRCS_2	=	\
			client.c	\
			client_utils.c

SRCSD	= srcs/

OBJS_1	= ${addprefix ${SRCSD}, ${SRCS_1:.c=.o}}

OBJS_2	= ${addprefix ${SRCSD}, ${SRCS_2:.c=.o}}

# *======== INCLUDES ========*

INC = -I ./includes
INCPRINTF = -I ./printf/scrs

# *======== LIBS ========*

PRINTF_DIR = ./printf
PRINTF_FLAGS = -L$(PRINTF_DIR) -libftprintf

# *======== OTHERS ========*

NAME_1	= server

NAME_2	= client

CC		= clang
RM		= rm -rf

CFLAGS	= -g -Wall -Wextra -Werror

# *======== RULES ========*

all:		${NAME_1} ${NAME_2}

.c.o:	
		@clang ${CFLAGS} ${INCPRINTF} ${INC} -c $< -o $(<:.c=.o)

${NAME_1}:	${OBJS_1}
					make -C ${PRINTF_DIR}
			${CC} ${INCPRINTF} ${INC} ${CFLAGS} ${OBJS_1} ${PRINTF_FLAGS} -o ${NAME_1}

${NAME_2}:	${OBJS_2}
					make -C ${PRINTF_DIR}
			${CC} ${INCPRINTF} ${INC} ${CFLAGS} ${OBJS_2} ${PRINTF_FLAGS} -o ${NAME_2}


clean:
			${RM} ${OBJS_1} ${OBJS_2}

fclean:		clean
			${RM} ${NAME_1} ${NAME_2}

re:			fclean all

.PHONY:		all clean fclean re