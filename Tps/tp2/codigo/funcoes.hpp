#include <iostream>
#include <cstring>
#include <string>

using namespace std;

#ifndef FUNCOES_HPP
#define FUNCOES_HPP

typedef struct Circ circ;
typedef struct Ret ret;
typedef struct Tri tri;

typedef struct Func func;
typedef struct PilhaNo pilhano;
typedef struct Pilha pilha;

typedef struct FilaNo filano;
typedef struct Fila fila;

typedef struct ListaPNo listapratono;
typedef struct ListaP listaprato;

typedef struct ListaINo listaingredienteno;
typedef struct ListaI listaingrediente;

Fila* cria_fila();
void libera_fila(Fila* f);
int fila_vazia(Fila* f);

void cria_e_insere(Fila* f, int id);
int remover(Fila* f);
void calcula_area(Fila* f);
void imprime_obj(Fila* f);
void atualiza(Fila* f, int n);

Pilha* cria_pilha();
void pilha_push(Pilha* p, int v);
void pilha_pop(Pilha* p);
int pilha_vazia(Pilha* p);
void deleta_pilha(Pilha* p);

Func* cria_func(int n);
void define_func(Func* f);
void imprime_func(Func* f, int n);

void QuickSort_particao(Func *v, int esq , int dir , int *i, int *j);
void QuickSort_iter(Func *v, int n);
void quick_dia(Func* f, int n);
void quick_nome(Func* f, int n);

int busca(Func* vet, int chave, int Tam, int& lim_e, int& lim_d);
void niver(Func* vet, int lim_e, int lim_d);

ListaP* cria_lista();
int lista_prato_vazia(ListaP* pratos);
void insere_prato(ListaP* pratos, int codigo, string nome);
int apagar_prato(ListaP* pratos, int codigo);
void imprime_prato_ingredientes(ListaP* pratos, int codigo);
void adicionar_ingrediente(ListaP* pratos, int codigo, string nom, int cod);
void deletar_ingrediente(ListaP* pratos, int codigo, string nome);
void lista_completa(ListaP* pratos);
void libera(ListaP* pratos);




#endif
