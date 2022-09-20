all: arvore.o prog.cpp
			g++ -o prog prog.cpp arvore.o

funcoes.o: arvore.cpp
						g++ -o arvore.o -c arvore.cpp

clean:
				rm -f *.o

run:
				./prog < input.txt > output.txt
