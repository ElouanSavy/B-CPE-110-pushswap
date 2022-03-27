##
## EPITECH PROJECT, 2021
## makefile
## File description:
## generate binary
##

SRC	=	src/main.c	\
		src/manage_list.c	\
		src/list_op.c	\
		src/binary_index.c	\
		src/array_handler.c	\
		src/operation_list.c	\
		src/radix_sort.c	\

OBJ	=	$(SRC:.c=.o)

TEST = 	src/manage_list.c	\
		src/list_op.c	\
		tests/tests_push_swap.c	\
		src/binary_index.c	\
		src/array_handler.c	\
		src/radix_sort.c	\
		src/operation_list.c	\

NAME	=	push_swap

CPPFLAGS	=	-I./include

LIB     =       -L lib/my -lmy

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my
	gcc -o $(NAME) $(OBJ) $(CPPFLAGS) $(LIB)

clean:
	rm -f $(OBJ);
	rm -f *~;
	rm -f *.gc*
	rm -f vgcore*
	rm -f unit_tests

fclean : clean
	make fclean -C lib/my
	rm -f $(NAME)

re: fclean all

debug: fclean
	make -C lib/my
	gcc -o $(NAME) $(SRC) $(CPPFLAGS) $(LIB) -W -Wall -Wextra -ggdb3

tests_run:
	make -C lib/my
	gcc -o unit_tests $(TEST) $(CPPFLAGS) -Llib/ -lmy -lcriterion --coverage
	./unit_tests
