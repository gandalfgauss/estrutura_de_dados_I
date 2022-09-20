#include <iostream>
#include "funcoes.hpp"

using namespace std;

#define MAX 100

int main()
{
  int vector_number, opcao;
  int *vector  = new int[MAX];
  long long int comp;
  long long int mov;

  clock_t tempo = 0;

  cout <<"\nDigite o número de vetores: ";
  cin >> vector_number;

  cout <<"\nDigite: \n1-Bubble Sort\n2-Selection Sort\n3-Insertion Sort\n4-Merge Sort Recurssivo\n5-Merge Sort Iterativo" << endl;

  for(int i = 0; i < vector_number; i++)
  {
    cin >> opcao;

    switch(opcao)
    {
      case 1:

        comp = 0;
        mov = 0;

        tempo = clock();

        vector_aleatorio(vector);
        bubblesort(vector, MAX, comp, mov);


        tempo = clock() - tempo;
				tempo = ((float)tempo) * 1000.0 / CLOCKS_PER_SEC;

        cout <<"Vetor aleatório" << endl;
        cout << "Tempo : " << tempo << " ms" << endl;
        cout <<"Comparações: " << comp << endl;
        cout <<"Movimentações: " << mov << endl << endl;

        comp = 0;
        mov = 0;

        tempo = clock();

        vector_crescente(vector);
        bubblesort(vector, MAX, comp, mov);


        tempo = clock() - tempo;
				tempo = ((float)tempo) * 1000.0 / CLOCKS_PER_SEC;

        cout <<"Vetor crescente" << endl;
        cout << "Tempo : " << tempo << " ms" << endl;
        cout <<"Comparações: " << comp << endl;
        cout <<"Movimentações: " << mov << endl << endl;

        comp = 0;
        mov = 0;

        tempo = clock();

        vector_decrescente(vector);
        bubblesort(vector, MAX, comp, mov);


        tempo = clock() - tempo;
        tempo = ((float)tempo) * 1000.0 / CLOCKS_PER_SEC;

        cout <<"Vetor decrescente" << endl;
        cout << "Tempo : " << tempo << " ms" << endl;
        cout <<"Comparações: " << comp << endl;
        cout <<"Movimentações: " << mov << endl << endl;

      break;

      case 2:

        comp = 0;
        mov = 0;

        tempo = clock();

        vector_aleatorio(vector);
        selectionSort(vector, MAX, comp, mov);


        tempo = clock() - tempo;
        tempo = ((float)tempo) * 1000.0 / CLOCKS_PER_SEC;

        cout <<"Vetor aleatório" << endl;
        cout << "Tempo : " << tempo << " ms" << endl;
        cout <<"Comparações: " << comp << endl;
        cout <<"Movimentações: " << mov << endl << endl;

        comp = 0;
        mov = 0;

        tempo = clock();

        vector_crescente(vector);
        selectionSort(vector, MAX, comp, mov);

        tempo = clock() - tempo;
        tempo = ((float)tempo) * 1000.0 / CLOCKS_PER_SEC;

        cout <<"Vetor crescente" << endl;
        cout << "Tempo : " << tempo << " ms" << endl;
        cout <<"Comparações: " << comp << endl;
        cout <<"Movimentações: " << mov << endl << endl;

        comp = 0;
        mov = 0;

        tempo = clock();

        vector_decrescente(vector);
        selectionSort(vector, MAX, comp, mov);


        tempo = clock() - tempo;
        tempo = ((float)tempo) * 1000.0 / CLOCKS_PER_SEC;

        cout <<"Vetor decrescente" << endl;
        cout << "Tempo : " << tempo << " ms" << endl;
        cout <<"Comparações: " << comp << endl;
        cout <<"Movimentações: " << mov << endl << endl;

      break;

      case 3:

          comp = 0;
          mov = 0;

          tempo = clock();

          vector_aleatorio(vector);
          insertionsort(vector, MAX, comp, mov);


          tempo = clock() - tempo;
          tempo = ((float)tempo) * 1000.0 / CLOCKS_PER_SEC;

          cout <<"Vetor aleatório" << endl;
          cout << "Tempo : " << tempo << " ms" << endl;
          cout <<"Comparações: " << comp << endl;
          cout <<"Movimentações: " << mov << endl << endl;

          comp = 0;
          mov = 0;

          tempo = clock();

          vector_crescente(vector);
          insertionsort(vector, MAX, comp, mov);

          tempo = clock() - tempo;
          tempo = ((float)tempo) * 1000.0 / CLOCKS_PER_SEC;

          cout <<"Vetor crescente" << endl;
          cout << "Tempo : " << tempo << " ms" << endl;
          cout <<"Comparações: " << comp << endl;
          cout <<"Movimentações: " << mov << endl << endl;

          comp = 0;
          mov = 0;

          tempo = clock();

          vector_decrescente(vector);
          insertionsort(vector, MAX, comp, mov);


          tempo = clock() - tempo;
          tempo = ((float)tempo) * 1000.0 / CLOCKS_PER_SEC;

          cout <<"Vetor decrescente" << endl;
          cout << "Tempo : " << tempo << " ms" << endl;
          cout <<"Comparações: " << comp << endl;
          cout <<"Movimentações: " << mov << endl << endl;

      break;

      case 4:

          comp = 0;
          mov = 0;

          tempo = clock();

          vector_aleatorio(vector);
          mergeSort(vector, 0, MAX, comp, mov);


          tempo = clock() - tempo;
          tempo = ((float)tempo) * 1000.0 / CLOCKS_PER_SEC;

          cout <<"Vetor aleatório" << endl;
          cout << "Tempo : " << tempo << " ms" << endl;
          cout <<"Comparações: " << comp << endl;
          cout <<"Movimentações: " << mov << endl << endl;

          comp = 0;
          mov = 0;

          tempo = clock();

          vector_crescente(vector);
          mergeSort(vector, 0, MAX, comp, mov);


          tempo = clock() - tempo;
          tempo = ((float)tempo) * 1000.0 / CLOCKS_PER_SEC;

          cout <<"Vetor crescente" << endl;
          cout << "Tempo : " << tempo << " ms" << endl;
          cout <<"Comparações: " << comp << endl;
          cout <<"Movimentações: " << mov << endl << endl;

          comp = 0;
          mov = 0;

          tempo = clock();

          vector_decrescente(vector);
          mergeSort(vector, 0, MAX, comp, mov);


          tempo = clock() - tempo;
          tempo = ((float)tempo) * 1000.0 / CLOCKS_PER_SEC;

          cout <<"Vetor decrescente" << endl;
          cout << "Tempo : " << tempo << " ms" << endl;
          cout <<"Comparações: " << comp << endl;
          cout <<"Movimentações: " << mov << endl << endl;
      break;

      case 5:

          comp = 0;
          mov = 0;

          tempo = clock();

          vector_aleatorio(vector);
          mergeSort_iterativo(vector,MAX, comp, mov);


          tempo = clock() - tempo;
          tempo = ((float)tempo) * 1000.0 / CLOCKS_PER_SEC;

          cout <<"Vetor aleatório" << endl;
          cout << "Tempo : " << tempo << " ms" << endl;
          cout <<"Comparações: " << comp << endl;
          cout <<"Movimentações: " << mov << endl << endl;

          comp = 0;
          mov = 0;

          tempo = clock();

          vector_crescente(vector);
          mergeSort_iterativo(vector,MAX, comp, mov);


          tempo = clock() - tempo;
          tempo = ((float)tempo) * 1000.0 / CLOCKS_PER_SEC;

          cout <<"Vetor crescente" << endl;
          cout << "Tempo : " << tempo << " ms" << endl;
          cout <<"Comparações: " << comp << endl;
          cout <<"Movimentações: " << mov << endl << endl;

          comp = 0;
          mov = 0;

          tempo = clock();

          vector_decrescente(vector);
          mergeSort_iterativo(vector,MAX, comp, mov);


          tempo = clock() - tempo;
          tempo = ((float)tempo) * 1000.0 / CLOCKS_PER_SEC;

          cout <<"Vetor decrescente" << endl;
          cout << "Tempo : " << tempo << " ms" << endl;
          cout <<"Comparações: " << comp << endl;
          cout <<"Movimentações: " << mov << endl << endl;

      break;

    }

  }



  return 0;
}
