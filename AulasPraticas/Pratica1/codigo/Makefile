all: alunos.o disciplinas.o professores.o prog.cpp
			g++ -o prog prog.cpp alunos.o disciplinas.o professores.o

alunos.o: alunos.cpp
						g++ -o alunos.o -c alunos.cpp

disciplinas.o: disciplinas.cpp
						g++ -o disciplinas.o -c disciplinas.cpp

professores.o: professores.cpp
						g++ -o professores.o -c professores.cpp

clean:
				rm -f *.o

run:
				./prog < input.txt > output.txt
