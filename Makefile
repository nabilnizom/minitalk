NAME = libftprintf.a

SRC = $(shell find . -name ft_printf\*.c)

CC = gcc
CFLAGS = -Wextra -Wall -Werror

all: $(NAME)

$(NAME):$(SRC:.c=.o)
	ar rcs $@ $^

bonus : $(BONUS:.c=.o)
	ar rcs $(NAME) $^

so:
	$(CC) -fPIC $(CFLAGS) $(SRC)
	gcc -shared -o ft_printf.so $(OBJ)

%.o : %.c ft_printf.h
	$(CC) $(CFLAGS) $< -c

clean :
	rm -f *.o

fclean :
	rm -f $(NAME) *.o

re : fclean all

.PHONY : all clean fclean re
