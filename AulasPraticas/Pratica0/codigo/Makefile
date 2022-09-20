all : prog.o
		g++ prog.cpp -o exec

prog.o: prog.cpp
	g++ -o prog.o -c prog.cpp

clean:
		rm -f *.o exec

run:
		./exec < input.txt > output.txt
