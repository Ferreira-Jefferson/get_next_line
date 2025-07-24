NAME = gnl

MANDATORY_SRC = get_next_line_utils.c get_next_line.c
BONUS_SRC = ./tests/main.c get_next_line_utils_bonus.c get_next_line_bonus.c

CC = gcc
FLAGS = -Wall -Werror -Wextra -g

MANDATORY_OBJ = $(MANDATORY_SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

all: $(NAME)

$(NAME): $(MANDATORY_OBJ)
	$(CC) $(FLAGS) $(MANDATORY_OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

bonus:
	@$(MAKE) MANDATORY_OBJ="$(MANDATORY_OBJ) $(BONUS_OBJ)" all

run: all 
	./$(NAME)

clean:
	rm -f $(MANDATORY_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean