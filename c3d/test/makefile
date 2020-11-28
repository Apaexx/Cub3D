NAME=c3d.a
SRC =*.c
OUT =*.o

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(SRC)
	ar -rc $(NAME) $(OUT)
	ranlib $(NAME)
	make clean

clean:
	rm -f $(OUT)

fclean:
	rm -f $(NAME)

re: fclean all