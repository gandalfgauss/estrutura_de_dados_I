#include <string>
#include <cstring>
using namespace std;
#ifndef DISCIPLINA_HPP
#define DISCIPLINA_HPP

typedef struct disciplina Disciplina;

Disciplina* criarDisciplina();
Disciplina** criarDisciplina(int);
Disciplina* inserirDadosDisciplina(string,string,int,string,string);
int validarCargaHoraria();
void retornarDadosDisciplina(Disciplina*,string*,string*,int*,string*,string*);
int buscarDisciplina(Disciplina**, string, int);
void listarDisciplina(Disciplina*,string*,string*);
void removerDisciplina(Disciplina**, int, int);
void liberarDisciplina(Disciplina*);
void liberarDisciplina(Disciplina**,int);
void liberarDisciplinaTad(Disciplina**);
Disciplina* retornarDisciplina(Disciplina*);
int retornarCarga(Disciplina*);
string retornarCodigo(Disciplina*);
string retornaNomeDisciplina(Disciplina*);

#endif
