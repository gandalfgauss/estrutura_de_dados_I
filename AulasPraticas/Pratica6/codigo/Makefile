all: funcoes.o prog.cpp
			g++ -o prog prog.cpp funcoes.o

funcoes.o: funcoes.cpp
						g++ -o funcoes.o -c funcoes.cpp

clean:
				rm -f *.o

run:
				./prog < input.txt > output.txt
