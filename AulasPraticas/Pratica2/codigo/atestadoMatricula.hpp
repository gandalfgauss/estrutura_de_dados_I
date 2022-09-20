#include <string>
#include <cstring>
#include "aluno.hpp"
#include "disciplina.hpp"
#ifndef atestadoMatricula_hpp
#define atestadoMatricula_hpp

typedef struct atestado Atestado;

Atestado* criarAtestado();
Atestado** criarAtestado(int);
Atestado* inserirDadosAtestado(string,int);
int buscarAtestado(Atestado**, string, int);
Atestado* inserirDisciplinaAtestado(Atestado*,Disciplina**, Aluno**,int,int);
bool verificarCargaHoraria(Atestado*,int);
bool buscarDisciplinaAtestado(Atestado*,string);
Atestado* alocarAtestadoDisciplinas();
bool verificarCargaHoraria(Atestado*,Disciplina*,int);
string retornarNomeAlunoAtestado(Atestado*);
void mostrarDisciplinasAluno(Atestado*);
void liberarAtestado(Atestado**,int);
void liberarAtestado(Atestado*);
void removerDisciplinaAtestado(Atestado*, int);
int retornarIndiceDisciplinaAtestado(Atestado*, string);
void removerAtestado(Atestado**,int,int&);

#endif
