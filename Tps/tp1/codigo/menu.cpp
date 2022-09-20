#include "menu.hpp"
#include "atestadoMatricula.hpp"
#include "encargo.hpp"
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

int menuInicial()
{
	int opcao;
	
	cout <<"\nDigite uma opção: " << endl;
	cout << "1-ALUNO" << endl;
	cout << "2-PROFESSOR" << endl;
	cout << "3-DISCIPLINA" << endl;
	cout << "4-ATESTADO DE MATRICULA" << endl;
	cout << "5-ENCARGOS DE PROFESSOR" << endl;
	cout << "0-SAIR" << endl;

	cin >> opcao;
	return opcao;
}

void menuAluno(Aluno **aluno, Atestado**atestado, int &contAluno, int &contAtestado)
{
	int opcao, indice, indiceAtestado;
	string nome, cpf, curso, data, matricula;
	do
	{
		
		
		cout << "\n1-INSERIR ALUNO";
		cout << "\n2-REMOVER ALUNO";
		cout << "\n3-ATUALIZAR ALUNO";
		cout << "\n4-BUSCAR ALUNO";
		cout << "\n5-LISTAR ALUNOS";
		cout << "\n0-SAIR" << endl;
		
		cin >> opcao;

		getchar();

		switch(opcao)
		{
		case 1:
			cout << "\nINSERIR DADOS DO ALUNO:\n" << endl;
			cout << "MATRICULA: ";
			getline(cin, matricula);
			if(buscarAluno(aluno, matricula, contAluno) == -1)
			{
				//checando se ja existe aluno cadastrado com a matricula digitada
				cout << "NOME: ";
				getline(cin, nome);
				cout << "CPF: ";
				getline(cin, cpf);
				cout << "CURSO: ";
				getline(cin, curso);
				cout << "DATA DE INGRESSO: ";
				getline(cin, data);
				aluno[contAluno] = inserirDadosAluno(nome, cpf, matricula, curso, data);
				cout << "\nALUNO " << retornaNomeAluno(aluno[contAluno]) << " CADASTRADO COM SUCESSO\n" << endl;
				contAluno++;
			}
			else
			{
				cout << "\nMATRICULA JA EXISTENTE\n" << endl;
			}
			break;
		case 2:
			cout << "\nREMOVER ALUNO:\n" << endl;
			if(contAluno > 0)
			{
				cout << "INSIRA A MATRICULA DO ALUNO: ";
				getline(cin, matricula);
				indice = buscarAluno(aluno, matricula, contAluno);
				if(indice >= 0)
				{
					//procura o atestado de matricula do aluno
					indiceAtestado = buscarAtestado(atestado, matricula, contAtestado);
					if(indiceAtestado != contAtestado)
					{
						//se existir, remove o atestado
						removerAtestado(atestado, indiceAtestado, contAtestado);
					}
					cout << "\nALUNO " << retornaNomeAluno(aluno[indice]) << " REMOVIDO COM SUCESSO\n" << endl;
					removerAluno(aluno, indice, contAluno);
				}
				else
				{
					cout << "\nALUNO NAO ENCONTRADO\n" << endl;
				}
			}
			else
			{
				cout << "\nNAO EXISTEM ALUNOS CADASTRADOS NO MOMENTO\n" << endl;
			}
			break;
		case 3:
			cout << "\nATUALIZAR ALUNO:\n" << endl;
			if(contAluno > 0)
			{
				cout << "INSIRA A MATRICULA DO ALUNO: ";
				getline(cin, matricula);
				indice = buscarAluno(aluno, matricula, contAluno);
				if(indice >= 0)
				{
					cout << "NOME: ";
					getline(cin, nome);
					cout << "CPF: ";
					getline(cin, cpf);
					cout << "CURSO: ";
					getline(cin, curso);
					cout << "DATA DE INGRESSO: ";
					getline(cin, data);
					alterarDadosAluno(aluno[indice], nome, cpf, matricula, curso, data);
					cout << "\nALUNO ATUALIZADO COM SUCESSO\n" << endl;
				}
				else
				{
					cout << "\nALUNO NAO ENCONTRADO\n" << endl;
				}
			}
			else
			{
				cout << "\nNAO EXISTEM ALUNOS CADASTRADOS NO MOMENTO\n" << endl;
			}
			break;
		case 4:
			cout << "\nBUSCAR ALUNO:\n" << endl;
			if(contAluno > 0)
			{
				cout << "INSIRA A MATRICULA DO ALUNO: ";
				getline(cin, matricula);
				indice = buscarAluno(aluno, matricula, contAluno);
				if(indice >= 0)
				{
					//mostra todos os dados do aluno
					retornarDadosAluno(aluno[indice], &nome, &cpf, &matricula, &curso, &data);
					cout << "\nNOME: " << nome << endl;
					cout << "CPF: " << cpf << endl;
					cout << "MATRICULA: " << matricula << endl;
					cout << "CURSO: " << curso << endl;
					cout << "DATA DE INGRESSO: " << data << "\n" << endl;
				}
				else
				{
					cout << "\nALUNO NAO ENCONTRADO\n" << endl;
				}
			}
			else
			{
				cout << "\nNAO EXISTEM ALUNOS CADASTRADOS NO MOMENTO\n" << endl;
			}
			break;
		case 5:
			cout << "\nLISTA DE ALUNOS: \n" << endl;
			if(contAluno > 0)
			{
				for(int i = 0; i < contAluno; i++)
				{
					//faz uma lista de todos os alunos, mostrando apenas o nome e a matricula
					listarAluno(aluno[i], &nome, &matricula);
					cout << "NOME: " << nome << " || MATRICULA: " << matricula << endl;
				}
			}
			else
			{
				cout << "\nNAO EXISTEM ALUNOS CADASTRADOS NO MOMENTO\n" << endl;
			}
			cout << endl;
		case 0:
			break;
		default:
			cout << "\nOPCAO INVALIDA!" << endl;
			cout << "DIGITE NOVAMENTE!\n" << endl;
		}
	}
	while(opcao);
}

