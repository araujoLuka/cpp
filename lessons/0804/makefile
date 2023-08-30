CC = g++
CPPFLAGS = -Wall -g
PROGRAM = cad

all: $(PROGRAM)
$(PROGRAM): main.o Pessoa.o
	g++ -o $(PROGRAM) $? $(CPPFLAGS)

debug: CPPFLAGS += -DDEBUG
debug: all

main.o: main.cpp

Pessoa.o: Pessoa.hpp Pessoa.cpp

clean:
	rm -f *.o *.gch $(PROGRAM)
