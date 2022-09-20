#include <string>
#include <cstring>
using namespace std;

#ifndef ALUNO_H
#define ALUNO_H

typedef struct aluno Aluno;

Aluno* criarAluno();
Aluno** criarAluno(int);
Aluno* inserirDadosAluno(string,string,string,string,string);
void alterarDadosAluno(Aluno*,string,string,string,string,string);
void retornarDadosAluno(Aluno*, string*, string*, string*, string*, string*);
int buscarAluno(Aluno**,string,int);
void removerAluno(Aluno**,int,int&);
void listarAluno(Aluno*,string*,string*);
void liberarAluno(Aluno*);
void liberarAluno(Aluno**,int);
string retornaMatricula(Aluno*);
Aluno* retornarAluno(Aluno*);
string retornaNomeAluno(Aluno*);

#endif
