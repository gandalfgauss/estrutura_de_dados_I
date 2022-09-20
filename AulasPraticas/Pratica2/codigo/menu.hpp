#include "aluno.hpp"
#include "professor.hpp"
#include "disciplina.hpp"
#include "atestadoMatricula.hpp"
#include "encargo.hpp"
#include <cstring>
#include <string>
#ifndef MENU_HPP
#define MENU_HPP

int menuInicial();
void menuAluno(Aluno**,Atestado**,int&,int&);
void menuProfessor(Professor**,Encargo**,int&,int&);
void menuDisciplina(Disciplina**, Atestado**,Encargo**, int,int,int&);
void menuAtestadoMatricula(Atestado**,Aluno**,Disciplina**,int,int,int&);
void menuEncargoProfessor(Encargo**,Professor**, Disciplina**, int, int, int&);

#endif
