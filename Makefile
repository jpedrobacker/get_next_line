SRC =	get_next_line.c get_next_line_utils.c

SRC_BONUS = get_next_line_bonus.c get_next_line_utils_bonus.c

FLAGS =	-Wall -Werror -Wextra

CC =	cc

run:
	$(CC) $(FLAGS) -D BUFFER_SIZE=3 $(SRC) maintest.c -o saida.out

run bonus:
			$(CC) $(FLAGS) -D BUFFER_SIZE=3 $(SRC_BONUS) maintest.c -o saida_bonus.out