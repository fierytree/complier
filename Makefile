CC := g++
CFLAGS := -Wall -Wextra -std=c++11 # without debug
TARGET := ./bin/main

all: run

src/main.lex.yy.c: src/main.lex
	 flex --noyywrap -o src/main.lex.yy.cpp  src/main.lex 

src/main.tab.c: src/main.y
	bison -o src/main.tab.cpp --defines=src/main.tab.h -v src/main.y

src/pch.h.gch: src/pch.h
	g++ -x c++-header -o src/pch.h.gch -c src/pch.h

lex: src/main.lex.yy.c

yacc: src/main.tab.c

main: src/pch.h.gch
	$(CC) $(CFLAGS) $(shell ls ./src/*.cpp) -o ./bin/main

.PHONY: all clean main run lex yacc test debug link testscope asm nasm example-code out

run: lex yacc main
	./bin/main tests/test.c > result.txt

run1: lex yacc main
	./bin/main tests/test1.c > result.txt

run2: lex yacc main
	./bin/main tests/test2.c > result.txt

run3: lex yacc main
	./bin/main tests/test3.c > result.txt

run4: lex yacc main
	./bin/main tests/test4.c > result.txt

run5: lex yacc main
	./bin/main tests/test5.c > result.txt

run6: lex yacc main
	./bin/main tests/test6.c > result.txt

clean:
	rm -f src/*.output src/main.lex.yy.cpp src/main.tab.cpp src/main.tab.h src/main.output src/pch.h.gch $(TARGET) *.o ./bin/* 

test: 
	./bin/main tests/test.c > result.txt