void menuProfessor(Professor **professor, Encargo **encargo, int &contProfessor, int&contEncargo)
{
	int opcao, indice, siape, indiceEncargo;
	string nome;
	do
	{
		
		
		cout << "\n1-INSERIR PROFESSOR";
		cout << "\n2-REMOVER PROFESSOR";
		cout << "\n3-ATUALIZAR PROFESSOR";
		cout << "\n4-BUSCAR PROFESSOR";
		cout << "\n5-LISTAR PROFESSORES" << endl;
		cout << "\n0-SAIR" << endl;
		
		cin >> opcao;

		switch(opcao)
		{
		case 1:
			cout << "\nINSERIR DADOS DO PROFESSOR:\n" << endl;
			cout << "SIAPE: ";
			cin >> siape;
			getchar();
			if(buscarProfessor(professor, siape, contProfessor) == -1)
			{
				//checando se ja existe aluno cadastrado com a matricula digitada
				cout << "NOME: ";
				getline(cin, nome);
				professor[contProfessor] = inserirDadosProfessor(nome, siape);
				cout << "\nPROFESSOR  " << retornaNomeProfessor(professor[contProfessor]) << " CADASTRADO COM SUCESSO\n" << endl;
				contProfessor++;
			}
			else
			{
				cout << "\nSIAPE JA EXISTENTE\n" << endl;
			}
			break;
		case 2:
			cout << "\nREMOVER PROFESSOR:\n" << endl;
			if(contProfessor > 0)
			{
				cout << "INSIRA O SIAPE DO PROFESSOR: ";
				cin >> siape;
				indice = buscarProfessor(professor, siape, contProfessor);
				if(indice >= 0)
				{
					//procura o encargo do professor
					indiceEncargo = buscarEncargo(encargo, siape, contEncargo);
					if(indiceEncargo != contEncargo)
					{
						//se exitir, remove o encargo
						removerEncargo(encargo, indiceEncargo, contEncargo);
					}
					cout << "\nPROFESSOR " << retornaNomeProfessor(professor[indice]) << " REMOVIDO COM SUCESSO\n" << endl;
					removerProfessor(professor, indice, contProfessor);
					contProfessor--;
				}
				else
				{
					cout << "\nPROFESSOR NAO ENCONTRADO\n" << endl;
				}
			}
			else
			{
				cout << "\nNAO EXISTEM PROFESSORES CADASTRADOS NO MOMENTO\n" << endl;
			}
			break;
		case 3:
			cout << "\nATUALIZAR PROFESSOR:\n" << endl;
			if(contProfessor > 0)
			{
				cout << "INSIRA O SIAPE DO PROFESSOR: ";
				cin >> siape;
				getchar();
				indice = buscarProfessor(professor, siape, contProfessor);
				if(indice >= 0)
				{
					cout << "NOME: ";
					getline(cin, nome);
					professor[indice] = inserirDadosProfessor(nome, siape);
					cout << "\nPROFESSOR ATUALIZADO COM SUCESSO\n" << endl;
				}
				else
				{
					cout << "\nPROFESSOR NAO ENCONTRADO\n" << endl;
				}
			}
			else
			{
				cout << "\nNAO EXISTEM PROFESSORES CADASTRADOS NO MOMENTO\n" << endl;
			}
			break;
		case 4:
			cout << "\nBUSCAR PROFESSOR:\n" << endl;
			if(contProfessor > 0)
			{
				cout << "INSIRA O SIAPE DO PROFESSOR: ";
				cin >> siape;
				indice = buscarProfessor(professor, siape, contProfessor);
				if(indice >= 0)
				{
					//mostra todos os dados do professor
					retornarDadosProfessor(professor[indice], &nome, &siape);
					cout << "\nNOME: " << nome << endl;
					cout << "SIAPE: " << siape << "\n" << endl;

				}
				else
				{
					cout << "\nPROFESSOR NAO ENCONTRADO\n" << endl;
				}
			}
			else
			{
				cout << "\nNAO EXISTEM PROFESSORES CADASTRADOS NO MOMENTO\n" << endl;
			}
			break;
		case 5:
			cout << "\nLISTA DE PROFESSORES: \n" << endl;
			if(contProfessor > 0)
			{
				for(int i = 0; i < contProfessor; i++)
				{
					//lista todos os professores, mostrando o seu nome e o siape
					listarProfessor(professor[i], &nome, &siape);
					cout << "NOME: " << nome << " || SIAPE: " << siape << endl;
				}
			}
			else
			{
				cout << "\nNAO EXISTEM PROFESSORES CADASTRADOS NO MOMENTO\n" << endl;
			}
			cout << endl;
		case 0:
			break;
		default:
			cout << "\nOPCAO INVALIDA!" << endl;
			cout << "DIGITE NOVAMENTE!\n" << endl;
		}
	}
	while(opcao);
}

