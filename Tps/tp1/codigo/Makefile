all: menu.o aluno.o professor.o disciplina.o atestadoMatricula.o encargo.o funcoes2.o funcoes3.o main.cpp
	g++ main.cpp menu.o aluno.o professor.o disciplina.o atestadoMatricula.o encargo.o funcoes2.o funcoes3.o -o exec

aluno.o: aluno.cpp
	g++ -o aluno.o -c aluno.cpp 

professor.o: professor.cpp
	g++ -o professor.o -c professor.cpp

disciplina.o: disciplina.cpp
	g++ -o disciplina.o -c disciplina.cpp

menu.o: menu.cpp
	g++ -o menu.o -c menu.cpp

encargo.o: encargo.cpp
	g++ -o encargo.o -c encargo.cpp

atestadoMatricula.o: atestadoMatricula.cpp
	g++ -o atestadoMatricula.o -c atestadoMatricula.cpp

funcoes2.o: funcoes2.cpp
	g++ -o funcoes2.o -c funcoes2.cpp

funcoes3.o: funcoes3.cpp
	g++ -o funcoes3.o -c funcoes3.cpp
	
clean:
	rm -f *.o exec

run:
	./exec < input.txt > output.txt
