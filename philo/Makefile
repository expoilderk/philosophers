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
	./philo 5 800 800 800

test_2:
	./philo 5 100 100 100