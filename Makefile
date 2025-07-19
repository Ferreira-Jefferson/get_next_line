NAME = gnl

SRC = get_next_line.c get_next_line_utils.c
SRC_TEST = get_next_line.test.c

CC = gcc
FLAGS = -Wall -Werror -Wextra -g

OBJ_SRC = $(SRC:.c=.o)
OBJ_SRC_TEST = $(SRC_TEST:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_SRC) $(OBJ_SRC_TEST)
	$(CC) $(FLAGS) $(OBJ_SRC) $(OBJ_SRC_TEST) -o $(NAME)
	make clean

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

test: all 
	./$(NAME)

clean:
	rm -f $(OBJ_SRC) $(OBJ_SRC_TEST)

fclean: clean
	rm -f $(NAME)

re: fclean all