#ifndef DISCIPLINAS_HPP
#define DISCIPLINAS_HPP

typedef struct Disciplinas disciplinas;
Disciplinas** aloca_d(int quant_d);
void desaloca_d(Disciplinas** disciplina,int quant_d);
void deleta_d(Disciplinas** disciplina, char nome_dis[50], int&  quant_inserir_auxd);
void inserir_d(Disciplinas** disciplina, int quant_inserir_d, int quant_inserir_auxd);
void buscar_d(Disciplinas** disciplina, char nome_dis[50], int quant_inserir_auxd);
void atualizar_d(Disciplinas** disciplina,char nome_dis[50], int quant_inserir_auxd);
void imprimir_d(Disciplinas** disciplina, int quant_inserir_auxd);
void info_disciplina();


#endif
