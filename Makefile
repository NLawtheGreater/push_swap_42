# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: niclaw <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/24 13:59:17 by niclaw            #+#    #+#              #
#    Updated: 2022/10/28 21:23:52 by niclaw           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### EXECUTABLE ###
# This is where you want to put the name of your program or library that you will be compiling

NAME	= push_swap

### DIR ###
# all the dir to neatly keep your .c and .h

DIRSRC		= src/
BONUS_DIR	= bonus/
HEAD		= include/
SHARE_DIR	= share/
LIBDIR		= libft/
BUILD =	./build/

### TESTER GIT URL ###
# add some git url to your makefile to make your evaluator life easier

TESTER1		=
TESTER2		=
TESTER3		=
TESTER4		=

### SOURCE FILE ###
# the name of your .c go here. SRC is for mandatory, BONUS is for the bonus. 
# SHARE is for .c file that your mandatory and bonus use. LIBFT is where your specific libft .c file go.

SRC	=	push_swap.c stack_act3.c stack_act1.c stack_act2.c va_12.c

BONUS	=	

SHARE	=

### PATH ###
# DO NOT CHANGE
SRCS		= ${addprefix ${DIRSRC}, ${SRC}}
BONUS_SRCS	= ${addprefix ${BONUS_DIR}, ${BONUS}}
SHARE_SRCS	= ${addprefix ${SHARE_DIR}, ${SHARE}}

### OBJECT FILE ###
# DO NOT CHANGE
OBJS		= ${SRCS:.c=.o}
BONUS_OBJS	= ${BONUS_SRCS:.c=.o}
SHARE_OBJS	= ${SHARE_SRCS:.c=.o}

## LIBFT TARGET ##
LIBFT	= ${LIBDIR}libft.a

### COMPILATION ###
# the compilation flag that will we will use for the project

CC	= gcc
CFLAGS	= -g -Wall -Wextra -Werror
RM	= rm -f

### COLORS ###
# up to your creativity 
NOC		= \033[0m
RED		= \033[1;31m
GREEN	= \033[1;32m
YELLOW	= \033[1;33m
BLUE	= \033[1;34m
WHITE	= \033[1;37m

### TMP ###
# if needed
MSG = "Upload to git"

### RULES ###

.c.o:	${HEAD} ${LIBDIR}
	@mkdir -p ${addprefix ${BUILD}, ${DIRSRC}}
	@mkdir -p ${addprefix ${BUILD}, ${SHARE_DIR}}
	@mkdir -p ${addprefix ${BUILD}, ${BONUS_DIR}}
	${CC} ${CFLAGS} -I ${LIBDIR} -I ${HEAD} \
	 -c $< -o ${addprefix ${BUILD}, ${<:.c=.o}}

all:	${NAME}

${NAME}:	${OBJS} ${SHARE_OBJS} ${LIBFT} 
	@${CC} ${CFLAGS} ${addprefix ${BUILD}, ${OBJS}} ${addprefix ${BUILD}, ${SHARE_OBJS}}\
	${LIBFT} -o ${NAME}
	@echo "$(GREEN) $@ Linking Done!$(NOC)" 

${LIBFT}:
	make -C ${LIBDIR}
	cp ${LIBFT} ${NAME}

bonus:	${BONUS_OBJS} ${SHARE_OBJS} ${LIBFT}
	@${CC} ${CFLAGS} ${addprefix ${BUILD}, ${BONUS_OBJS}} ${addprefix ${BUILD}, ${SHARE_OBJS}}\
	${LIBFT} -o ${BONUS_NAME}
	@echo "$(GREEN)${BONUS_NAME}$(NOC)"

clean:
	@echo "$(RED)clean$(NOC)"
	${RM} -r ${BUILD}
	make clean -C ${LIBDIR} 

fclean:	clean
	@echo "$(RED)fclean$(NOC)"
	${RM} ${NAME} ${BONUS_NAME}
	make fclean -C ${LIBDIR} 

re:	fclean all

## PUSH_SWAP ##
NUM	=1..10

test:	
	ARG=`ruby -e "puts (1..10).to_a.to_a.shuffle.join(' ')"`
	./push_swap $$ARG

test2:	re
	${CC} ${CFLAGS} -I ${HEAD} -o ${NAME} playground.c
	./push_swap $(NUM) > check.txt

mem:	re
	./push_swap
	valgrind -s --leak-check=full ./push_swap ${NUM}

tester:
	@echo "$(YELLOW)Testers are not perfect but its good enough$(NOC)"
	git clone ${TESTER1} TESTER1
	git clone ${TESTER2} TESTER2
	git clone ${TESTER3} TESTER3
	git clone ${TESTER3} TESTER4

norm:
	norminette

gitpush:
	git add .
	git status
	git commit -m "${MSG}"
	git push

help:
	@clear
	@echo "$(GREEN)Avaibles options:$(NOC)"
	@echo "$(RED)==================$(NOC)"
	@echo "$(RED)| $(YELLOW)make ${NAME} $(RED)|$(NOC)"
	@echo "$(RED)| $(YELLOW)make bonus     $(RED)|$(NOC)"
	@echo "$(RED)| $(YELLOW)make norm      $(RED)|$(NOC)"
	@echo "$(RED)| $(YELLOW)make tester    $(RED)|$(NOC)"
	@echo "$(RED)| $(YELLOW)make clean     $(RED)|$(NOC)"
	@echo "$(RED)| $(YELLOW)make fclean    $(RED)|$(NOC)"
	@echo "$(RED)| $(YELLOW)make re        $(RED)|$(NOC)"
	@echo "$(RED)| $(YELLOW)make help      $(RED)|$(NOC)"
	@echo "$(RED)| $(YELLOW)make test      $(RED)|$(NOC)"
	@echo "$(RED)| $(YELLOW)make mem      $(RED)|$(NOC)"
	@echo "$(RED)==================$(NOC)"

.PHONY:	all clean fclean re bonus test mem