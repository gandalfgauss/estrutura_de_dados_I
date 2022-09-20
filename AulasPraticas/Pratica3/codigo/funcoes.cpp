#include <iostream>
#include "funcoes.hpp"
#include <cstdlib>

using namespace std;

void menu()//Menu onde encontra-se as opções para os ecercícios
{
    int opcao, base, expoente, numero, aux1 = 1, decimal, aux2 = 0, n, auxn = 0, aux4, posic, ls, li;
    char vetor[50], menor, vet[100], chave;

    do
    {
        cout <<"\nDigite uma opção: ";
        cin >> opcao;//Lê a opção do exercício

        switch(opcao)
        {
            case 1:

                cout <<"\nDigite a base e o expoente: ";
                cin >> base >> expoente;

                cout << base <<"^" << expoente << ": " << exe1_potencia(base, expoente) << endl;

            break;

            case 2:

                cout <<"\nDigite um número: ";
                cin >> numero;

                cout <<"\nInvertido: " << exe2_numero_invertido(numero, aux1) << endl;

            break;

            case 3:

              cout <<"\nDigite um número : ";
              cin >> decimal;

              cout <<"\nO número " << decimal <<" em binário é: " << exe3_binario(decimal, aux1) << endl  ;

            break;

            case 4:

              cout <<"\nDigite um vetor : ";
              cin >> vetor;

              menor = vetor[0];

              cout <<"\nO menor número do vetor é: " << exe4_menorel(vetor, menor, aux2) << endl;//Chama a função com o menor valendo o vetor na posição 0

            break;

            case 5:

              cout <<"\nDigite um vetor : ";
              cin >> vetor;

              cout <<"\nO menor número do vetor é: " << exe4_1_menorel(vetor) << endl;

            break;

            case 6:

              cout <<"\nDigite um número: ";
              cin >> n;

              exe5_imprimir_naturais(n, auxn);

            break;

            case 7:

              cout <<"\nDigite um número: ";
              cin >> n;

              exe5_1_imprimir_naturais(n);

            break;

            case 8:

              aux4 = 0;//para evitar erros ao passar como referência, ao executar novamente o exercício

              cout <<"\nDigite um vetor: ";
              cin >> vet;

              cout <<"\nDigite uma chave: ";
              cin >> chave;

              ls = contar_elementos(vet, aux4);
              li = 0;

              posic =  exe6_busca(vet, chave,ls, li);//posição vai receber a posição da chave encontrada

              if(posic != -1)//se for diferente de -1 imprimi a posição do vetor onde ela se encontra
                cout <<"\nA chave " << chave << " está na posição : " << posic << endl;

              else//se for igual a -1 não achou
                cout <<"\nChave não encontrada !" << endl;

            break;

            case 9:

              cout <<"\nDigite um vetor: ";
              cin >> vet;

              cout <<"\nDigite a chave: ";
              cin >> chave;

              posic = exe6__1_busca(vet,chave);//posição vai receber a posição da chave encontrada

              if(posic != -1)//se for diferente de -1 imprimi a posição do vetor onde ela se encontra
                cout <<"\nA chave " << chave << " está na posição : " << posic << endl;

              else// se for igual a -1 não achou
                cout <<"\nChave não encontrada !" << endl;

            break;

        }

    }while(opcao != 0);
}

int exe1_potencia(int base, int expoente)//Função que calcula potencia por recussão
{
    if(expoente == 1)
        return base;

    base *= exe1_potencia(base,expoente-1);//Chama a mesma função decrementando no expoente

    return base;
}

int exe2_numero_invertido(int numero, int& aux1)//Função recursiva que inverte um número
{
    if(numero/10 == 0)
    {
      aux1 = 1;
      return numero;
    }

    numero = exe2_numero_invertido(numero/10, aux1) + numero%10*exe1_potencia(10,aux1);//Função potência é chamada por que a cada retorno de função o numero deve ser multiplicado por 10^n

    aux1++;

    return numero;
}

int exe3_binario(int decimal, int& aux1)//Função recursiva que transforma um número binário em decimal
{
  if(decimal <  2)
  {
    aux1 = 1;
    return decimal;
  }

  decimal = exe3_binario(decimal/2, aux1)*exe1_potencia(10,aux1) + decimal%2;//O número decimal é formado pelo rsultado do cálculo(divisões por 2)de trás para frente sempre multiplicando por 10 mais o resto de cada divisão

  return decimal;
}

char exe4_menorel(char vetor[50], char& menor, int& aux2)//Função recursiva que acha o menor elemento de um vetor
{
  aux2++;

  if(vetor[aux2] != '\0' && vetor[aux2] < menor)
     menor = vetor[aux2];

  if(vetor[aux2] == '\0')
     return menor;

  exe4_menorel(vetor,menor,aux2);//Função vai ser chamada enquanto não achar o barra 0

  return menor;
}

char exe4_1_menorel(char vetor[50])//Função interativa que acha o menor número de um vetor
{
    int aux = 0, menor = vetor[0];

    while(vetor[aux] != '\0')
    {
      if(vetor[aux] < menor)//Se achar um elemento menor do que o vetor na posição 0, a variável menor receber esse número menor
        menor = vetor[aux];

      aux++;
    }

    return menor;
}

int exe5_imprimir_naturais(int n, int auxn)//Função recursiva que imprime números naturais de 0 a n
{
    if(auxn <= n )
        cout << auxn << " ";

    else
      return auxn;

    exe5_imprimir_naturais(n, auxn+1);//sempre soma 1 no aux e chama a função enquanto for menor igual ao número digitado pelo usuário

    return auxn;
}

void exe5_1_imprimir_naturais(int n)//Função interativa que imprime números naturais de 0 a n
{
    for(int i = 0; i <= n; i++)//Um for que imprime i começando de 0 até o número digitado pelo usuário
      cout << i << " ";
}

int exe6_busca(char vet[100], char& chave, int ls, int li)//Função recursiva que retornar a posição de uma chave buscada em um vetor
{

  int metade = (li + ls)/2;

  if (vet[metade] == chave)
    return metade;

 if (li >= ls)
    return -1;

 else
     if (vet[metade] < chave)
        return exe6_busca(vet, chave, ls, metade+1);

     else
        return exe6_busca(vet, chave, metade-1, li);

}

int contar_elementos(char vet[100], int& aux4)//Função recursiva que retorna a quantidade elementos de um vetor
{

  if(vet[aux4] != '\0')
      aux4++;

  else
     return aux4;

  contar_elementos(vet,aux4);//soma um no contador aux4 e chama a função novamente equanto não achar o bara 0

  return aux4;
}

int exe6__1_busca(char vet[100], char chave)//Função interativa que retornar a posição de uma chave buscada em um vetor
{
  int tamanho = 0, metade, superior, inferior = 0;

  while(vet[tamanho] != '\0')//conta a quantidade de variáveis de um vetor e armazena em tamanho
    tamanho++;

  superior = tamanho;

  while (inferior <= superior)//Loop para achar a chave
  {
      metade = (inferior + superior)/2;

      if (chave == vet[metade])
          return metade;

      if (chave < vet[metade])
           superior = metade-1;

      else
        inferior = metade+1;
  }

  return -1;
}
