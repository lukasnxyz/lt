# lt - latex template system
# See LICENSE file for copyright and license details.

CC = gcc
SRC = lt.c
OBJ = ${SRC:.c=.o}
PREFIX = /usr/local
MANPREFIX = ${PREFIX}/share/man

all: lt

.c.o:
	${CC} -c ${CFLAGS} $<

lt: ${OBJ}
	${CC} -o $@ ${OBJ}

clean:
	rm -f lt *.o

install: all
	mkdir -p ${DESTDIR}${PREFIX}/bin
	cp -f lt ${DESTDIR}${PREFIX}/bin
	chmod 755 ${DESTDIR}${PREFIX}/bin/lt

uninstall:
	rm -f ${DESTDIR}${PREFIX}/bin/lt
