CC		:= gcc
TARGET 	:= build/dfi
CFLAGS 	:= -Wextra -Wall

SRCS	:= $(wildcard src/*.c)
OBJS 	:= $(SRCS:src/%.c=build/%.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

build/%.o: src/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf build
