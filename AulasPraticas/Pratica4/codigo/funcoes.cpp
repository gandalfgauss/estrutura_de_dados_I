#include <iostream>
#include "funcoes.hpp"

using namespace std;

struct Listano
{
  int info;
  listano* prox;
};

struct Lista
{
  listano* prim;
  listano* ultm;
};

lista* lst_cria()
{

    lista* l = new lista;

    l->prim = NULL;
    l->ultm = NULL;

    cout <<"\nLista criada !" << endl;

    return l;
}

void lst_libera(lista* l)
{
  listano* p = l->prim;

  while(p != NULL)
  {
    listano* aux = p->prox;

    delete p;

    p = aux;
  }
  delete l;

  cout <<"Lista deletada !" << endl;
}

void lst_insere(lista* l, int v)
{
  listano* novo = new listano;

  novo->info = v;

  novo->prox = l->prim;

  l->prim = novo;
}

void lst_imprime(lista* l)
{
  for(listano* aux = l->prim; aux != NULL; aux = aux->prox)
    cout << aux->info <<" ";

    cout << endl;
}

void lst_insere_ordenado(lista* l, int v)
{
  listano* ant = NULL;
  listano* p = l->prim;

  while(p != NULL && p->info < v)
  {
    ant = p;
    p = p->prox;
  }

  listano* novo = new Listano;
  novo->info = v;

  if(ant == NULL)
  {
    novo->prox = l->prim;
    l->prim = novo;
  }

  else
  {
    novo->prox = ant->prox;
    ant->prox = novo;
  }
}

void lst_retira(lista* l, int v)
{
  listano* ant = NULL;
  listano* p = l->prim;

  while(p != NULL && p->info != v)
  {
    ant = p;
    p = p->prox;
  }

  if(p != NULL)
  {
    if(ant == NULL)
    {
      l->prim = p->prox;
    }

    else
    {
      ant->prox = p->prox;
    }

    delete p;
  }
}

int lst_vazia(lista* l)
{
  if(l->prim == NULL)
    return 1;

  return 0;
}

int lst_pertence(lista* l, int v)
{
  for(listano* aux = l->prim; aux != NULL; aux = aux->prox)
  {
    if(aux->info == v)
      return 1;
  }
  return 0;
}



void lst_insere_ultima_posicao(lista *l)
{
  for(listano* aux = l->prim; aux != NULL; aux = aux->prox)
  {
    if(aux->prox == NULL)
    {
      listano* novo = new listano;
      
      novo->prox = NULL;
      aux->prox = novo->prox;
      l->ultm =  novo->prox;
    }
  }
}

int lst_retira_ultima_posicao(lista *l)
{

  listano* depois;

  for(listano* aux = l->prim; aux != NULL; aux = aux->prox)
  {
    depois = aux->prox;

    if(depois->prox == NULL)
    {
       l->ultm = aux->prox;

       depois = depois->prox;

       delete depois;

       aux->prox = NULL;

       return 1;
    }
  }

  return 0;
}
