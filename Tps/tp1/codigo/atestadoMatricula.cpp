#include "atestadoMatricula.hpp"
#include <string>
#include <cstring>
#include <iostream>
using namespace std;

//criando struct atestado
struct atestado
{
	Aluno* aluno;
	Disciplina** disciplina;
	int cargaHoraria;
	int contDisciplina;
};
//funcao para alocar dinamicamente a struct atestado
Atestado* criarAtestado()
{
	return new Atestado;
}
//funcao para alocar o vetor de atestados dinamicamente
Atestado** criarAtestado(int TAM)
{
	Atestado** aux = new Atestado* [TAM];
	for(int i = 0; i < TAM; i++)
	{
		aux[i] = alocarAtestadoDisciplinas();
	}
	return aux;
}
//funcao para buscar o indice do atestado, se nao encontrar, retorna o contAtestado
int buscarAtestado(Atestado **atestado, string matricula, int TAM)
{
	for(int i = 0; i < TAM; i++)
	{
		if(retornaMatricula(atestado[i]->aluno) == matricula)
		{
			return i;
		}
	}
	return TAM;
}
//funcao para inserir os dados das disciplinas para o atestado
Atestado* inserirDisciplinaAtestado(Atestado *atestado, Disciplina **disciplina, Aluno **aluno, int indiceDisciplina, int indiceAluno)
{
	int cont = atestado->contDisciplina;
	atestado->disciplina[cont] = retornarDisciplina(disciplina[indiceDisciplina]); //busca a disciplina na tad disciplina
	atestado->aluno = retornarAluno(aluno[indiceAluno]); //busca aluno na tad aluno
	atestado->cargaHoraria += retornarCarga(disciplina[indiceDisciplina]);//incrementa a carga horaria
	atestado->contDisciplina++;//incrementa o contador de disciplinas
	return atestado;
}
//funcao para alocar o a posicao do atestado
Atestado* alocarAtestadoDisciplinas()
{
	Atestado *atestado = criarAtestado();
	atestado->contDisciplina = 0; //zerando o contador de disciplinas
	atestado->disciplina = criarDisciplina(6);//alocando o vetor de disciplinas
	//atestado->aluno = criarAluno(); //alocando o ponteiro de aluno
	/*for(int i = 0; i < 6; i++)
	{
		//alocando dinamicamente nas posicoes do vetor de disciplinas
		atestado->disciplina[i] = criarDisciplina();
	}*/
	return atestado;
}
//funcao para verificar se o atestado ja possui 24 horas
bool verificarCargaHoraria(Atestado* atestado,int cargaMaxima)
{
	if (atestado->cargaHoraria < cargaMaxima)
		return true;
	else
	{
		return false;
	}
}
//funcao para buscar o nome do aluno em outra TAD
string retornarNomeAlunoAtestado(Atestado* atestado)
{
	return retornaNomeAluno(atestado->aluno);
}
//funcao para checar se o atestado ja possui a disciplina cadastrada
bool buscarDisciplinaAtestado(Atestado* atestado, string codigo)
{
	if(buscarDisciplina(atestado->disciplina, codigo, atestado->contDisciplina) >= 0)
	{
		return false;
	}
	return true;
}
//funcao para retornar o indice do vetor de disciplinas dentro do atestado
int retornarIndiceDisciplinaAtestado(Atestado* atestado, string codigo)
{
	int indice;
	for(int i = 0; i < atestado->contDisciplina; i++)
	{
		indice = buscarDisciplina(atestado->disciplina, codigo, atestado->contDisciplina);
		if(indice >= 0){
			return indice;
		}
	}
	return -1;
}
//funcao para remover o atestado do vetor
void removerAtestado(Atestado** atestado, int inicio, int &contAtestado)
{
	for(int i = inicio; i < contAtestado - 1; i++)
	{
		atestado[i] = atestado[i + 1];
	}
	liberarAtestado(atestado[contAtestado]);
	contAtestado--;
}
//funcao para remover uma disciplina de dentro do atestado
void removerDisciplinaAtestado(Atestado* atestado, int inicio)
{
	//reduz a carga horaria
	atestado->cargaHoraria -= retornarCarga(atestado->disciplina[inicio]);
	for(int i = inicio; i < atestado->contDisciplina; i++)
	{
		atestado->disciplina[i] = atestado->disciplina[i + 1];
	}
	atestado->contDisciplina--;//reduz o contador de disciplinas
}
//funcao para verificar se com o acrescimo da disciplina a carga horaria vai ultrapassar 24 horas
bool verificarCargaHoraria(Atestado* atestado, Disciplina *disciplina,int cargaMaxima)
{
	if (atestado->cargaHoraria + retornarCarga(disciplina) <= cargaMaxima)
		return true;
	else
	{
		return false;
	}
}
//funcao para mostrar as disciplinas que o aluno possui em seu atestado
void mostrarDisciplinasAluno(Atestado* atestado){
	for(int i=0;i<atestado->contDisciplina;i++){
		cout<<i+1<<": "<<retornaNomeDisciplina(atestado->disciplina[i])<<endl;
	}
	cout<<endl;
}
//funcao para desalocar dinamicamente o vetor de atestados
void liberarAtestado(Atestado **atestado, int TAM)
{
	for(int i = 0; i < TAM; i++)
	{
		liberarAtestado(atestado[i]);
	}
	delete []atestado;
}
//funcao que desaloca o vetor de disciplinas, o ponteiro de alunos e a posicao do atestado
void liberarAtestado(Atestado *atestado)
{
	//liberarDisciplina(atestado->disciplina, 6);
    //liberarAluno(atestado->aluno);
    liberarDisciplinaTad(atestado->disciplina);
	delete atestado;
}
