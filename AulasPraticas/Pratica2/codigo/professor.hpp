#include <string>
#include <cstring>
using namespace std;
#ifndef PROFESSOR_HPP
#define PROFESSOR_HPP

typedef struct professor Professor;

Professor* criarProfessor();
Professor** criarProfessor(int);
Professor* inserirDadosProfessor(string,int);
void retornarDadosProfessor(Professor*,string*,int*);
int buscarProfessor(Professor**,int, int);
void removerProfessor(Professor**, int, int);
void liberarProfessor(Professor*);
void listarProfessor(Professor*,string*,int*);
void liberarProfessor(Professor**,int);
int retornaSiape(Professor*);
Professor* retornarProfessor(Professor*);
string retornaNomeProfessor(Professor*);

#endif
