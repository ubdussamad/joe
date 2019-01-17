CC = gcc
CFLAGS = -Wall -Wextra
DEP = lib/line_reader.c

all: lex

lex: lexical_analysis.c
	$(CC) $(DEP) lexical_analysis.c -o lex

clean:
	rm lex
