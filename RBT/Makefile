
CC = gcc

CFLAGS = -std=c11

EXE = rbttest

HDRS = rbt.h

LIBS = 

SRCS = main.c rbt.c

OBJS = $(SRCS:.c=.o)

$(EXE): $(OBJS) $(HDRS) Makefile
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBS)

$(OBJS): $(HDRS) Makefile

clean:
	rm -f core $(EXE) *.o
