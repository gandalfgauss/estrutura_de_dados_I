#include <iostream>
#include "arvore.hpp"

using namespace std;

struct Contato
{
    char nome[100];
    int telefone;
    int aniversario;

    Contato *dir, *esq, *raiz;
};

bool compara(char *nome1, char *nome2, int x)
{
    if(nome1[x] < nome2[x] || (nome1[x] == '\0' && nome2[x] != '\0') || (nome1[x] == ' ' && nome2[x] != ' '))
        return true;
    if(nome1[x] > nome2[x] || (nome1[x] != '\0' && nome2[x] == '\0') || (nome2[x] == ' ' && nome1[x] != ' '))
        return false;

    return compara(nome1, nome2, x + 1);
}

void Contato_inicia(Contato **praiz)
{
    *praiz = NULL;
}

Contato* contato_cria(char nome[100], int telefone, int aniversario)
{
    Contato *aux;
    aux = new Contato;

    strcpy(aux->nome, nome);
    aux->telefone = telefone;
    aux->aniversario = aniversario;

    aux->dir = NULL;
    aux->esq = NULL;

    return aux;
}

void imprimir(Contato *aux)
{
    cout << "Nome: " << aux->nome << endl << "Telefone: " << aux->telefone << endl << "Aniversario: " << aux->aniversario << endl;
}

bool buscar(Contato **aux, char nome[100])
{
    if((*aux) == NULL)
    {
        cout <<"Não existe !" << endl;
        return false;
    }

    else if(!strcmp(nome, (*aux)->nome))
    {
        imprimir((*aux));
        return true;
    }

    else if(compara((*aux)->nome, nome, 0))
        return buscar(&(*aux)->esq, nome);

    else
        return buscar(&(*aux)->dir, nome);

    return false;
}

bool inserir(Contato **aux, char nome[100], int telefone, int aniversario)
{
    if((*aux) == NULL)
    {
        (*aux) = contato_cria(nome, telefone, aniversario);

        return true;
    }

    if(compara((*aux)->nome, nome, 0))
    {
        return inserir(&((*aux)->esq), nome, telefone, aniversario);
    }
    else
    {
        return inserir(&((*aux)->dir), nome, telefone, aniversario);
    }
}

void retirar(Contato *dir, Contato **raiz)
{
  if((*raiz)->esq != NULL)
  {
    retirar(dir, &(*raiz)->esq);
    return;
  }

  dir = (*raiz);

  Contato *aux;

  aux = (*raiz);

  (*raiz) = (*raiz)->dir;

  delete aux;
}

bool retirar(Contato **p, char nome[100])
{
    if((*p) == NULL)
    {
        cout << "Não existe !" << endl;
        return false;
    }

    else if((*p)->dir == NULL && (*p)->esq == NULL)
    {
      delete *p;
      (*p) = NULL;
    }

    else if((*p)->dir != NULL && (*p)->esq == NULL)
    {
      Contato *aux;
      aux = *p;

      *p = (*p)->dir;

      delete aux;
    }

    else if((*p)->dir == NULL && (*p)->esq != NULL)
    {
      Contato *aux;
      aux = *p;

      *p = (*p)->esq;

      delete aux;
    }
    else
      retirar((*p), &((*p)->dir));

    return true;
}

void PosOrdem(Contato* c)
{
  if(c == NULL)
    return;

  PosOrdem(c->esq);
  PosOrdem(c->dir);

  cout <<"\nNome: " <<  c->nome << endl;
}

void PreOrdem(Contato* c)
{
  if(c == NULL)
    return;

  cout <<"\nNome: " <<  c->nome << endl;

  PosOrdem(c->esq);
  PosOrdem(c->dir);
}

void central(Contato* c)
{
  if(c == NULL)
    return;

  PosOrdem(c->esq);
  cout <<"\nNome: " <<  c->nome << endl;
  PosOrdem(c->dir);
}
