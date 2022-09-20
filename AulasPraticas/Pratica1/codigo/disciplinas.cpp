#include <iostream>
#include <cstring>
#include "disciplinas.hpp"

using namespace std;

struct Disciplinas
{
  string codigo_d, carga_horaria_d, curso_d, sala_d;
  char nome_d[50];
};


Disciplinas** aloca_d(int quant_d)
{
  Disciplinas** disciplina = new Disciplinas*[quant_d];

  for(int i = 0; i < quant_d; i++)
  {
    disciplina[i] = new Disciplinas;
  }

  return disciplina;
}

void desaloca_d(Disciplinas** disciplina,int quant_d)
{
  if(disciplina != NULL)
  {

    for(int i = 0; i < quant_d; i++)
    {
      if(disciplina[i] != NULL)
        delete disciplina[i];
    }
    delete [] disciplina;
  }
}

void inserir_d(Disciplinas** disciplina, int quant_inserir_d, int quant_inserir_auxd)
{
  for(int i = 0; i < quant_inserir_d; i++)
  {
        cout <<"\nDigite o nome da Disciplina " << quant_inserir_auxd +1 << " : ";
        cin >> disciplina[quant_inserir_auxd]->nome_d;

        cout <<"Digite a carga horária da Disciplina: ";
        cin >> disciplina[quant_inserir_auxd]->carga_horaria_d;

        cout <<"Digite o código da Disciplina: ";
        cin >> disciplina[quant_inserir_auxd]->codigo_d;

        cout <<"Digite a sala da Disciplina: ";
        cin >> disciplina[quant_inserir_auxd]->sala_d;

        cout <<"Digite o curso em que a Disciplina será dada: ";
        cin >> disciplina[quant_inserir_auxd]->curso_d;

        quant_inserir_auxd++;
  }
}

void deleta_d(Disciplinas** disciplina, char nome_dis[50], int&  quant_inserir_auxd)
{
  int posic = -1;

  for(int i = 0; i < quant_inserir_auxd; i++)
    if(!strcmp(disciplina[i]->nome_d, nome_dis))
      posic = i;

  if(posic != -1 )
  {
    *(disciplina[posic]) = *(disciplina[quant_inserir_auxd-1]);

    cout <<"\nDisciplina deletada com sucesso !" << endl;
    
    quant_inserir_auxd--;
  }

  else
    cout <<"\nDisciplina não encontrada !" << endl;
}


void atualizar_d(Disciplinas** disciplina,char nome_dis[50], int quant_inserir_auxd)
{
  int opcao, posic = -1;

  for(int i = 0; i < quant_inserir_auxd; i++)
    if(!strcmp(disciplina[i]->nome_d, nome_dis))
      posic = i;

  if(posic != -1 )
  {
        do
        {
          cout <<"\nDigite o dado que deseja atualizar: " << endl;
          cout <<"0- Sair" << endl << "1- Nome " << endl <<"2- Código" << endl;
          cout <<"3- Carga Horária " << endl <<"4- Curso" << endl;
          cout <<"5- Sala " << endl;

          cin >> opcao;

          switch(opcao)
          {
            case 0:

            break;

            case 1:

              cout <<"Digite o nome da Disciplina: ";
              cin >> disciplina[posic]->nome_d;

            break;

            case 2:

              cout <<"Digite o código da disciplina: ";
              cin >> disciplina[posic]->codigo_d;

            break;

            case 3:

              cout <<"Digite a carga horária da disciplina: ";
              cin >> disciplina[posic]->carga_horaria_d;

            break;

            case 4:

              cout <<"Digite o curso dem que a disciplina é dada: ";
              cin >> disciplina[posic]->curso_d;

            break;

            case 5:

              cout <<"Digite a sala da Disciplina: ";
              cin >> disciplina[posic]->sala_d;

            break;
          }
        }while(opcao !=0);
  }

  else
    cout <<"\nDisciplina não encontrada !" << endl;
}

void buscar_d(Disciplinas** disciplina, char nome_dis[50], int quant_inserir_auxd)
{

  int posic = -1;

  for(int i = 0; i < quant_inserir_auxd; i++)
    if(!strcmp(disciplina[i]->nome_d, nome_dis))
      posic = i;

  if(posic != -1 )
  {
    cout <<"\nNome da Disciplina: " << disciplina[posic]->nome_d << endl;
    cout <<"Código da Disciplina: "<< disciplina[posic]->codigo_d << endl;
    cout <<"Carga horária da Disciplina: " << disciplina[posic]->carga_horaria_d << endl;
    cout <<"Curso em que a Disciplina é dada: "<< disciplina[posic]->curso_d << endl;
    cout <<"Sala em que a disciplina é lecionada: "<< disciplina[posic]->sala_d << endl;
  }

  else
    cout <<"\nDisciplina não encontrada !" << endl;

}

void imprimir_d(Disciplinas** disciplina, int quant_inserir_auxd)
{
  for(int i = 0; i < quant_inserir_auxd; i++)
  {
    cout <<"\nNome da Disciplina: " << disciplina[i]->nome_d << endl;
    cout <<"Código da Disciplina: "<< disciplina[i]->codigo_d << endl;
    cout <<"Carga horária da Disciplina: " << disciplina[i]->carga_horaria_d << endl;
    cout <<"Curso em que a Disciplina é dada: "<< disciplina[i]->curso_d << endl;
    cout <<"Sala em que a disciplina é lecionada: "<< disciplina[i]->sala_d << endl;
      cout << endl;
  }
}

void info_disciplina()
{
  cout <<"\nDigite : " << endl;
  cout <<"0- Sair" << endl << "1- Inserir disciplina  " << endl <<"2- Remover disciplina" << endl;
  cout <<"3- Buscar disciplina " << endl <<"4- Atualizar disciplina" << endl;
  cout <<"5- Listar disciplina " << endl;
}
