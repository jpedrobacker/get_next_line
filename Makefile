SRC =	get_next_line.c get_next_line_utils.c

FLAGS =	-Wall -Werror -Wextra
CC =	cc

run:
	$(CC) $(FLAGS) $(SRC) maintest.c -o saida
