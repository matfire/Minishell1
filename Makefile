##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=		src/main.c \
			src/split.c \
			src/path.c \
			src/utils.c \
			src/exec.c \
			src/analyse.c \
			src/my_strcmp.c \
			src/builtins.c \
			src/my_putstr.c \
			src/my_getnbr.c \
			src/my_strcpy.c \
			src/my_strcat.c \
			src/env.c \
			src/my_str_isalpha.c

CRIT_SRC	=	src/analyse.c \
				src/split.c \
				src/path.c \
				src/utils.c \
				src/exec.c \
				src/my_strcmp.c \
				src/builtins.c \
				src/my_putstr.c \
				src/my_getnbr.c \
				src/my_strcpy.c \
				src/my_strcat.c \
				src/env.c \
				src/my_str_isalpha.c \
				bonus/find_function.c \
				bonus/get_words_colons.c \
				bonus/check_builtins.c

CRIT_NAME	=	criterion

OBJ	=	$(SRC:.c=.o)

NAME	=	mysh

CFLAGS	+=	-Wall -Wextra  -I./inc -g

LDFLAGS	=	-lcriterion -lgcov --verbose -I./inc

all	:	$(NAME)

$(NAME):			$(OBJ)
		gcc -o $(NAME) $(OBJ) -Llib -lgnl

clean	:
			rm -f $(NAME)

fclean	:	clean
			rm -f $(OBJ)
			rm -f $(CRIT_NAME)

re	:	fclean all

test_run:			$(OBJ)
		cc -o $(CRIT_NAME) $(CRIT_SRC) $(LDFLAGS)
		./$(CRIT_NAME)
