CC=gcc
CFLAGS=-Werror -Wall -Wextra -pedantic -std=gnu89 -g
PROG=prog.out



all: $(PROG)
	
$(PROG):
	$(CC) $(CFLAGS) *.c
clr:
	rm -f $(PROG)

