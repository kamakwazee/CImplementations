
CC = gcc

CFLAGS = -std=c11

EXE = trietest

HDRS = trie.h

LIBS = 

SRCS = main.c trie.c

OBJS = $(SRCS:.c=.o)

$(EXE): $(OBJS) $(HDRS) Makefile
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBS)

$(OBJS): $(HDRS) Makefile

clean:
	rm -f core $(EXE) *.o
