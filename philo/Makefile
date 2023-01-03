NAME = philo
HEADER = philo.h

SRC = $(wildcard *.c)

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra
CC = cc -pthread
RM = rm -f

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

# Tests
test_1:
	@echo o filósofo não deve comer e deve morrer!
	./philo 1 800 200 200

test_2:
	@echo ninguém deve morrer!
	./philo 5 800 200 200

test_3:
	@echo ninguém deve morrer, todos devem comer pelo menos 7 vezes e parar.
	./philo 5 800 200 200 7

test_4:
	@echo ninguém deve morrer!
	./philo 4 410 200 200

test_5:
	@echo um filósofo deve morrer!
	./philo 4 310 200 100