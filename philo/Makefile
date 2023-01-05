NAME = philo
HEADER = philo.h

SRC = actions.c check.c dinner.c finish.c init.c philo.c time.c utils.c

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
