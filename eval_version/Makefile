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

SRC	=	sort_insrt_con.c push_swap_con.c sort_quick_man4a_3.c sort_quick_man4a_2.c sort_quick_man4a.c\
		sort_quick_man4b_5.c sort_quick_man4b_4.c sort_quick_man4b_3.c sort_quick_man4b_2.c sort_quick_man4b.c\
		sort_quick_man3.c sort_quick_man2.c sort_quick_man.c\
		sort_quick3.c sort_quick2.c utils.c sort_insrt.c\
		sort_quick.c push_swap.c stack_act3.c stack_act1.c stack_act2.c

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

.c.o:	${SRCS}
	@mkdir -p ${addprefix ${BUILD}, ${DIRSRC}}
	@mkdir -p ${addprefix ${BUILD}, ${SHARE_DIR}}
	@mkdir -p ${addprefix ${BUILD}, ${BONUS_DIR}}
	${CC} ${CFLAGS} -I ${LIBDIR} -I ${HEAD} \
	 -c $< -o ${addprefix ${BUILD}, ${<:.c=.o}}

${NAME}:	${OBJS} ${SHARE_OBJS} ${LIBFT} 
	@${CC} ${CFLAGS} ${addprefix ${BUILD}, ${OBJS}} ${addprefix ${BUILD}, ${SHARE_OBJS}}\
	${LIBFT} -o ${NAME}
	@echo "$(GREEN) $@ Linking Done!$(NOC)" 

all: ${NAME}

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
NUM	=	-706404366 511599284 1349054117 1941080828 -760495512 -1448160347 -1171860955 -1313815841 -124410546 -1539094345 891134336 -560264149 -1903271989 -1560424048 935821817 -1400917623 1589952276 470749638 -830327801 -949993543 1852415225 1526865197 -1825179986 -115442442 1900989646 604261575 -1593465794 -217033263 697820102 -1900240388 81891736 1977426918 -1803290821 128529904 704839093 -76378007 1425723254 2120819768 -1230192167 2112704639 -462153163 -1386003915 1943187590 -1535264566 236680134 -1842063392 881287393 -1570821287 459401776 -471292799 


t1:	
	./push_swap ${NUM} | ./checker_linux ${NUM}
#ARG=`ruby -e "puts (1..50).to_a.to_a.shuffle.join(' ')"` && ./push_swap $ARG | ./checker_linux $ARG
#ARG="4 7 8 9 10 11 12 13 14 15 16"
t2:	
	./push_swap_test $(NUM) > check.txt

test2:	re
	${CC} ${CFLAGS} -I ${HEAD} -o ${NAME} playground.c

mem:	
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

.PHONY:	all clean fclean re bonus test t1 t2 mem tester norm name

# this will add the file dependencies below, i.e. it modifies this file
depend:
		makedepend -I${HEAD} -I${LIBDIR} -- ${DIRSRC}$(SRCS)

# DO NOT DELETE THIS LINE -- make depend depends on it.

