#ifndef FUNCOES_HPP
#define FUNCOES_HPP
#define MAX 100

void  vector_aleatorio(int vector[MAX]);
void vector_crescente(int vector[MAX]);
void vector_decrescente(int vector[MAX]);
void imprimir_vector (int vector[MAX]);

void bubblesort(int* vector, int tamanho, long long int& comp, long long int& mov);
void selectionSort(int* vector, int tamanho, long long int& comp, long long int& mov);
void insertionsort(int* vector, int tamanho, long long int& comp, long long int& mov);
void merge1(int* arr, int l, int m, int r, long long int& comp, long long int& mov);
void mergeSort(int* arr, int l, int r, long long int& comp, long long int& mov);

void mergeSort_iterativo(int* arr, int n, long long int& comp, long long int& mov);
void merge(int* arr, int l, int m, int r, long long int& comp, long long int& mov);








#endif
