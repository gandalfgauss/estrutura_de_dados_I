#include <iostream>
#include <cstring>
#include "alunos.hpp"
using namespace std;

struct Alunos
{
  string nome_a, cpf_a, curso_a, ingresso_a;
  char matricula_a[50];
};


Alunos** aloca_a(int quant_a)
{
  Alunos** aluno = new Alunos*[quant_a];

  for(int i = 0; i < quant_a; i++)
  {
    aluno[i] = new Alunos;
  }

  return aluno;
}

void desaloca_a(Alunos** aluno, int quant_a)
{

  if(aluno != NULL)
  {


    for(int i = 0; i < quant_a; i++)
    {
      if(aluno[i] != NULL)
        delete aluno[i];
    }

    delete [] aluno;
  }
}

void inserir_a(Alunos** aluno, int quant_inserir_a, int quant_inserir_aux)
{
  for(int i = 0; i < quant_inserir_a; i++)
  {
        cout <<"\nDigite o nome do Aluno " << quant_inserir_aux +1 << " : ";
        cin >> aluno[quant_inserir_aux]->nome_a;

        cout <<"Digite o cpf do Aluno: ";
        cin >> aluno[quant_inserir_aux]->cpf_a;

        cout <<"Digite a matrícula do Aluno: ";
        cin >> aluno[quant_inserir_aux]->matricula_a;

        cout <<"Digite o curso do Aluno: ";
        cin >> aluno[quant_inserir_aux]->curso_a;

        cout <<"Digite a data de ingresso do Aluno: ";
        cin >> aluno[quant_inserir_aux]->ingresso_a;

        quant_inserir_aux++;
  }
}

void deleta_a(Alunos** aluno, char matricula_aluno_aux[50], int&  quant_inserir_aux)
{
  int posic = -1;


  for(int i = 0; i < quant_inserir_aux; i++)
    if(!strcmp(aluno[i]->matricula_a, matricula_aluno_aux))
      posic = i;

  if(posic != -1)
  {

    *(aluno[posic]) = *(aluno[(quant_inserir_aux-1)]);

    cout <<"\nAluno deletado com sucesso !" << endl;

    quant_inserir_aux--;

  }

  else
    cout <<"\nMatrícula não encontrada !" << endl;


}


void atualizar_a(Alunos** aluno,char matricula_aluno_aux[50], int quant_inserir_aux)
{
  int opcao, posic = -1;

  for(int i = 0; i < quant_inserir_aux; i++)
    if(!strcmp(aluno[i]->matricula_a, matricula_aluno_aux))
      posic = i;

  if(posic != -1 )
  {
        do
        {
          cout <<"\nDigite o dado que deseja atualizar: " << endl;
          cout <<"0- Sair" << endl << "1- Nome " << endl <<"2- CPF" << endl;
          cout <<"3- Matrícula " << endl <<"4- Curso" << endl;
          cout <<"5- Data de Ingresso " << endl;

          cin >> opcao;

          switch(opcao)
          {
            case 0:

            break;

            case 1:

              cout <<"Digite o nome do Aluno: ";
              cin >> aluno[posic]->nome_a;

            break;

            case 2:

              cout <<"Digite o cpf do Aluno: ";
              cin >> aluno[posic]->cpf_a;

            break;

            case 3:

              cout <<"Digite a matrícula do Aluno: ";
              cin >> aluno[posic]->matricula_a;

            break;

            case 4:

              cout <<"Digite o curso do Aluno: ";
              cin >> aluno[posic]->curso_a;

            break;

            case 5:

              cout <<"Digite a data de ingresso do Aluno: ";
              cin >> aluno[posic]->ingresso_a;

            break;
          }
        }while(opcao !=0);
  }

  else
    cout <<"\nAluno não encontrado !" << endl;
}

void buscar_a(Alunos** aluno, char matricula_aluno_aux[50], int quant_inserir_aux)
{

  int posic = -1;

  for(int i = 0; i < quant_inserir_aux; i++)
    if(!strcmp(aluno[i]->matricula_a, matricula_aluno_aux))
      posic = i;

  if(posic != -1 )
  {
    cout <<"\nNome do Aluno: " << aluno[posic]->nome_a << endl;
    cout <<"CPF do Aluno: "<< aluno[posic]->cpf_a << endl;
    cout <<"Matrícula do Aluno: " << aluno[posic]->matricula_a << endl;
    cout <<"Curso do Aluno: "<< aluno[posic]->curso_a << endl;
    cout <<"Data de Ingresso do Aluno: "<< aluno[posic]->ingresso_a << endl;
  }

  else
    cout <<"\nAluno não encontrado !" << endl;

}

void imprimir_a(Alunos** aluno, int quant_inserir_aux)
{
  for(int i = 0; i < quant_inserir_aux; i++)
  {
      cout <<"\nNome do Aluno: " << aluno[i]->nome_a << endl;
      cout <<"CPF do Aluno: "<< aluno[i]->cpf_a << endl;
      cout <<"Matrícula do Aluno: " << aluno[i]->matricula_a << endl;
      cout <<"Curso do Aluno: "<< aluno[i]->curso_a << endl;
      cout <<"Data de Ingresso do Aluno: "<< aluno[i]->ingresso_a << endl;
      cout << endl;
  }
}

void info_aluno()
{
  cout <<"\nDigite : " << endl;
  cout <<"0- Sair" << endl << "1- Inserir aluno " << endl <<"2- Remover aluno" << endl;
  cout <<"3- Buscar aluno " << endl <<"4- Atualizar aluno" << endl;
  cout <<"5- Listar alunos " << endl;
}
