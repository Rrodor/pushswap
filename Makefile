NAME= push_swap
SRC= ps_main.c pushswap.c pushswap_mvm.c pushswap_utils.c pushswap_lst.c pushswap_lst2.c ps_quicksort.c ps_bruteforce.c ps_divide.c ps_bruteforce2.c ps_bruteforce3.c ps_bruteforce2p2.c
SRCPATH= ./cfiles/
OBJ= $(SRC:.c=.o)
OBJS= $(addprefix $(OBJPATH), $(OBJ))
SRCS= $(addprefix $(SRCPATH), $(SRC))
OBJPATH= ./ofiles/

CC= gcc -Wall -Wextra -Werror

all: makelib $(NAME)

makelib:
	make -C ./libft2

$(OBJPATH)%.o: $(SRCPATH)%.c
	mkdir -p ofiles
	$(CC) -I./hfiles -I./libft2  -o $@ -c $<

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) -Llibft2 -lft -L/usr/lib -I./libft2 -I./hfiles

clean:
	rm -f $(OBJS)
	rm -rf ofiles
	make clean -C ./libft2

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft2

re: fclean all
