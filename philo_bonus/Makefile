# Resulting bonus binary name
NAME		= philo_bonus

# Bonus source files configuration
DIR 			= src
SRCS			:= $(shell find $(DIR) -name *.c)
OBJS			= ${patsubst %.c,%.o,${SRCS}}
D_FILES			= ${patsubst %.c,%.d,${SRCS}}
INCLUDES		= includes/

# Compilation configuration
THREADS			= -pthread
CFLAGS			= -Wall -Werror -Wextra

# Console output color
GREENBG			= \033[42m
NOBG			= \033[0m
GREENTXT		= \033[1;32m
NOCOLORTXT		= \033[0m

%.o:			%.c Makefile
				${CC} ${CFLAGS} ${THREADS} -c $< -o $@ -I${INCLUDES} -MMD

all:			${NAME}

${NAME}:		${OBJS} Makefile
				${CC} ${CFLAGS} ${THREADS} ${OBJS} -o ${basename ${NAME}}
				@echo "${GREENTXT}philo is compiled${NOCOLORTXT}\n"

clean:
				@rm -rf ${OBJS} ${D_FILES}
				@echo "${GREENTXT}Cleaning complete${NOCOLORTXT} \n"

fclean:			clean
				@${RM} ${NAME}
				@echo "${GREENTXT}Full cleaning is complete${NOCOLORTXT} \n"

re:				fclean all

include $(wildcard $(D_FILES))

.PHONY:			all clean fclean re bonus
.SILENT:		all clean fclean re bonus $(NAME)