void menuDisciplina(Disciplina **disciplina, Atestado **atestado, Encargo** encargo, int contEncargo, int contAtestado, int &contDisciplina)
{
	int opcao, indice, carga, indiceDisciplinaAtestado, indiceDisciplinaEncargo;
	string nome, curso, codigo, sala;
	do
	{
		
		cout << "\n1-INSERIR DISCIPLINA";
		cout << "\n2-REMOVER DISCIPLINA";
		cout << "\n3-ATUALIZAR DISCIPLINA";
		cout << "\n4-BUSCAR DISCIPLINA";
		cout << "\n5-LISTAR DISCIPLINAS";
		cout << "\n0-SAIR" << endl;
		
		
		cin >> opcao;

		getchar();

	      switch(opcao)
	      {
		case 1:
			cout << "\nINSERIR DADOS DA DISCIPLINA:\n" << endl;
			cout << "CODIGO: ";
			getline(cin, codigo);
			if(buscarDisciplina(disciplina, codigo, contDisciplina) == -1)
			{
				//checando se ja existe a disciplina cadastrada
				cout << "NOME: ";
				getline(cin, nome);
				carga = validarCargaHoraria();
				getchar();
				cout << "CURSO: ";
				getline(cin, curso);
				cout << "SALA: ";
				getline(cin, sala);
				disciplina[contDisciplina] = inserirDadosDisciplina(nome, codigo, carga, curso, sala);
				contDisciplina++;
				cout << "\nDISCIPLINA CADASTRADA COM SUCESSO\n" << endl;
			}
			else
			{
				cout << "\nCODIGO JA EXISTENTE\n" << endl;
			}
			break;
		case 2:
			cout << "\nREMOVER DISCIPLINA:\n" << endl;
			if(contDisciplina > 0)
			{
				cout << "INSIRA O CODIGO DA DISCIPLINA: ";
				getline(cin, codigo);
				indice = buscarDisciplina(disciplina, codigo, contDisciplina);
				if(indice >= 0)
				{
					for(int i = 0; i < contAtestado; i++)
					{
						//procurando os atestados de aluno que possuam essa disciplina
						indiceDisciplinaAtestado = retornarIndiceDisciplinaAtestado(atestado[i], codigo);
						if(indiceDisciplinaAtestado >= 0)
						{
							//se existir, remove do atestado
							removerDisciplinaAtestado(atestado[i], indiceDisciplinaAtestado);
						}
					}
					for(int i = 0; i < contEncargo; i++)
					{
						//procurando os encargos de professor que possuam essa disciplina
						indiceDisciplinaEncargo = retornarIndiceDisciplinaEncargo(encargo[i], codigo);
						if(indiceDisciplinaEncargo >= 0)
						{
							//se existir, remove do atestado
							removerDisciplinaEncargo(encargo[i], indiceDisciplinaEncargo);
						}
					}
					cout << "\nDISCIPLINA " << retornaNomeDisciplina(disciplina[indice]) << " REMOVIDA COM SUCESSO\n" << endl;
					removerDisciplina(disciplina, indice, contDisciplina);
					contDisciplina--;
				}
				else
				{
					cout << "\nDISCIPLINA NAO ENCONTRADA\n" << endl;
				}
			}
			else
			{
				cout << "\nNAO EXISTEM DISCIPLINAS CADASTRADAS NO MOMENTO\n" << endl;
			}
			break;
		case 3:
			cout << "\nATUALIZAR DISCIPLINA:\n" << endl;
			if(contDisciplina > 0)
			{
				cout << "INSIRA O CODIGO DA DISCIPLINA: ";
				getline(cin, codigo);
				indice = buscarDisciplina(disciplina, codigo, contDisciplina);
				if(indice >= 0)
				{
					cout << "NOME: ";
					getline(cin, nome);
					carga = validarCargaHoraria();
					getchar();
					cout << "CURSO: ";
					getline(cin, curso);
					cout << "SALA: ";
					getline(cin, sala);
					disciplina[contDisciplina] = inserirDadosDisciplina(nome, codigo, carga, curso, sala);
					cout << "\nDISCIPLINA ATUALIZADA COM SUCESSO\n" << endl;
				}
				else
				{
					cout << "\nDISCIPLINA NAO ENCONTRADA\n" << endl;
				}
			}
			else
			{
				cout << "\nNAO EXISTEM DISCIPLINAS CADASTRADAS NO MOMENTO\n" << endl;
			}
			break;
		case 4:
			cout << "\nBUSCAR DISCIPLINA:\n" << endl;
			if(contDisciplina > 0)
			{
				cout << "INSIRA O CODIGO DA DISCIPLINA: ";
				getline(cin, codigo);
				indice = buscarDisciplina(disciplina, codigo, contDisciplina);
				if(indice >= 0)
				{
					//mostra todos os dados da disciplina
					retornarDadosDisciplina(disciplina[indice], &nome, &codigo, &carga, &curso, &sala);
					cout << "\nNOME: " << nome << endl;
					cout << "CARGA HORARIA: " << carga << " horas" << endl;
					cout << "CODIGO: " << codigo << endl;
					cout << "CURSO: " << curso << endl;
					cout << "SALA: " << sala << "\n" << endl;
				}
				else
				{
					cout << "\nDISCIPLINA NAO ENCONTRADA\n" << endl;
				}
			}
			else
			{
				cout << "\nNAO EXISTEM DISCIPLINAS CADASTRADAS NO MOMENTO\n" << endl;
			}
			break;
		case 5:
			cout << "\nLISTA DE DISCIPLINAS: \n" << endl;
			if(contDisciplina > 0)
			{
				for(int i = 0; i < contDisciplina; i++)
				{
					//mostra uma lista com as disciplinas, mostrando o nome e o seu codigo
					listarDisciplina(disciplina[i], &nome, &codigo);
					cout << "NOME: " << nome << " || CODIGO: " << codigo << endl;
				}
			}
			else
			{
				cout << "\nNAO EXISTEM DISCIPLINAS CADASTRADAS NO MOMENTO\n" << endl;
			}
			cout << endl;
		case 0:
			break;
		default:
			cout << "\nOPCAO INVALIDA!" << endl;
			cout << "DIGITE NOVAMENTE!\n" << endl;
		}
	}
	while(opcao);
}

