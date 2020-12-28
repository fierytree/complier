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
	$(CC) $(CFLAGS) $(shell ls ./src/*.cpp) -o ./bin/main.out

.PHONY: all clean main run lex yacc test debug link testscope asm nasm example-code out

run: lex yacc main
	./bin/main.out tests/test6.c > main.S

clean:
	rm -f src/*.output src/main.lex.yy.cpp src/main.tab.cpp src/main.tab.h src/main.output src/pch.h.gch $(TARGET) *.o ./bin/* 

test: 
	gcc main.s -m32 -o main.out
	qemu-i386 main.out

ans:
	gcc ans.s -m32 -o ans.out
	qemu-i386 ans.out

code:
	gcc tests/test.c -m32 -std=c99 -S -o ans.S -O0 -fno-asynchronous-unwind-tables -fno-builtin-fno-common -fno-ident -finhibit-size-directive -fno-pie -march=i386

code6:
	gcc tests/test6.c -m32 -std=c99 -S -o ans.S -O0 -fno-asynchronous-unwind-tables -fno-builtin-fno-common -fno-ident -finhibit-size-directive -fno-pie -march=i386