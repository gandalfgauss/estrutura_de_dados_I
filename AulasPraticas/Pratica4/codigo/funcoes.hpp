#ifndef FUNCOES_HPP
#define FUNCOES_HPP

typedef struct Lista lista;
typedef struct Listano listano;

lista* lst_cria();
void lst_libera(lista* l);
void lst_insere(lista* l, int v);
void lst_imprime(lista* l);
void lst_insere_ordenado(lista* l, int v);
void lst_retira(lista* l, int v);
int lst_vazia(lista* l);
int lst_pertence(lista* l, int v);
void lst_insere_ultima_posicao(lista *l);
int lst_retira_ultima_posicao(lista *l);

#endif
