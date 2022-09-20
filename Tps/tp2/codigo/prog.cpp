#include <iostream>
#include "funcoes.hpp"

using namespace std;

int main()
{
  int exercicio, exe1, mes, lim_e, lim_d, exe3, codigo,cod;
  int id, n_obj, num_func = 6;
  Fila* f;
  Func* funcionario;
  ListaP* lista;
  string nome;


  do
  {

      cout <<"\nDigite o número de um exercício: \n0-Sair\n1-Exercício 1\n2-Exercício 2\n3-Exercício 3\n";
      cin >> exercicio;

      switch(exercicio)
      {
        case 0:
        break;

        case 1:

          f = cria_fila();

          do
          {
            cout <<"\n0-Sair\n1-Inserir\n2-Remover\n3-Calcular Área\n4-Imprime Objetos\n5-Atualizar Objeto" << endl;
            cin >> exe1;

            switch(exe1)
            {
              case 1:

                cout <<"\nIserir:\n1-Circulo\n2-Retângulo\n3-Triângulo" << endl;
                cin >> id;

                cria_e_insere(f, id);

              break;

              case 2:

                if(remover(f))
                  cout <<"\nRemovida com sucesso" << endl;

                else
                  cout <<"\nFila vazia" << endl;

              break;

              case 3:

                if(fila_vazia(f))
                  cout <<"\nFila vazia" << endl;

                else
                  calcula_area(f);

              break;

              case 4:

                  if(fila_vazia(f))
                    cout <<"\nFila vazia" << endl;

                  else
                    imprime_obj(f);

              break;

              case 5:

                  if(fila_vazia(f))
                    cout <<"\nFila vazia" << endl;

                  else
                  {
                    cout <<"\nDigite o número da Figura: ";
                    cin >> n_obj;

                    atualiza(f, n_obj);
                  }

              break;
            }
          }while(exe1 != 0);

          libera_fila(f);

        break;

        case 2:

          lista = cria_lista();

          do
          {
            cout <<"\nDigite\n0-Sair\n1-Inserir Pratos e ingredientes\n2-Imprimir lista completa\n3-Imprimir Ingredientes de um prato\n4-Apagar um prato\n5-Adicionar um ingrediente\n6-Deletar ingrediente\n";
            cin >> exe3;

            switch(exe3)
            {
              case 0:
              break;

              case 1:

                    cout <<"Digite o código do prato que deseja inserir: ";
                    cin >> codigo;

                    cout <<"Digite o nome do prato que deseja inserir: ";
                    cin >> nome;

                  insere_prato(lista, codigo,nome);

              break;

              case 2:

                if(lista_prato_vazia(lista))
                  cout <<"\nLista vazia !" << endl;

                else
                  lista_completa(lista);

              break;

              case 3:

                if(lista_prato_vazia(lista))
                  cout <<"\nLista vazia !" << endl;

                else
                {
                  cout <<"\nDigite o código do prato que deseja buscar: ";
                  cin >> codigo;

                  imprime_prato_ingredientes(lista,codigo);
                }
              break;

              case 4:

                  if(lista_prato_vazia(lista))
                    cout <<"\nLista vazia !" << endl;

                  else
                  {
                    cout <<"\nDigite o código do prato que deseja deletar: ";
                    cin >> codigo;

                    if(apagar_prato(lista,codigo))
                    {
                      cout <<"\nRemovido com sucesso" << endl;
                    }

                    else
                    {
                      cout <<"\nCódigo não existe" << endl;
                    }
                  }

              break;

              case 5:

                  if(lista_prato_vazia(lista))
                    cout <<"\nLista vazia !" << endl;

                  else
                  {
                    cout <<"\nDigite o código do prato que deseja acrescentar um ingrediente: ";
                    cin >> codigo;

                    cout <<"\n\nDigite o código do ingrediente que deseja adicionar: ";
                    cin >> cod;

                    cout <<"\nDigite o nome do ingrediente que deseja adicionar: ";
                    cin >> nome;

                    adicionar_ingrediente(lista, codigo, nome, cod);

                  }
              break;

              case 6:

                  if(lista_prato_vazia(lista))
                    cout <<"\nLista vazia !" << endl;

                  else
                  {
                    cout <<"\nDigite o código do prato que deseja deletar um ingrediente: ";
                    cin >> codigo;

                    cout <<"\nDigite o nome do ingrediente que deseja deletar: ";
                    cin >> nome;


                    deletar_ingrediente(lista, codigo, nome);

                  }

              break;

              libera(lista);
            }

          }while(exe3 != 0);

        break;

        case 3:

          funcionario = cria_func(num_func);
          define_func(funcionario);
          imprime_func(funcionario, num_func);
          QuickSort_iter(funcionario, num_func);
          cout <<"\nOrdenou " << endl << endl;
          imprime_func(funcionario, num_func);

          cout <<"\nDigite o mês que deseja consultar " << endl;
          cin >> mes;


          if(busca(funcionario, mes, num_func, lim_e, lim_d) == -1)
            cout <<"\nNão encontrado " << endl;

          else
          {
            cout << "Aniversariantes do mês " << mes << ": ";

            niver(funcionario,lim_e, lim_d);
          }

        break;
      }
    }while(exercicio != 0);

  return 0;
}
