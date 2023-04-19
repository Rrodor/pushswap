NAME= push_swap
SRC= pushswap.c pushswap_mvm.c pushswap_utils.c pushswap_lst.c pushswap_lst2.c
SRCPATH= ./cfiles/
OBJ= $(SRC:.c=.o)
OBJS= $(addprefix $(OBJPATH), $(OBJ))
SRCS= $(addprefix $(SRCPATH), $(SRC))
OBJPATH= ./ofiles/

CC= gcc

all: makelib $(NAME)

makelib:
	make -C ./libft2

%.o: $(SRCPATH)%.c
	mkdir -p ofiles
	$(CC) -I./hfiles -I./libft2  -o $(OBJPATH)$@ -c $<

$(NAME): $(OBJ)
	$(CC) $(OBJS) -o $(NAME) -Llibft2 -lft -L/usr/lib -lXext -lX11 -lm -lz -I./libft2 -I./hfiles

clean:
	rm -f $(OBJS)
	rmdir ofiles
	make clean -C ./libft2

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft2

re: fclean all
