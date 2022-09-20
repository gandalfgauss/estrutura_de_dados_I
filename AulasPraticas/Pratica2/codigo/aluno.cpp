#include "aluno.hpp"
#include "atestadoMatricula.hpp"
#include <iostream>
using namespace std;

//criando struct aluno
struct aluno
{
	string nome;
	string cpf;
	string matricula;
	string curso;
	string dataIngresso;
};
//funcao para alocar dinamicamente a struct aluno
Aluno* criarAluno()
{
	return new Aluno;
}
//funcao para alocar o vetor de alunos dinamicamente
Aluno** criarAluno(int TAM)
{
	Aluno** aux = new Aluno* [TAM];
	return aux;
}
//funcao que recebe os dados do aluno de outra TAD e coloca na struct Aluno
Aluno* inserirDadosAluno(string nome, string cpf, string matricula, string curso, string data)
{
	Aluno *aluno = criarAluno();
	aluno->nome = nome;
	aluno->cpf = cpf;
	aluno->matricula = matricula;
	aluno->curso = curso;
	aluno->dataIngresso = data;

	return aluno;
}
//funcao para retornar os dados do aluno para outra TAD
void retornarDadosAluno(Aluno *aluno, string *nome, string *cpf, string *matricula, string *curso, string *data)
{
	*nome = aluno->nome;
	*cpf = aluno->cpf;
	*matricula = aluno->matricula;
	*curso = aluno->curso;
	*data = aluno->dataIngresso;
}

//funcao que recebe os dados do aluno de outra TAD e altera na struct Aluno
void alterarDadosAluno(Aluno* aluno, string nome, string cpf, string matricula, string curso, string data)
{
	aluno->nome = nome;
	aluno->cpf = cpf;
	aluno->matricula = matricula;
	aluno->curso = curso;
	aluno->dataIngresso = data;
}
//funcao para buscar o indice do aluno, se nao encontrar, retorna -1
int buscarAluno(Aluno **aluno, string matricula, int TAM)
{
	for(int i = 0; i < TAM; i++)
	{
		if(aluno[i]->matricula == matricula)
		{
			return i;
		}
	}
	return -1;
}
//funcao para remover o Aluno do vetor
void removerAluno(Aluno** aluno, int inicio, int &contAluno)
{
	for(int i = inicio; i < contAluno - 1; i++)
	{
		aluno[i] = aluno[i + 1];
	}
	liberarAluno(aluno[contAluno]);
	contAluno--;
}
//funcao que retorna o nome e a matricula para outra TAD, para serem listados
void listarAluno(Aluno *aluno, string *nome, string *matricula)
{
	*nome = aluno->nome;
	*matricula = aluno->matricula;
}
//funcao para desalocar dinamicamente a posicao do vetor de alunos
void liberarAluno(Aluno *aluno)
{
	delete aluno;
}
//funcao para desalocar o vetor de alunos
void liberarAluno(Aluno **aluno, int TAM)
{
	for(int i = 0; i < TAM; i++)
	{
		liberarAluno(aluno[i]);
	}
	delete[] aluno;
}
//funcao para retornar a matricula para outra TAD
string retornaMatricula(Aluno *aluno)
{
	return aluno->matricula;
}
//funcao para retornar a struct aluno para outra TAD
Aluno* retornarAluno(Aluno* aluno)
{
	return aluno;
}
//funcao para retornar o nome do aluno para outra TAD
string retornaNomeAluno(Aluno *aluno)
{
	return aluno->nome;
}
