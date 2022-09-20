#include <iostream>
#include "funcoes2.hpp"

using namespace std;

void preenche(int matriz[10][10])
{
  for(int i = 0; i < 10; i++)
    for(int j = 0; j < 10; j++)
      cin >> matriz[i][j];
}

void imprime(int matriz[10][10])
{
    for(int i = 0; i < 10; i++)
    {
      cout << i << " ";

      for(int j = 0; j < 10; j++)
      {
        if(i == 0 && j == 0)
        {
          cout <<"inicio ";
          matriz[i][j] = 3;
        }

        else
        {
            if(matriz[i][j] == 0 && (i !=9 || j !=9))
              cout <<"000 ";

            else if(matriz[i][j] == 1)
              cout <<"*** ";

            else if(matriz[i][j] == 2)
              cout <<"aqu ";

            if(i == 9 && j == 9)
              cout << "fim" << endl;
        }
      }
      cout << endl;
    }
}

void resolucao(int matriz[10][10], int linha, int coluna)
{

    if(linha == 9)
      cout << "\nfim" << endl;

    else
    {
      imprime(matriz);

      if(matriz[linha+1][coluna] == 0 && linha+1 != 10 && matriz[linha+1][coluna] != 2)
      {
        matriz[linha][coluna] = 2;

        linha++;

       resolucao(matriz, linha, coluna);
      }


      else if(matriz[linha][coluna+1] == 0 && coluna+1 != 10  && matriz[linha][coluna+1] != 2)
      {
          matriz[linha][coluna] = 2;
          coluna++;

          resolucao(matriz, linha, coluna);
      }

      else if(matriz[linha][coluna-1] == 0 && coluna-1 != -1  && matriz[linha][coluna-1] != 2)
      {
          matriz[linha][coluna] = 2;
          coluna--;

          resolucao(matriz, linha, coluna);
      }

      imprime(matriz);

    }

}
