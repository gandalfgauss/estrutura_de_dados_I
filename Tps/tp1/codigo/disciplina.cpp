#include "disciplina.hpp"
#include <iostream>
using namespace std;

//criando struct disciplina
struct disciplina
{
	string nome;
	string codigo;
	int cargaHoraria;
	string curso;
	string sala;
};
//funcao para alocar dinamicamente a struct disciplina
Disciplina* criarDisciplina()
{
	return new Disciplina;
}
//funcao para alocar o vetor de disciplinas dinamicamente
Disciplina** criarDisciplina(int TAM)
{
	Disciplina** aux = new Disciplina* [TAM];
	return aux;
}
//funcao para inserir os dados das disciplinas
Disciplina* inserirDadosDisciplina(string nome, string codigo, int carga, string curso, string sala)
{
	Disciplina *disciplina = criarDisciplina();
	disciplina->nome = nome;
	disciplina->codigo = codigo;
	disciplina->cargaHoraria = carga;
	disciplina->curso = curso;
	disciplina->sala = sala;

	return disciplina;
}
//funcao para validar se a carga horaria digitada eh 4 ou 8 horas
int validarCargaHoraria()
{
	bool flag = false;
	int carga;
	do
	{
		if(flag) cout << "\nCARGA HORARIA INVALIDA (4 ou 8 horas)\nDIGITE NOVAMENTE\n" << endl;
		cout << "CARGA HORARIA: ";
		cin >> carga;
		flag = true;
	}
	while(carga != 4 && carga != 8);
	return carga;
}
//funcao para retornar os dados da disciplina para outra TAD
void retornarDadosDisciplina(Disciplina *disciplina, string *nome, string *codigo, int *cargaHoraria, string *curso, string *sala)
{
	*nome = disciplina->nome;
	*codigo = disciplina->codigo;
	*cargaHoraria = disciplina->cargaHoraria;
	*curso = disciplina->curso;
	*sala = disciplina->sala;
}
//funcao que retorna o nome da disciplina e o codigo para outra TAD, para serem listados
void listarDisciplina(Disciplina *disciplina, string *nome, string *codigo)
{
	*nome = disciplina->nome;
	*codigo = disciplina->codigo;
}
//funcao para buscar o indice da disciplina, se nao encontrar, retorna -1
int buscarDisciplina(Disciplina **disciplina, string codigo, int TAM)
{
	for(int i = 0; i < TAM; i++)
	{
		if(disciplina[i]->codigo == codigo)
		{
			return i;
		}
	}
	return -1;
}
//funcao para remover o Professor do vetor
void removerDisciplina(Disciplina** disciplina, int inicio, int contDisciplina)
{
	for(int i = inicio; i < contDisciplina - 1; i++)
	{
		disciplina[i] = disciplina[i + 1];
	}
	liberarDisciplina(disciplina[contDisciplina]);
}
//funcao para desalocar a memoria da posicao do vetor do Professor
void liberarDisciplina(Disciplina *disciplina)
{
	delete disciplina;
}
//funcao para desalocar o vetor de professores
void liberarDisciplina(Disciplina **disciplina, int TAM)
{
	for(int i = 0; i < TAM; i++)
	{
		liberarDisciplina(disciplina[i]);
	}
	delete[] disciplina;
}
//funcao para retornar a struct disciplina para outra TAD
Disciplina* retornarDisciplina(Disciplina *disciplina)
{
	return disciplina;
}

void liberarDisciplinaTad(Disciplina **disciplina)
{//deletando o vetor de disciplinas alocado na struct atestado e encargos
	delete[] disciplina;
}

//funcao para retornar a carga horaria da disciplina para outra TAD
int retornarCarga(Disciplina *disciplina)
{
	return disciplina->cargaHoraria;
}
//funcao para retornar o codigo da disciplina para outra TAD
string retornarCodigo(Disciplina *disciplina)
{
	return disciplina->codigo;
}
//funcao para retornar o nome da disciplina para outra TAD
string retornaNomeDisciplina(Disciplina *disciplina)
{
	return disciplina->nome;
}
