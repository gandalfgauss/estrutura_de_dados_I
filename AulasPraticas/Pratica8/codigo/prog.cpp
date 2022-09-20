#include <iostream>
#include "arvore.hpp"
#include <cstdlib>

using namespace std;

int main()
{
  int opcao;
  Contato *c;
  char nome[100];
  int telefone;
  int aniversario;

  Contato_inicia(&(c));

  do
  {

    cout <<"\nDigite:\n0-Sair\n1-Criar\n2-Buscar\n3-Remover\n4-Caminhamento Pré-Ordem\n5-Caminhamento Pós-Ordem\n6-Caminhamento Central" << endl;

    cin >> opcao;

    switch (opcao)
    {
      case 1:
      {
        cout <<"Digite o nome do contato: ";
        cin >> nome;

        cout <<"Digite o numero de telefone e o aniversário: ";
        cin >> telefone >> aniversario;

        inserir(&(c), nome, telefone, aniversario);
      }
        break;

      case 2:
      {
        cout << "Digite o nome do contato: ";
          cin >> nome;

        buscar(&(c), nome);
      }
        break;

      case 3:
      {
        cout << "Digite o nome do contato: ";
          cin >> nome;

        retirar(&(c), nome);
      }
      break;

      case 4:

        PreOrdem(c);

      break;

      case 5:

         PosOrdem(c);

      break;

      case 6:

        central(c);

      break;
    }
  }while(opcao != 0);

return 0;
}
