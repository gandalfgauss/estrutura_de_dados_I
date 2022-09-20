all: menu.o aluno.o professor.o disciplina.o atestadoMatricula.o encargo.o main.cpp
	g++ main.cpp menu.o aluno.o professor.o disciplina.o atestadoMatricula.o encargo.o -o exec

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
	
clean:
	rm -f *.o exec

run:
	./exec < input.txt > output.txt
