SRC =	get_next_line.c get_next_line_utils.c

FLAGS =	-Wall -Werror -Wextra
CC =	cc

run:
	$(CC) $(FLAGS) -D BUFFER_SIZE=3 $(SRC) maintest.c -o saida.out
