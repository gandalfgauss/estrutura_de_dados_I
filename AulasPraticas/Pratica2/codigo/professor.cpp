#include "professor.hpp"
using namespace std;
#include <iostream>

//criando struct professor
struct professor
{
	string nome;
	int siape;
};
//funcao para alocar dinamicamente a struct professor
Professor* criarProfessor()
{
	return new Professor;
}
//funcao para alocar o vetor de professores dinamicamente
Professor** criarProfessor(int TAM)
{
	Professor** aux = new Professor* [TAM];
	return aux;
}
//funcao para inserir os dados dos alunos
Professor* inserirDadosProfessor(string nome, int siape)
{
	Professor *professor = criarProfessor();
	professor->nome = nome;
	professor->siape = siape;

	return professor;
}
//funcao para retornar os dados do professor para outra TAD
void retornarDadosProfessor(Professor *professor, string *nome, int *siape)
{
	*nome = professor->nome;
	*siape = professor->siape;
}
//funcao que retorna o nome e o siape para outra TAD, para serem listados
void listarProfessor(Professor *professor, string *nome, int *siape)
{
	*nome = professor->nome;
	*siape = professor->siape;
}
//funcao para buscar o indice do professor, se nao encontrar, retorna -1
int buscarProfessor(Professor **professor, int siape, int TAM)
{
	for(int i = 0; i < TAM; i++)
	{
		if(professor[i]->siape == siape)
		{
			return i;
		}
	}
	return -1;
}
//funcao para remover o Professor do vetor
void removerProfessor(Professor** professor, int inicio, int contProfessor)
{
	for(int i = inicio; i < contProfessor - 1; i++)
	{
		professor[i] = professor[i + 1];
	}
	liberarProfessor(professor[contProfessor]);
}
//funcao para desalocar a memoria da posicao do vetor do Professor
void liberarProfessor(Professor *professor)
{
	delete professor;
}
//funcao para desalocar o vetor de professores
void liberarProfessor(Professor **professor, int TAM)
{
	for(int i = 0; i < TAM; i++)
	{
		liberarProfessor(professor[i]);
	}
	delete[] professor;
}
//funcao para retornar a siape para outra TAD
int retornaSiape(Professor *professor)
{
	return professor->siape;
}
//funcao para retornar a struct professor para outra TAD
Professor* retornarProfessor(Professor* professor)
{
	return professor;
}
//funcao para retornar o nome do professor para outra TAD
string retornaNomeProfessor(Professor *professor)
{
	return professor->nome;
}
