
CC = gcc

CFLAGS = -std=c11

EXE = bsttest

HDRS = bst.h

LIBS = 

SRCS = main.c bst.c

OBJS = $(SRCS:.c=.o)

$(EXE): $(OBJS) $(HDRS) Makefile
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBS)

$(OBJS): $(HDRS) Makefile

clean:
	rm -f core $(EXE) *.o
