#ifndef FUNCOES_HPP
#define FUNCOES_HPP

void menu();//Menu onde encontra-se as opções para os ecercícios
int exe1_potencia(int base, int expoente);//Função que calcula potencia por recussão
int exe2_numero_invertido(int numero, int& aux1);//Função recursiva que inverte um número
int exe3_binario(int decimal, int& aux1);//Função recursiva que transforma um número binário em decimal
char exe4_menorel(char vetor[50], char& menor, int& aux2);//Função recursiva que acha o menor elemento de um vetor
char exe4_1_menorel(char vetor[50]);//Função interativa que acha o menor número de um vetor
int exe5_imprimir_naturais(int n, int auxn);//Função recursiva que imprime números naturais de 0 a n
void exe5_1_imprimir_naturais(int n);//Função interativa que imprime números naturais de 0 a n
int exe6_busca(char vet[100], char& chave, int ls, int li);//Função recursiva que retornar a posição de uma chave buscada em um vetor
int contar_elementos(char vet[100], int& aux4);//Função recursiva que retorna a quantidade de elementos de um vetor
int exe6__1_busca(char vet[100], char chave);//Função interativa que retornar a posição de uma chave buscada em um vetor

#endif
