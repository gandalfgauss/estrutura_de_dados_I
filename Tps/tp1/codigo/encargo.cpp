#include "encargo.hpp"
#include <string>
#include <cstring>
#include <iostream>
using namespace std;

//criando struct encargo
struct encargo
{
	Professor* professor;
	Disciplina** disciplina;
	int cargaHoraria;
	int contDisciplina;
};
//funcao para alocar dinamicamente a struct encargo
Encargo* criarEncargo()
{
	return new Encargo;
}
//funcao para alocar o vetor de encargos dinamicamente
Encargo** criarEncargo(int TAM)
{
	Encargo** aux = new Encargo* [TAM];
	for(int i = 0; i < TAM; i++)
	{
		aux[i] = alocarEncargoDisciplinas();
	}
	return aux;
}
//funcao para buscar o indice do encargo, se nao encontrar, retorna o contEncargo
int buscarEncargo(Encargo **encargo, int siape, int TAM)
{
	for(int i = 0; i < TAM; i++)
	{
		if(retornaSiape(encargo[i]->professor) == siape)
		{
			return i;
		}
	}
	return TAM;
}
//funcao para inserir os dados das disciplinas para o encargo
Encargo* inserirDisciplinaEncargo(Encargo *encargo, Disciplina **disciplina, Professor **professor, int indiceDisciplina, int indiceProfessor)
{
	int cont = encargo->contDisciplina;
	encargo->disciplina[cont] = retornarDisciplina(disciplina[indiceDisciplina]); //busca a disciplina na tad disciplina
	encargo->professor = retornarProfessor(professor[indiceProfessor]); //busca professor na tad professor
	encargo->cargaHoraria += retornarCarga(disciplina[indiceDisciplina]);//incrementa a carga horaria
	encargo->contDisciplina++;//incrementa o contador de disciplinas
	return encargo;
}
//funcao para alocar o a posicao do encargo
Encargo* alocarEncargoDisciplinas()
{
	Encargo *encargo = criarEncargo();
	encargo->contDisciplina = 0; //zerando o contador de disciplinas
	encargo->disciplina = criarDisciplina(4);//alocando o vetor de disciplinas
	/*encargo->professor = criarProfessor(); //alocando o ponteiro de professor
	for(int i = 0; i < 4; i++)
	{
		//alocando dinamicamente nas posicoes do vetor de disciplinas
		encargo->disciplina[i] = criarDisciplina();
	}*/
	return encargo;
}
//funcao para verificar se o encargo ja possui 16 horas
bool verificarCargaHoraria(Encargo* encargo,int cargaMaxima)
{
	if (encargo->cargaHoraria < cargaMaxima)
		return true;
	else
	{
		return false;
	}
}
//funcao para buscar o nome do professor em outra TAD
string retornarNomeProfessorEncargo(Encargo* encargo)
{
	return retornaNomeProfessor(encargo->professor);
}
//funcao para checar se o encargo ja possui a disciplina cadastrada
bool buscarDisciplinaEncargo(Encargo* encargo, string codigo)
{
	if(buscarDisciplina(encargo->disciplina, codigo, encargo->contDisciplina) >= 0)
	{
		return false;
	}
	return true;
}
//funcao para retornar o indice do vetor de disciplinas dentro do encargo
int retornarIndiceDisciplinaEncargo(Encargo* encargo, string codigo)
{
	int indice;
	for(int i = 0; i < encargo->contDisciplina; i++)
	{
		indice = buscarDisciplina(encargo->disciplina, codigo, encargo->contDisciplina);
		if(indice >= 0)
			return indice;
	}
	return -1;
}
//funcao para mostrar as disciplinas que o professor possui em seu encargo
void mostrarDisciplinasProfessor(Encargo* encargo){
	for(int i=0;i<encargo->contDisciplina;i++){
		cout<<i+1<<": "<<retornaNomeDisciplina(encargo->disciplina[i])<<endl;
	}
	cout<<endl;
}
//funcao para remover o encargo do vetor
void removerEncargo(Encargo** encargo, int inicio, int &contEncargo)
{
	for(int i = inicio; i < contEncargo - 1; i++)
	{
		encargo[i] = encargo[i + 1];
	}
	liberarEncargo(encargo[contEncargo]);
	contEncargo--;
}
//funcao para remover uma disciplina de dentro do encargo
void removerDisciplinaEncargo(Encargo* encargo, int inicio)
{
	//reduz a carga horaria
	encargo->cargaHoraria -= retornarCarga(encargo->disciplina[inicio]);
	for(int i = inicio; i < encargo->contDisciplina; i++)
	{
		encargo->disciplina[i] = encargo->disciplina[i + 1];
	}
	encargo->contDisciplina--;//reduz o contador de disciplinas
}
//funcao para verificar se com o acrescimo da disciplina a carga horaria vai ultrapassar 16 horas
bool verificarCargaHoraria(Encargo* encargo, Disciplina *disciplina,int cargaMaxima)
{
	if (encargo->cargaHoraria + retornarCarga(disciplina) <= cargaMaxima)
		return true;
	else
	{
		return false;
	}
}
//funcao para desalocar dinamicamente o vetor de encargos
void liberarEncargo(Encargo **encargo, int TAM)
{
	for(int i = 0; i < TAM; i++)
	{
		liberarEncargo(encargo[i]);
	}
	delete []encargo;
}
//funcao que desaloca o vetor de disciplinas, o ponteiro de professores e a posicao do encargo
void liberarEncargo(Encargo *encargo)
{
	liberarDisciplinaTad(encargo->disciplina);
    //liberarDisciplina(encargo->disciplina, 4);
	//liberarProfessor(encargo->professor);
	delete encargo;
}
