#include <string>
#include <cstring>
#include "professor.hpp"
#include "disciplina.hpp"
#ifndef encargoMatricula_hpp
#define encargoMatricula_hpp

typedef struct encargo Encargo;

Encargo* criarEncargo();
Encargo** criarEncargo(int);
Encargo* inserirDadosEncargo(string,int);
int buscarEncargo(Encargo**, int, int);
Encargo* inserirDisciplinaEncargo(Encargo*,Disciplina**, Professor**,int,int);
bool verificarCargaHoraria(Encargo*,int);
bool buscarDisciplinaEncargo(Encargo*,string);
Encargo* alocarEncargoDisciplinas();
bool verificarCargaHoraria(Encargo*,Disciplina*,int);
string retornarNomeProfessorEncargo(Encargo*);
void mostrarDisciplinasProfessor(Encargo*);
void liberarEncargo(Encargo**,int);
void liberarEncargo(Encargo*);
void removerDisciplinaEncargo(Encargo*, int);
int retornarIndiceDisciplinaEncargo(Encargo*, string);
void removerEncargo(Encargo**,int,int&);

#endif
