#ifndef ALUNOS_HPP
#define ALUNOS_HPP

typedef struct Alunos alunos;
Alunos** aloca_a(int quant_a);
void desaloca_a(Alunos** aluno,int quant_a);
void deleta_a(Alunos** aluno, char matricula_aluno_aux[50], int&  quant_inserir_aux);
void inserir_a(Alunos** aluno, int quant_inserir_a, int quant_inserir_aux);
void buscar_a(Alunos** aluno, char matricula_aluno_aux[50], int quant_inserir_aux);
void atualizar_a(Alunos** aluno,char matricula_aluno_aux[50], int quant_inserir_aux);
void imprimir_a(Alunos** aluno, int quant_inserir_aux);
void info_aluno();


#endif
