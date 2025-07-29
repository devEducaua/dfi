CFLAGS = -Wextra -Wall

all: dfi

dfi: dfi.c
	gcc $(CFLAGS) -o dfi dfi.c

clean:
	rm dfi
