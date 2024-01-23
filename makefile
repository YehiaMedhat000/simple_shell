CC=gcc
CFLAGS=-Werror -Wall -Wextra -pedantic -std=gnu89 -g
PROG=prog.out
MAIN=.main.c

all: $(PROG)
	@betty *.c

$(PROG):
	@$(CC) $(CFLAGS) *.c $(MAIN) -o $(PROG)

clean:
	@rm -f $(PROG)

