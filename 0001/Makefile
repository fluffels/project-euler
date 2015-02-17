CC=gcc

WARNING_FLAGS=-Wall -Wextra -pedantic -Winit-self -Wmissing-include-dirs \
-Wswitch-default -Wswitch-enum -Wunused-parameter -Wstrict-overflow=5 \
-Wfloat-equal -Wshadow -Wconversion -Wsign-conversion
FORMATTING_FLAGS=-fmessage-length=80 -fdiagnostics-show-option
CFLAGS=${WARNING_FLAGS} ${FORMATTING_FLAGS} -g -std=gnu11 -pipe -nostdlib \
	-fno-asynchronous-unwind-tables -fno-builtin

LDFLAGS=
LDLIBS=

TARGET=main
OBJECTS=$(addsuffix .o, $(basename $(shell ls *.c | grep -v Test)))
HEADERS=$(addsuffix .h, $(basename $(shell ls *.h | grep -v Test)))

CLEAN_TARGETS=$(addsuffix .o, $(basename $(shell ls *.c))) ${TARGET} \

all: ${OBJECTS}
	${CC} ${LDFLAGS} ${LDLIBS} $^ -o main

%.o:
	${CC} ${CFLAGS} -c ${LDFLAGS} $< -o $@

clean:
	rm ${CLEAN_TARGETS}

tar:
	make clean; tar -cvjf src.tar.bz2 *

# Calculate dependencies based on output from gcc -MM.
makefile.dep: *.[ch]
	for i in *.c; do gcc -MM "$${i}"; done > $@
include makefile.dep
