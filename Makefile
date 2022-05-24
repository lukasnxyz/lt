# lt - latex template system
# See LICENSE file for copyright and license details.

CC = gcc
SRCS := $(wildcard *.c)
BINS := $(SRCS:%.c=%)
DEPS = config.h

all: ${bins}

%: %.o
	$(CC) $< -o $@

%.o: %.c
	$(CC) -c $<

clean:
	rm -rvf *.o ${BINS}
