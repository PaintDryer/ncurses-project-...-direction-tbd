LINKS := -lncurses
FLAGS := #-Wall -Werror -Wextra
DIRS := -I./src/ -I./include
#SRCS := ./src/main.c ./src/deltatime.c

#searches for all C files
SRCS := $(wildcard src/*.c)

#automatically applies to %.o: %.c
OBJS := $(SRCS:%.o=%.c)

all: a.out
	echo flags disabled
a.out: $(OBJS)
	cc $(FLAGS) $^ $(DIRS) -o $@ $(LINKS)

# $< first requirement, $@ target
%.o: %.c
	cc $(FLAGS) -c $< $(DIRS) -o $@

clean:
	rm curse src/*.o

# Tells make 'all' and 'clean' are only command names
.PHONY: all clean

