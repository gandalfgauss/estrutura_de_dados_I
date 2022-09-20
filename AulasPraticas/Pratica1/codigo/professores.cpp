#include <iostream>
#include <cstring>
#include "professores.hpp"

using namespace std;

struct Professores
{
  string cpf_p, depa_p;
  char nome_p[50];
};


Professores** aloca_p(int quant_p)
{
  Professores** professor = new Professores*[quant_p];

  for(int i = 0; i < quant_p; i++)
  {
    professor[i] = new Professores;
  }

  return professor;
}

void desaloca_p(Professores** professor,int quant_p)
{

  if(professor != NULL)
  {
    for(int i = 0; i < quant_p; i++)
    {
      if(professor[i] != NULL)
        delete professor[i];
    }

    delete [] professor;
  }
}

void inserir_p(Professores** professor, int quant_inserir_p, int quant_inserir_auxp)
{
  for(int i = 0; i < quant_inserir_p; i++)
  {
        cout <<"\nDigite o nome do Professor " << quant_inserir_auxp +1 << " : ";
        cin >> professor[quant_inserir_auxp]->nome_p;

        cout <<"Digite o cpf do Professor: ";
        cin >> professor[quant_inserir_auxp]->cpf_p;

        cout <<"Digite o Departamento do Professor: ";
        cin >> professor[quant_inserir_auxp]->depa_p;

        quant_inserir_auxp++;
  }
}

void deleta_p(Professores** professor, char nome_prof[50], int&  quant_inserir_auxp)
{
  int posic = -1;

  for(int i = 0; i < quant_inserir_auxp; i++)
    if(!strcmp(professor[i]->nome_p, nome_prof))
      posic = i;

  if(posic != -1 )
  {
    *(professor[posic]) = *(professor[quant_inserir_auxp-1]);

    cout <<"\nProfessor deletado com sucesso !" << endl;

    quant_inserir_auxp--;
  }

  else
    cout <<"\nProfessor não encontrado !" << endl;

  
}


void atualizar_p(Professores** professor,char nome_prof[50], int quant_inserir_auxp)
{
  int opcao, posic = -1;

  for(int i = 0; i < quant_inserir_auxp; i++)
    if(!strcmp(professor[i]->nome_p, nome_prof))
      posic = i;

  if(posic != -1 )
  {
        do
        {
          cout <<"\nDigite o dado que deseja atualizar: " << endl;
          cout <<"0- Sair" << endl << "1- Nome " << endl <<"2- CPF" << endl;
          cout <<"3- Depatarmento " << endl;

          cin >> opcao;

          switch(opcao)
          {
            case 0:

            break;

            case 1:

              cout <<"Digite o nome do Professor: ";
              cin >> professor[posic]->nome_p;

            break;

            case 2:

              cout <<"Digite o cpf do Professor: ";
              cin >> professor[posic]->cpf_p;

            break;

            case 3:

              cout <<"Digite o departamento do Professor: ";
              cin >> professor[posic]->depa_p;

            break;
          }
        }while(opcao !=0);
  }

  else
    cout <<"\nProfessor não encontrado !" << endl;
}

void buscar_p(Professores** professor, char nome_prof[50], int quant_inserir_auxp)
{

  int posic = -1;

  for(int i = 0; i < quant_inserir_auxp; i++)
    if(!strcmp(professor[i]->nome_p, nome_prof))
      posic = i;

  if(posic != -1 )
  {
    cout <<"\nNome do Professor: " << professor[posic]->nome_p << endl;
    cout <<"CPF do Professor: "<< professor[posic]->cpf_p << endl;
    cout <<"Departamento do Professor: " << professor[posic]->depa_p << endl;
  }

  else
    cout <<"\nProfessor não encontrado !" << endl;

}

void imprimir_p(Professores** professor, int quant_inserir_auxp)
{
  for(int i = 0; i < quant_inserir_auxp; i++)
  {
    cout <<"\nNome do Professor: " << professor[i]->nome_p << endl;
    cout <<"CPF do Professor: "<< professor[i]->cpf_p << endl;
    cout <<"Departamento do Professor: " << professor[i]->depa_p << endl;
      cout << endl;
  }
}

void info_professor()
{
  cout <<"\nDigite : " << endl;
  cout <<"0- Sair" << endl << "1- Inserir professor " << endl <<"2- Remover professor" << endl;
  cout <<"3- Buscar professor " << endl <<"4- Atualizar professor" << endl;
  cout <<"5- Listar professores " << endl;
}
