CC = gcc
CFLAGS = -Wall -Wextra

SRCS = studentmain.c studentfunctions.c
OBJS = $(SRCS:.c=.o)
EXECUTABLE = grade_system

.PHONY: all clean

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(EXECUTABLE) $(OBJS)