void menuAtestadoMatricula(Atestado** atestado, Aluno** aluno, Disciplina** disciplina, int contAluno, int contDisciplina, int &contAtestado)
{
	int opcao, indiceAluno, indiceAtestado, indiceDisciplina, cargaHorariaMaxima = 24;
	string matricula, codigo, nomeAluno;
	do
	{
		
		
		cout << "\n1-MATRICULAR";
		cout << "\n2-REMOVER";
		cout << "\n3-LISTAR";
		cout << "\n0-SAIR"<< endl;
		
		cin >> opcao;

		getchar();

	    switch(opcao)
	    {
		case 1:
			if(contAluno > 0)
			{
				//checando se existem alunos cadastrados
				if(contDisciplina > 0)
				{
					//checando se existem disciplinas cadastradas
					cout << "\nINSIRA A MATRICULA DO ALUNO:\n" << endl;
					cout << "MATRICULA: ";
					getline(cin, matricula);
					indiceAluno = buscarAluno(aluno, matricula, contAluno);
					if(indiceAluno >= 0)//checando se existe o aluno cadastrado
					{
						indiceAtestado = buscarAtestado(atestado, matricula, contAtestado);
						if(indiceAtestado == contAtestado)//checa primeiro se o aluno ja tem atestado
						{
							//se nao tiver, incrementa o contador de atestados
							contAtestado++;
						}
						nomeAluno = retornaNomeAluno(aluno[indiceAluno]);
						cout << "\nALUNO: " << nomeAluno << endl;
						if(verificarCargaHoraria(atestado[indiceAtestado], cargaHorariaMaxima))
						{
							//checando se o aluno ja possui a carga horaria maxima permitidas semanais cadastradas no seu atestado
							cout << "\nINSIRA O CODIGO DA DISCIPLINA:\n" << endl;
							cout << "CODIGO: ";
							getline(cin, codigo);//procurando a disciplina
							indiceDisciplina = buscarDisciplina(disciplina, codigo, contDisciplina);
							if(indiceDisciplina >= 0)
							{
								if(buscarDisciplinaAtestado(atestado[indiceAtestado], codigo))
								{
									//checa se o aluno ja possui essa disciplina cadastrada
									if(verificarCargaHoraria(atestado[indiceAtestado], disciplina[indiceDisciplina], cargaHorariaMaxima))
									{
										//checa se com essa disciplina, a carga horaria vai ultrapassar a carga horaria maxima permitida
										atestado[indiceAtestado] = inserirDisciplinaAtestado(atestado[indiceAtestado], disciplina, aluno, indiceDisciplina, indiceAluno);
										cout << "\nO ALUNO " << nomeAluno << " FOI CADASTRADO COM SUCESSO NA DISCIPLINA DE " << retornaNomeDisciplina(disciplina[indiceDisciplina]) << "\n" << endl;
									}
									else
									{
										cout << "\nNAO EH POSSIVEL MATRICULAR O ALUNO NESTA DISCIPLINA\nCARGA HORARIA ULTRAPASSA " << cargaHorariaMaxima << " HORAS SEMANAIS\n" << endl;
									}
								}
								else
								{
									cout << "\nO ALUNO JA POSSUI MATRICULA NESTA DISCIPLINA\n" << endl;
								}
							}
							else
							{
								cout << "\nDISCIPLINA NAO ENCONTRADA\n" << endl;
							}
						}
						else
						{
							cout << "\nO ALUNO " << retornaNomeAluno(aluno[indiceAluno]) << " JA POSSUI " << cargaHorariaMaxima << " HORAS SEMANAIS\n" << endl;
						}
					}
					else
					{
						cout << "\nALUNO NAO ENCONTRADO\n" << endl;
					}
				}
				else
				{
					cout << "\nNAO EXISTEM DISCIPLINAS CADASTRADAS NO MOMENTO\n" << endl;
				}
			}
			else
			{
				cout << "\nNAO EXISTEM ALUNOS CADASTRADOS NO MOMENTO\n" << endl;
			}
			break;
		case 2:
			cout << "\nREMOVER DISCIPLINA DO ALUNO:\n" << endl;
			if(contAtestado > 0)
			{
				cout << "INSIRA A MATRICULA DO ALUNO: ";
				cin >> matricula;

				indiceAtestado = buscarAtestado(atestado, matricula, contAtestado);
				if(indiceAtestado != contAtestado)//procura o atestado do aluno
				{
					indiceAluno = buscarAluno(aluno, matricula, contAluno);
					nomeAluno = retornaNomeAluno(aluno[indiceAluno]);
					cout << "\nALUNO: " << nomeAluno << endl;
					cout << "INSIRA O CODIGO DA DISCIPLINA: ";
					cin >> codigo;
					indiceDisciplina = retornarIndiceDisciplinaAtestado(atestado[indiceAtestado], codigo);
					if(indiceDisciplina >= 0)//procura o indice da disciplina no atestado
					{
						removerDisciplinaAtestado(atestado[indiceAtestado], indiceDisciplina);
						cout << "\nDISCIPLINA REMOVIDA COM SUCESSO\n" << endl;
					}
					else
					{
						cout << "\nO ALUNO NAO POSSUI ESSA DISCIPLINA NO ATESTADO\n" << endl;
					}
				}
				else
				{
					cout << "\nO ALUNO NAO POSSUI ATESTADO DE MATRICULA\n" << endl;
				}
			}
			else
			{
				cout << "\nNAO EXISTEM ATESTADOS DE MATRICULA CADASTRADOS NO MOMENTO\n" << endl;
			}
			break;
		case 3:
			cout << "\nLISTA DE DISCIPLINAS DO ALUNO:\n" << endl;
			if(contAluno > 0)
			{
				//checa se ja existem alunos cadastrados
				if(contAtestado > 0)
				{
					//checa se ja existem atestados cadastrados
					cout << "INSIRA A MATRICULA DO ALUNO: ";
					getline(cin, matricula);
					indiceAluno = buscarAluno(aluno, matricula, contAluno);
					if(indiceAluno >= 0)
					{
						indiceAtestado = buscarAtestado(atestado, matricula, contAtestado);
						if(indiceAtestado != contAtestado)
						{
							cout << "\nNOME: " << retornaNomeAluno(aluno[indiceAluno]) << endl;
							cout << "DISCIPLINAS:" << endl;//lista as disciplinas do aluno
							mostrarDisciplinasAluno(atestado[indiceAtestado]);
						}
						else
						{
							cout << "\nATESTADO DE ALUNO NAO ENCONTRADO\n" << endl;
						}
					}
					else
					{
						cout << "\nALUNO NAO ENCONTRADO\n" << endl;
					}
				}
				else
				{
					cout << "\nNAO EXISTEM ATESTADOS CADASTRADOS NO MOMENTO\n" << endl;
				}
			}
			else
			{
				cout << "\nNAO EXISTEM ALUNOS CADASTRADOS NO MOMENTO\n" << endl;
			}
			break;
		case 0:
			break;
		default:
			cout << "\nOPCAO INVALIDA!" << endl;
			cout << "DIGITE NOVAMENTE!\n" << endl;

		}
	}
	while(opcao);
}

