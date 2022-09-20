#ifndef ARVORE_HPP
#define ARVORE_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

typedef struct Contato contato;

bool compara(char *nome1, char *nome2, int x);
void Contato_inicia(Contato **praiz);
Contato* contato_cria(char nome[100], int telefone, int aniversario);
void imprimir(Contato *aux);
bool buscar(Contato **aux, char nome[100]);
bool inserir(Contato **aux, char nome[100], int telefone, int aniversario);
void retirar(Contato *dir, Contato **raiz);
bool retirar(Contato **p, char nome[100]);
void PreOrdem(Contato* c);
void PosOrdem(Contato* c);
void central(Contato* c);

#endif
