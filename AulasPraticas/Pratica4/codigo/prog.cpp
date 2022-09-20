#include <iostream>
#include "funcoes.hpp"

using namespace std;

int main()
{
  int opcao, v;

  lista* l = lst_cria();

  cout <<"\nDigite\n0-Sair\n1-Inserir\n2-Inserir Ordenado\n3-Retira\n4-Vazia\n5-Pertence\n6-Imprime\n7-Insere Última Posição\n8-Retira Última Posição" << endl;

  do
  {
      cin >> opcao;

      switch(opcao)
      {
        case 1:

          cout <<"Digite um inteiro: ";
          cin >> v;

          lst_insere(l,v);

          cout <<"\nInserida com sucesso" << endl;

        break;

        case 2:

          cout <<"Digite um inteiro: ";
          cin >> v;

          lst_insere_ordenado(l, v);

          cout <<"Lista Ordenada Inserida" << endl;

        break;

        case 3:

          cout <<"Digite um inteiro" << endl;
          cin >> v;

          lst_retira(l, v);

          cout <<"Retirado com sucesso" << endl;

        break;

        case 4:

          v = lst_vazia(l);

          if(v == 1)
            cout <<"Lista vazia" << endl;

          else
            cout <<"Lista não vazia" << endl;

        break;

        case 5:

          cout <<"Digite um inteiro: ";

          cin >> v;
          v = lst_pertence(l,v);

          if(v == 1)
            cout <<"Elemento pertence a uma lista" << endl;

          else
            cout <<"Elemento não pertence a uma lista" << endl;

        break;

        case 6:

          lst_imprime(l);

        break;

      case 7:

          lst_insere_ultima_posicao(l);

          cout <<"Inserida com sucesso" << endl;

        break;

        case 8:

         v = lst_retira_ultima_posicao(l);

         if(v == 1)
          cout <<"Retirada com sucesso" << endl;

        else
         cout <<"Error" << endl;


        break;

      }
  }while(opcao != 0);

   lst_libera(l);

  return 0;
}
