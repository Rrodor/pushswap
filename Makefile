NAME= pushswap

SRC= file1.c pushswap_mvm.c

OBJ= $(SRC:.c=.o)

all: $(NAME) clean

$(NAME): $(OBJ)
	gcc -c $(SRC)
	gcc -Wall -Wextra -Werror -I. $(OBJ) -L. -lft -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
