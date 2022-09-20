#include <iostream>
#include <ctime>
#include <cstdlib>
#include <time.h>
#include "funcoes.hpp"

using namespace std;

#define MAX 100

void  vector_aleatorio(int vector[MAX])
{
  srand(time(NULL));

  	for(long long int i = 0; i < MAX; i++)
  		vector[i] = 1 + rand() % (MAX - 1) ;
}

void vector_crescente(int* vector)
{
  for(long long int i = 0; i < MAX; i++)
		vector[i] = i+1;
}

void vector_decrescente(int* vector)
{
  int j = 1;

  for(long long int i = MAX-1; i > 0; i--)
  {
		vector[i] = j;
    j++;
  }

}

void imprimir_vector (int* vector)
{
  for(long long int i = 0; i < MAX; i++)
    cout << vector[i] << " ";

  cout << endl << endl;
}

void bubblesort(int* vector, int tamanho, long long int& comp, long long int& mov)
{
	int aux;


	for (int i = 0; i < tamanho - 1; i++)
  {
      for (int j = (i+1); j < tamanho; j++)
      {
          comp++;

          if (vector[j] < vector[i])
          {

            mov++;
            aux = vector[i];
            vector[i] = vector[j];
            vector[j] = aux;
          }
      }
   }
}


void selectionSort(int* vector, int tamanho,long long int& comp, long long int& mov)
{
  int minimo, aux;

  for (int i = 0; i < (tamanho-1); i++)
  {
    minimo = i;

    for (int j = (i+1); j < tamanho; j++)
    {
      comp++;
     if(vector[j] < vector[minimo])
     {
       mov++;
       minimo = j;
     }
   }

   comp++;
   if (vector[i] != vector[minimo])
   {
     mov++;
     aux = vector[i];
     vector[i] = vector[minimo];
     vector[minimo] = aux;
   }
 }
}

void insertionsort(int* vector, int tamanho, long long int& comp, long long int& mov)
{
  for (int i = 1; i < tamanho; i++)
  {

			int aux = vector[i];
			int j = i;

      comp++;

			while ((j > 0) && (vector[j-1] > aux))
      {
        mov++;
				vector[j] = vector[j-1];
				j -= 1;

        comp++;
			}

      mov++;
			vector[j] = aux;
		}
}

void merge1(int* arr, int l, int m, int r, long long int& comp, long long int& mov)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    i = 0;
    j = 0;
    k = l;

    comp++;
    while (i < n1 && j < n2)
    {
        comp++;
        if (L[i] <= R[j])
        {
            mov++;
            arr[k] = L[i];
            i++;
        }
        else
        {
            mov++;
            arr[k] = R[j];
            j++;
        }
        k++;

      comp++;
    }

    comp++;

    while (i < n1)
    {
        mov++;
        arr[k] = L[i];
        i++;
        k++;

        comp++;
    }

    comp++;

    while (j < n2)
    {
        mov++;
        arr[k] = R[j];
        j++;
        k++;
    }

    comp++;
}

void mergeSort(int* arr, int l, int r, long long int& comp, long long int& mov)
{
    comp++;

    if (l < r)
    {

        int m = l+(r-l)/2;


        mergeSort(arr, l, m, comp, mov);
        mergeSort(arr, m+1, r, comp, mov);

        merge1(arr, l, m, r, comp, mov);
    }
}


void mergeSort_iterativo(int* arr, int n,long long int& comp, long long int& mov)
{
   int curr_size;

   int left_start;

   for (curr_size=1; curr_size<=n-1; curr_size = 2*curr_size)
   {

       for (left_start=0; left_start<n-1; left_start += 2*curr_size)
       {

           int mid = left_start + curr_size - 1;

           int right_end = min(left_start + 2*curr_size - 1, n-1);

           merge(arr, left_start, mid, right_end,comp, mov);
       }
   }
}


void merge(int* arr, int l, int m, int r, long long int& comp, long long int& mov)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    i = 0;
    j = 0;
    k = l;

    comp++;
    while (i < n1 && j < n2)
    {
        comp++;
        if (L[i] <= R[j])
        {
            mov++;
            arr[k] = L[i];
            i++;
        }
        else
        {
            mov++;
            arr[k] = R[j];
            j++;
        }
        k++;

      comp++;
    }

    comp++;
    while (i < n1)
    {
        mov++;
        arr[k] = L[i];
        i++;
        k++;

        comp++;
    }

    comp++;

    while (j < n2)
    {
        mov++;
        arr[k] = R[j];
        j++;
        k++;

        comp++;
    }
}

void shellSort(int* arr, int n, long long int& comp, long long int& mov)
{

    for (int a = n/2; a > 0; a /= 2)
    {
        comp++;

        for (int i = a; i < n; i += 1)
        {
            comp++;
            mov++;
            int temp = arr[i];


            int j;
            for (j = i; j >= a && arr[j - a] > temp; j -= a)
            {
              comp++;
              mov++;
                arr[j] = arr[j - a];
            }

            mov++;
            arr[j] = temp;
        }
    }
}

void troca(int* a, int* b, long long int& comp, long long int& mov)
{
    mov++;
    int t = *a;
    *a = *b;
    *b = t;
}

int particao(int* arr, int inferior, int superior, long long int& comp, long long int& mov)
{
    mov++;
    int pivo = arr[(superior+inferior)/2];
    int i = (inferior - 1);

    for (int j = inferior; j <= superior- 1; j++)
    {
        comp++;

        if (arr[j]   <= pivo)
        {
            comp++;

            i++;
            troca(&arr[i], &arr[j], comp, mov);
        }
    }
    troca(&arr[i + 1], &arr[superior], comp, mov);

    return (i + 1);
}

void quickSort(int* arr, int inferior, int superior, long long int& comp, long long int& mov)
{
    comp++;

    if (inferior < superior)
    {
        int p = particao(arr, inferior, superior, comp, mov);

        quickSort(arr, inferior, p - 1, comp, mov);
        quickSort(arr, p + 1, superior, comp, mov);
    }
}
