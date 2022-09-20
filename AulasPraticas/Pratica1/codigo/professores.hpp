#ifndef PROFESSORES_HPP
#define PROFESSORES_HPP

typedef struct Professores professores;
Professores** aloca_p(int quant_p);
void desaloca_p(Professores** professor,int quant_p);
void deleta_p(Professores** professor, char nome_prof[50], int&  quant_inserir_auxp);
void inserir_p(Professores** professor, int quant_inserir_p, int quant_inserir_auxp);
void buscar_p(Professores** professor, char nome_prof[50], int quant_inserir_auxp);
void atualizar_p(Professores** professor,char nome_prof[50], int quant_inserir_auxp);
void imprimir_p(Professores** professor, int quant_inserir_auxp);
void info_professor();


#endif
