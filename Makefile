CC		:= cc
CFLAGS	:= -Wall -Wextra -pedantic -Werror
TARGET	:= build/dfi
SRC		:= dfi.c
OBJ		:= $(patsubst %.c, build/%.o, $(SRC))

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

build/%.o: %.c 
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf build