void menuEncargoProfessor(Encargo** encargo, Professor** professor, Disciplina** disciplina, int contProfessor, int contDisciplina, int &contEncargo)
{
	int opcao, indiceProfessor, indiceEncargo, indiceDisciplina, siape, cargaHorariaMaxima = 16;
	string codigo, nomeProfessor;

	do
	{
		
		cout << "\n1-CRIAR";
		cout << "\n2-REMOVER";
		cout << "\n3-LISTAR";
		cout << "\n0SAIR" << endl;
		
		
		cin >> opcao;

		getchar();

	      switch(opcao)
	      {	
		case 1:
			if(contProfessor > 0)
			{
				//checando se existem professores cadastrados
				if(contDisciplina > 0)
				{
					//checando se existem disciplinas cadastrados
					cout << "\nINSIRA O SIAPE DO PROFESSOR:\n" << endl;
					cout << "SIAPE: ";
					cin >> siape;//busca o indice do professor
					indiceProfessor = buscarProfessor(professor, siape, contProfessor);
					if(indiceProfessor >= 0)
					{
						indiceEncargo = buscarEncargo(encargo, siape, contEncargo);
						if(indiceEncargo == contEncargo)//procura o indice do encargo
						{
							//se ele nao existir, incrementa o contador
							contEncargo++;
						}
						nomeProfessor = retornaNomeProfessor(professor[indiceProfessor]);
						cout << "\nPROFESSOR: " << nomeProfessor << endl;
						if(verificarCargaHoraria(encargo[indiceEncargo], cargaHorariaMaxima))
						{
							//checa se a carga horaria ja alcancou a carga horaria maxima permitida
							cout << "\nINSIRA O CODIGO DA DISCIPLINA:\n" << endl;
							cout << "CODIGO: ";
							getchar();
							getline(cin, codigo);//procurando a disciplina
							indiceDisciplina = buscarDisciplina(disciplina, codigo, contDisciplina);
							if(indiceDisciplina >= 0)
							{
								if(buscarDisciplinaEncargo(encargo[indiceEncargo], codigo))
								{
									//procurando se a disciplina ja existe no encargo do professor
									if(verificarCargaHoraria(encargo[indiceEncargo], disciplina[indiceDisciplina], cargaHorariaMaxima))
									{
										//checa se com essa disciplina, a carga horaria vai ultrapassar a carga horaria maxima permitida
										encargo[indiceEncargo] = inserirDisciplinaEncargo(encargo[indiceEncargo], disciplina, professor, indiceDisciplina, indiceProfessor);
										cout << "\nA DISCIPLINA " << retornaNomeDisciplina(disciplina[indiceDisciplina]) << " FOI ALOCADA COM SUCESSO PARA O PROFESSOR " << nomeProfessor << "\n" << endl;
									}
									else
									{
										cout << "\nNAO EH POSSIVEL ALOCAR ESSA DISCIPLINA PARA O PROFESSOR\nCARGA HORARIA ULTRAPASSA " << cargaHorariaMaxima << " HORAS SEMANAIS\n" << endl;
									}
								}
								else
								{
									cout << "\nO PROFESSOR JA POSSUI ESTA DISCIPLINA NO SEU ENCARGO\n" << endl;
								}
							}
							else
							{
								cout << "\nDISCIPLINA NAO ENCONTRADA\n" << endl;
							}
						}
						else
						{
							cout << "\nO PROFESSOR " << retornaNomeProfessor(professor[indiceProfessor]) << " JA POSSUI " << cargaHorariaMaxima << " HORAS SEMANAIS\n" << endl;
						}
					}
					else
					{
						cout << "\nPROFESSOR NAO ENCONTRADO\n" << endl;
					}
				}
				else
				{
					cout << "\nNAO EXISTEM DISCIPLINAS CADASTRADAS NO MOMENTO\n" << endl;
				}
			}
			else
			{
				cout << "\nNAO EXISTEM PROFESSORS CADASTRADOS NO MOMENTO\n" << endl;
			}
			break;
		case 2:
			cout << "\nREMOVER DISCIPLINA DO PROFESSOR:\n" << endl;
			if(contEncargo > 0)
			{
				cout << "INSIRA O SIAPE DO PROFESSOR: ";
				cin >> siape;//buscando o indice do professor para mostrar o seu nome
				indiceEncargo = buscarEncargo(encargo, siape, contEncargo);
				if(indiceEncargo != contEncargo)//buscando o indice de encargo
				{
					indiceProfessor = buscarProfessor(professor, siape, contProfessor);
					nomeProfessor = retornaNomeProfessor(professor[indiceProfessor]);
					cout << "\nPROFESSOR: " << nomeProfessor << endl;
					cout << "INSIRA O CODIGO DA DISCIPLINA: ";
					getchar();
					cin >> codigo;//buscando o indice da disciplina dentro do encargo
					indiceDisciplina = retornarIndiceDisciplinaEncargo(encargo[indiceEncargo], codigo);
					if(indiceDisciplina >= 0)
					{
						//se existir, remove a disciplina do encargo
						removerDisciplinaEncargo(encargo[indiceEncargo], indiceDisciplina);
						cout << "\nDISCIPLINA REMOVIDA COM SUCESSO\n" << endl;
					}
					else
					{
						cout << "\nO PROFESSOR NAO POSSUI ESSA DISCIPLINA NO ATESTADO\n" << endl;
					}
				}
				else
				{
					cout << "\nO PROFESSOR NAO POSSUI ATESTADO DE ENCARGO\n" << endl;
				}
			}
			else
			{
				cout << "\nNAO EXISTEM ATESTADOS DE ENCARGO CADASTRADOS NO MOMENTO\n" << endl;
			}
			break;
		case 3:
			cout << "\nLISTA DE DISCIPLINAS DO PROFESSOR:\n" << endl;
			if(contProfessor > 0)
			{
				if(contEncargo > 0)
				{
					cout << "INSIRA A MATRICULA DO PROFESSOR: ";
					cin >> siape;//busca o indice do professor
					indiceProfessor = buscarProfessor(professor, siape, contProfessor);
					if(indiceProfessor >= 0)
					{
						indiceEncargo = buscarEncargo(encargo, siape, contEncargo);
						if(indiceEncargo != contEncargo)//busca o indice do encargo
						{
							//lista as disciplinas que o professor leciona
							cout << "\nNOME: " << retornaNomeProfessor(professor[indiceProfessor]) << endl;
							cout << "DISCIPLINAS:" << endl;
							mostrarDisciplinasProfessor(encargo[indiceEncargo]);
						}
						else
						{
							cout << "\nATESTADO DE PROFESSOR NAO ENCONTRADO\n" << endl;
						}
					}
					else
					{
						cout << "\nPROFESSOR NAO ENCONTRADO\n" << endl;
					}
				}
				else
				{
					cout << "\nNAO EXISTEM ATESTADOS CADASTRADOS NO MOMENTO\n" << endl;
				}
			}
			else
			{
				cout << "\nNAO EXISTEM PROFESSORES CADASTRADOS NO MOMENTO\n" << endl;
			}
			break;
		case 0:
			break;
		default:
			cout << "\nOPCAO INVALIDA!" << endl;
			cout << "DIGITE NOVAMENTE!\n" << endl;
		}
	}
	while(opcao);
}
