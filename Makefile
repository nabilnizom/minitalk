SRC = server.c client.c
OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: server client

server: server.o ft_printf
		$(CC) -o $@ $< ft_printf/libftprintf.a
		
client: client.o
		$(CC) -o $@ $<

%o: %.c
		$(CC) -c $(CFLAGS) $?
		
ft_printf:
		make -C ft_printf

clean:
		rm -f $(OBJ)
		make -C ft_printf clean

fclean:
		rm -f server client ft_printf/ft_printf.a libminitalk.a
		
re: clean all

.PHONY: all ft_printf clean fclean re
