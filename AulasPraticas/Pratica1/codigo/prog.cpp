#include <iostream>
#include <cstring>
#include "alunos.hpp"
#include "disciplinas.hpp"
#include "professores.hpp"

using namespace std;

int main()
{
    int opcao_geral;

    int quant_a, opcao_a, quant_inserir_a, quant_inserir_aux = 0;//quant_inserir_aux é a quantidade de alunos cadastrados
    char matricula_aluno_aux[50];
    // variáveis para os Alunos

    int quant_d, opcao_d, quant_inserir_d, quant_inserir_auxd = 0;//quant_inserir_auxd é a quantidade de disciplinas cadastradas
    char nome_dis[50];
    //variaveis para disciplina

    int quant_p, opcao_p, quant_inserir_p, quant_inserir_auxp = 0;//quant_inserir_auxp é a quantidade de professores cadastrados
    char nome_prof[50];
    //variaveis para professores

    cout <<"\nDigite a quantidade de alunos que deseja trabalhar: ";
    cin >> quant_a;

    cout <<"\nDigite a quantidade de disciplinas que deseja trabalhar: ";
    cin >> quant_d;

    cout <<"\nDigite a quantidade de professores que deseja trabalhar: ";
    cin >> quant_p;


    Alunos** aluno = aloca_a(quant_a);//Aloca um ponteiro de ponteiros de alunos dinamicamente
    Disciplinas** disciplina = aloca_d(quant_d);//Aloca um ponteiro de ponteiros de disciplinas dinamicamente
    Professores** professor = aloca_p(quant_p);//Aloca um ponteiro de ponteiros de professores dinamicamente

    do//Loop enquanto a opção geral é difernte de zero
    {
        cout <<"\nDigite : " << endl;
        cout <<"0-Sair\n1-Aluno\n2-Disciplina\n3-Professor" << endl;

        cin >> opcao_geral;


        switch(opcao_geral)
        {
                case 1:

                    do//Loop enquanto a opção do aluno for diferente de 0
                    {
                      info_aluno();//Função que passa opções para os alunos

                      cin >> opcao_a;

                      switch(opcao_a)
                      {
                          case 0:

                          break;

                          case 1:

                                cout <<"Digite a quantidade de alunos que deseja inserir: ";
                                cin >> quant_inserir_a;

                                inserir_a(aluno, quant_inserir_a, quant_inserir_aux);//Função que insere alunos

                                quant_inserir_aux += quant_inserir_a;

                        break;

                        case 2:

                              cout <<"Digite a matrícula do aluno que deseja deletar: ";
                              cin >> matricula_aluno_aux;

                              deleta_a(aluno, matricula_aluno_aux, quant_inserir_aux);//Função que deleta alunos

                        break;

                        case 3:

                              cout <<"Digite a matrícula do aluno que deseja buscar: ";
                              cin >> matricula_aluno_aux;

                              buscar_a(aluno, matricula_aluno_aux, quant_inserir_aux);//Função que busca aluno inserido

                        break;

                        case 4:

                              cout <<"Digite a matrícula do aluno que deseja atualizar seus dados: ";
                              cin >> matricula_aluno_aux;

                              atualizar_a(aluno,matricula_aluno_aux,quant_inserir_aux);//Função que atualiza aluno

                        break;

                        case 5:

                              imprimir_a(aluno, quant_inserir_aux);//Função que imprimi na tela stodos os alunos

                        break;
                      }
                    }while(opcao_a != 0);

                  break;

                  case 2:

                        do//Loop enquanto a opção da disciplina for diferente de 0
                        {
                          info_disciplina();//Função que imprime na tela opções das ferramentas que pode se fazer com a disciplina

                          cin >> opcao_d;

                          switch(opcao_d)
                          {
                              case 0:

                              break;

                              case 1:

                                    cout <<"Digite a quantidade de disciplinas que deseja inserir: ";
                                    cin >> quant_inserir_d;

                                    inserir_d(disciplina, quant_inserir_d, quant_inserir_auxd);//Função que insere disciplinas

                                    quant_inserir_auxd += quant_inserir_d;

                              break;

                              case 2:

                                    cout <<"Digite o nome da disciplina que deseja deletar: ";
                                    cin >> nome_dis;

                                    deleta_d(disciplina,nome_dis, quant_inserir_auxd);//Função que deleta disciplinas

                              break;

                              case 3:

                                    cout <<"Digiteo o nome da disciplina que deseja buscar: ";
                                    cin >> nome_dis;

                                    buscar_d(disciplina,nome_dis, quant_inserir_auxd);//Função que busca um disciplina inserida

                              break;

                              case 4:

                                    cout <<"Digite o nome da disciplina que deseja atualizar seus dados: ";
                                    cin >> nome_dis;

                                    atualizar_d(disciplina,nome_dis,quant_inserir_auxd);//Função que atualiza um disciplina

                              break;

                              case 5:

                                    imprimir_d(disciplina, quant_inserir_auxd);//Função que imprime uma disciplina

                              break;
                          }
                        }while(opcao_d != 0);

                  break;

                  case 3:

                      do//Loop equanto a opção_p for diferente de 0
                      {
                          info_professor();//Informações das ferramentas relacionadas ao professor, apena imprimi na tela opções

                          cin >> opcao_p;

                          switch(opcao_p)
                          {
                              case 0:

                              break;

                              case 1:

                                    cout <<"Digite a quantidade de professores que deseja inserir: ";
                                    cin >> quant_inserir_p;

                                    inserir_p(professor, quant_inserir_p, quant_inserir_auxp);//Função que insere um professor

                                    quant_inserir_auxp += quant_inserir_p;

                              break;

                              case 2:

                                    cout <<"Digite o nome do professor que deseja deletar: ";
                                    cin >> nome_prof;

                                    deleta_p(professor,nome_prof, quant_inserir_auxp);//Função que deleta um professor

                              break;

                              case 3:

                                    cout <<"Digiteo o nome do professor que deseja buscar: ";
                                    cin >> nome_prof;

                                    buscar_p(professor,nome_prof, quant_inserir_auxp);//Função que busca um professor inserido

                              break;

                              case 4:

                                    cout <<"Digite o nome do professor que deseja atualizar seus dados: ";
                                    cin >> nome_prof;

                                    atualizar_p(professor,nome_prof,quant_inserir_auxp);//Função que atualiza os dados de um professor inserido

                              break;

                              case 5:

                                     imprimir_p(professor, quant_inserir_auxp);//imprime na tela todos os professores e seus dados

                              break;
                            }
                    }while(opcao_p != 0);

                break;
          }
    }while(opcao_geral != 0);

    desaloca_a(aluno, quant_a);//desaloca um ponteiro de ponteiros de alunos dinamicamente
    desaloca_d(disciplina, quant_d);//desaloca um ponteiro de ponteiros de alunos dinamicamente
    desaloca_p(professor, quant_p);//desaloca um ponteiro de ponteiros de alunos dinamicamente

    return 0;//término do programa
}
