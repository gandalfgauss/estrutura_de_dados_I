#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdio>
#include "menu.hpp"
#include "aluno.hpp"
#include "professor.hpp"
#include "disciplina.hpp"
#include "atestadoMatricula.hpp"
#include "funcoes2.hpp"
#include "funcoes3.hpp"

#define MAX 1000 //definindo um valor maximo para a alocacao dinamica

using namespace std;



int main()
{

	int opcao_geral = -1, base , expoente, matriz[10][10], linha = 0, coluna = 0;

	Aluno** aluno,**ptrAluno;
	Professor** professor,**ptrProfessor;
	Disciplina** disciplina,**ptrDisciplina;
	Atestado** atestado,**ptrAtestado;
	Encargo** encargo,**ptrEncargo;
	int opcao, contAluno = 0, contProfessor = 0, contDisciplina = 0, contAtestado = 0,contEncargo=0;

	aluno = criarAluno(MAX);
	professor = criarProfessor(MAX);
	disciplina = criarDisciplina(MAX);
	atestado = criarAtestado(MAX);
	encargo = criarEncargo(MAX);

	ptrAluno=aluno;
	ptrProfessor=professor;
	ptrDisciplina=disciplina;
	ptrAtestado=atestado;
	ptrEncargo=encargo;

	while(opcao_geral != 0)
	{
		cout <<"\nDigite o número do exercício: ";
		cin >> opcao_geral;

		switch(opcao_geral)
		{
			case 1:

				do
				{
					opcao = menuInicial();
					switch(opcao)
					{
					case 1:
						menuAluno(aluno, atestado, contAluno, contAtestado);
						break;
					case 2:
						menuProfessor(professor, encargo, contProfessor, contEncargo);
						break;
					case 3:
						menuDisciplina(disciplina,atestado,encargo,contEncargo,contAtestado, contDisciplina);
						break;
					case 4:
						menuAtestadoMatricula(atestado, aluno, disciplina, contAluno, contDisciplina, contAtestado);
						break;
					case 5:
						menuEncargoProfessor(encargo,professor,disciplina,contProfessor,contDisciplina,contEncargo);
						break;
					case 0:
						break;
					default:
						cout << "\nOPCAO INVALIDA!" << endl;
						cout << "DIGITE NOVAMENTE!\n" << endl;
					}
				}
				while(opcao);

			 break;

			 case 2:

						  cout <<"Digite: \n0 para espaço \n1 para parede" << endl;

							preenche(matriz);
							imprime(matriz);

							resolucao(matriz, linha, coluna);

			 break;

			 case 3:

					 	cout <<"\nDigite a base e o expoente: ";
						cin >> base >> expoente;

						base = potenciacao(base,expoente);

						cout <<"Resultado: " << base;

			 break;
			}
		}

	liberarAluno(ptrAluno, contAluno);
	liberarProfessor(ptrProfessor, contProfessor);
	liberarDisciplina(ptrDisciplina, contDisciplina);
	liberarAtestado(ptrAtestado, contAtestado);
	liberarEncargo(ptrEncargo, contEncargo);
}
