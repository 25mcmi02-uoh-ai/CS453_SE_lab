CC=gcc
CFLAGS=-Iinclude -Wall -Wextra

TARGET=build/student_management
SRCS=$(wildcard src/*.c)
OBJS=$(SRCS:.c=.o)

.PHONY: all
all: $(TARGET)
$(TARGET): $(OBJS)
	mkdir -p build
	$(CC) -o $@ $^ $(CFLAGS)

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: run
run: $(TARGET)
	./$(TARGET)
