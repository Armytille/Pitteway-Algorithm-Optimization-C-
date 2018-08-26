NAME = pitteway
CC = gcc
CFLAGS = -Wall -Wextra
FILE = pitt_char.c pittest.c pitt_test.c main.c
OBJ = $(FILE:.c=.o)
INCLUDE = pitteway.h

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

$(OBJ): $(FILE) $(INCLUDE)
	$(CC) -c $(FILE) $(CFLAGS)

clean:
	rm $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
