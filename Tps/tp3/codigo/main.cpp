#include <assert.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <ctype.h>
#include <cstring>
#include <stdbool.h>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

#define MAX_HASH 27
#define MAX_PESO 27

typedef struct noArvore NoArvore;
typedef struct noLista NoLista;
typedef struct lista Lista;

struct noArvore
{
	int frequencia;
	unsigned char letra;
	NoArvore* esq;
	NoArvore* dir;
};

struct noLista
{
	NoArvore* no;
	NoLista* prox;
};

struct lista
{
	NoLista* head;
	int elementos;
};

char* strdup(char*);
NoLista* novo_no_lista(NoArvore* arvore);
NoArvore* novo_no_Arvore(unsigned char letra, int frequencia, NoArvore* esq, NoArvore* dir);
void insere_na_lista(NoLista* no, Lista* lista);
NoArvore* retira_menor_frequencia_lista(Lista* l);
void buscar_frequencia(FILE* entrada, unsigned int* lista);
bool pega_codigo(NoArvore* no, unsigned char letra, char* buffer, int tamanho);
NoArvore* construir_arvoreHuffman(unsigned* listaBytes);
void libera_arvoreHuffman(NoArvore* no);
int geraBit(FILE* entrada, int posicao, unsigned char* aux);
void erroArquivo();
void comprimir(const char* arquivo_entrada, const char* arquivo_saida);
void descomprime(const char* arquivo_entrada, const char* arquivo_saida);


typedef struct Cidade {
	string uf;
	string nome;
	unsigned long populacao;
	float IDH;
}TCidade;

typedef struct No{
	TCidade cidade;
	struct No *pEsq, *pDir;
}TNo;

typedef TNo* TArvore;

typedef struct hash {
	int n; //numero de posicoes do hash;
	int nro_arvore; //tamanho do array de arvores
	int nro_pesos; //tamanho do array de pesos;
	int *p; //array de pesos;
	TArvore *raiz; //array de arvore
}THash;

/* Arvore Binaria de Pesquisa */
void TArvore_Inicia (TNo **raiz) {
	*raiz = NULL;
}

int TArvore_EhVazia(TNo **raiz) {
	return (*raiz == NULL ? 1 : 0);
}

int TArvore_Pesquisa(TArvore pRaiz, TCidade *cidade) {
	if (pRaiz == NULL)
		return 0;

	if (cidade->nome < pRaiz->cidade.nome)
		return TArvore_Pesquisa(pRaiz->pEsq, cidade);

	if (cidade->nome > pRaiz->cidade.nome)
		return TArvore_Pesquisa(pRaiz->pDir, cidade);

	*cidade = pRaiz->cidade;
	return 1;
}

TNo *TNo_Cria(TCidade cidade) {
	TNo *pAux = new TNo;
	pAux->cidade = cidade;
	pAux->pEsq = NULL;
	pAux->pDir = NULL;
	return pAux;
}

void cOut(string msg) {
	cout << "---- " << msg << " ----" << endl;
}

int TArvore_Insere(TNo **ppR, TCidade cidade) {
	if (*ppR == NULL) {
		*ppR = TNo_Cria(cidade);
		return 1;
	}

	if (cidade.nome < (*ppR)->cidade.nome)
		return TArvore_Insere(&((*ppR)->pEsq), cidade);
	if (cidade.nome > (*ppR)->cidade.nome)
		return TArvore_Insere(&((*ppR)->pDir), cidade);

	return 0;
}

int TArvore_Edita(TNo **ppR, TCidade cidade) {
	if (*ppR == NULL)
		return 0;

	if (cidade.nome < (*ppR)->cidade.nome)
		return TArvore_Edita(&((*ppR)->pEsq), cidade);

	if (cidade.nome > (*ppR)->cidade.nome)
		return TArvore_Edita(&((*ppR)->pDir), cidade);

	(*ppR)->cidade = cidade;
	return 1;
}

THash* THash_Inicia() {
	THash *hash = new THash;

	hash->n = 0;
	hash->nro_arvore = MAX_HASH;
	hash->nro_pesos = MAX_PESO;

	//inicializando as listas;
	hash->raiz = new TArvore[MAX_HASH];
	for (int i = 0; i < MAX_HASH; ++i)
		TArvore_Inicia(&hash->raiz[i]);

	hash->p = new int[MAX_PESO];
	for (int i = 0; i < MAX_PESO; ++i)
		hash->p[i] = rand() % 100000;

	return hash;
}

int THash_H(THash *hash, TCidade cidade) {
	int h = 0, len = cidade.uf.length();
	char character;
	if (len == 0) {
		return h;
	}

	for (int i = 0; i < len; i++) {
		character = cidade.uf.at(i);
		h = (31 * h) + (int)character;
	}

	return (h % hash->nro_arvore);
}

void TArvore_Sucessor(TNo *noExcluido, TNo **proximo) {
	if ((*proximo)->pEsq != NULL) {
		TArvore_Sucessor(noExcluido, &(*proximo)->pEsq);
		return;
	}

	TNo *pAux;

	noExcluido->cidade = (*proximo)->cidade;
	pAux = *proximo;
	*proximo = (*proximo)->pDir;
	free(pAux);
}

int TArvore_Excluir(TNo **p, TCidade cidade) {
	if (*p == NULL)
		return 0;

	TNo *pAux;

	if (cidade.nome < (*p)->cidade.nome)
		return TArvore_Excluir(&((*p)->pEsq), cidade);
	else if (cidade.nome > (*p)->cidade.nome)
		return TArvore_Excluir(&((*p)->pDir), cidade);

	if((*p)->pEsq == NULL && (*p)->pDir == NULL) { //nao tem filho
		free(*p);
		*p = NULL;

	} else if ((*p)->pEsq != NULL && (*p)->pDir == NULL) { //tem filho a esquerda
		pAux = *p;
		*p = (*p)->pEsq;
		free(pAux);
	} else if ((*p)->pEsq == NULL && (*p)->pDir != NULL) { //tem filho a direita
		pAux = *p;
		*p = (*p)->pDir;
		free(pAux);
	} else {
		TArvore_Sucessor(*p, &((*p)->pDir));
	}

	return 1;

}

int THash_Pesquisa(THash *hash, TCidade *cidade) {
	int i = THash_H(hash, *cidade);

	if (TArvore_EhVazia(&hash->raiz[i]))
		return 0;

	return TArvore_Pesquisa(hash->raiz[i], cidade);
}

int THash_Insere(THash *hash, TCidade cidade) {
	int i = THash_H(hash, cidade);
	if(TArvore_Insere(&hash->raiz[i], cidade) == 1) {
		hash->n++;
		return 1;
	}
	return 0;
}

int THash_Edita(THash *hash, TCidade cidade) {
	int i = THash_H(hash, cidade);
	return TArvore_Edita(&hash->raiz[i], cidade);
}

int THash_Excluir(THash *hash, TCidade cidade) {
	int i = THash_H(hash, cidade);
	if (TArvore_Excluir(&hash->raiz[i], cidade) == 1) {
		hash->n--;
		return 1;
	}

	return 0;
}
void TCidade_MostrarDados(TCidade cidade, bool uf) {
	if(uf == true)
		cout << "UF: " << cidade.uf 					<< endl;
		cout << "Nome: " << cidade.nome 				<< endl;
		cout << "Populacao: " << cidade.populacao 		<< endl;
		cout << "IDH: " << cidade.IDH 					<< endl;
}

void TArvore_PesquisarTodosCentral(TNo *p) {
	if(p == NULL)
		return;

	TArvore_PesquisarTodosCentral(p->pEsq);
	TCidade_MostrarDados(p->cidade, false);
	cout << endl;
	TArvore_PesquisarTodosCentral(p->pDir);
}
/* Fim Arvore Binaria de Pesquisa */

int THash_PesquisarTodos(THash hash) {
	if(hash.n == 0)
		return 0;

	for(int i = 0; i < hash.nro_arvore; i++) {
		if (hash.raiz[i] == NULL) continue;

		cOut("DADOS DO ESTADO " + hash.raiz[i]->cidade.uf);
		TArvore_PesquisarTodosCentral(hash.raiz[i]);
	}

	return 1;
}

string strToUpper(string str) {
	for(int i = 0; i < str.size(); ++i)
		str[i] = toupper(str[i]);

	return str;
}

int main(int argc, char* argv[]) {

	int opcao;

	/*	Declaração de Variáveis	*/
	int opMenu;
	cout <<"\nDigite uma opcao:\n0-Sair\n1-Questão 1\n2-Questão 2" << endl;
	cin >>opcao;


	switch(opcao)
	{
					case 0:
					break;

					case 1:

								cout << "comprimir "<< endl;
								cout << "descomprimir "<<endl;

							 if (strcmp("-c", argv[1]) == 0)
								 {
										if (strstr(argv[3], ".hx"))
										{
												comprimir(argv[2], argv[3]);
										}
										else
										{
												cout<<"O arquivo resultante da compressao deve ter a extensao '.hx'.\n"<<endl;
												cout<<"Exemplo: \n\t./huffman -c comprima.isso nisso.hx\n"<<endl;
												return 0;
										}
								}

								else if (strcmp("-x", argv[1]) == 0)
								{
										if (strstr(argv[2], ".hx"))
										{
												descomprime(argv[2], argv[3]);
										}
										else
										{
												cout<<"O arquivo a ser descomprimido deve ter a extensao '.hx'.\n"<<endl;
												cout<<"Exemplo: \n\t./huffman -x descomprime.hx nisso.extensao\n"<<endl;
												return 0;
										}
								}
								else
								{
										cout <<"Uso: huffman [OPCAO] [ARQUIVO] [ARQUIVO]\n\n"<<endl;
										cout <<"Opcoes:\n"<<endl;
										cout <<"\t-c\tComprime\n"<<endl;
										cout <<"\t-x\tDescomprime\n"<<endl;
										cout <<"\nExemplo: ./huffman -c comprima.isso nisso.hx\n"<<endl;
										return 0;
								}
					break;

					case 2:
							THash *hash = THash_Inicia();
							TCidade *cidade = new TCidade;

							/*	Hash instanciado ? */
							if(hash == NULL || cidade == NULL) {
								cout << "Insuficient Memory !!!" << endl;
								return 1;
							}

						/*	Programa principal	*/
						do {
							cOut("DIGITE O QUE DESEJA FAZER");
							cout << "	1 - Inserir nova cidade: "				<< endl;
							cout << "	2 - Editar cidade por nome: "			<< endl;
							cout << "	3 - Excluir cidade por nome: " 			<< endl;
							cout << "	4 - Pesquisar dados de alguma cidade: " << endl;
							cout << "	5 - Exibir todos os registros: "		<< endl;
							cout << "	6 - Encerrar programa: " 				<< endl;

							cin >> opMenu;

							switch(opMenu) {
								case 1: //Inserir nova cidade;
									cin.ignore();
									cin.clear();
									cout << "Insira a UF da cidade: " 			<< endl;
									getline(cin, cidade->uf);
									cidade->uf = strToUpper(cidade->uf);
									cin.clear();
									cout << "Insira o nome da cidade: " 		<< endl;
									getline(cin, cidade->nome);
									cin.clear();

									do {
										cout << "Insira a populacao da cidade: "	<< endl;
										cin >> cidade->populacao;
									} while (cidade->populacao < 0);

									do {
										cout << "Insira o IDH da cidade (Entre 0 e 1): " << endl;
										cin >> cidade->IDH;
									} while (cidade->IDH < 0 || cidade->IDH > 1);

									cout << ((THash_Insere(hash, *cidade) == 1) ? "Cidade inserida com sucesso." :  "Cidade ja cadastrada") << endl;
									break;
								case 2: //Editar cidade
									cin.ignore();
									cin.clear();
									cout << "Insira a UF da cidade: " 			<< endl;
									getline(cin, cidade->uf);
									cidade->uf = strToUpper(cidade->uf);
									cin.clear();
									cout << "Insira o nome da cidade: " 		<< endl;
									getline(cin, cidade->nome);
									cin.clear();

									if(THash_Pesquisa(hash, cidade) == 0)
										cOut("BUSCA NAO REALIZADA - REGISTRO NAO ENCONTRADO");
									else {
										cOut("BUSCA REALIZADA COM SUCESSO");
										TCidade_MostrarDados(*cidade, true);

										do {
											cOut("DIGITE O QUE DESEJA EDITAR");
											cout << "	1 - Populacao" 			<< endl;
											cout << "	2 - IDH" 				<< endl;
											cout << "	3 - Populacao e IDH"	<< endl;
											cout << "	4 - Cancelar" 		<< endl;
											cin >> opMenu;
										} while (opMenu < 1 || opMenu > 4);

										switch(opMenu) {
											case 1:
												do {
													cout << "Insira a populacao da cidade: "	<< endl;
													cin >> cidade->populacao;
												} while (cidade->populacao < 0);
												break;
											case 2:
												do {
													cout << "Insira o novo IDH da cidade (Entre 0 e 1): " << endl;
													cin >> cidade->IDH;
												} while (cidade->IDH < 0 || cidade->IDH > 1);
												break;
											case 3:
												do {
													cout << "Insira a populacao da cidade: "	<< endl;
													cin >> cidade->populacao;
												} while (cidade->populacao < 0);

												do {
													cout << "Insira o novo IDH da cidade (Entre 0 e 1): " << endl;
													cin >> cidade->IDH;
												} while (cidade->IDH < 0 || cidade->IDH > 1);

												break;
											case 4:
												continue;
												break;
										}



										cout << ((THash_Edita(hash, *cidade) == 1) ? "Cidade alterada com sucesso." :  "Cidade nao alterada, elemento nao encontrado") << endl;
									}
									break;
								case 3:	// Excluir cidade
									cin.ignore();
									cin.clear();
									cout << "Insira a UF da cidade: " 			<< endl;
									getline(cin, cidade->uf);
									cidade->uf = strToUpper(cidade->uf);
									cin.clear();
									cout << "Insira o nome da cidade: " 		<< endl;
									getline(cin, cidade->nome);
									cin.clear();

									if(THash_Pesquisa(hash, cidade) == 0)
										cOut("BUSCA NAO REALIZADA - REGISTRO NAO ENCONTRADO");
									else {
										cOut("BUSCA REALIZADA COM SUCESSO");
										TCidade_MostrarDados(*cidade, true);
										do {
											cout << "Deseja realmente excluir esta cidade? (1 -> Sim | 0 -> Nao)"<< endl;
											cin >> opMenu;
										} while (opMenu < 0 || opMenu > 1);

										if (opMenu == 1)
											cout << ((THash_Excluir(hash, *cidade) == 1) ? "Cidade excluida com sucesso !!!" : "Erro ao excluir cidade")  << endl;
									}
									break;
								case 4:	//Buscar cidade
									cin.ignore();
									cin.clear();
									cout << "Digite a UF da cidade que deseja buscar: " 	<< endl;
									getline(cin, cidade->uf);
									cidade->uf = strToUpper(cidade->uf);
									cin.clear();
									cout << "Insira o nome da cidade que deseja buscar: " 	<< endl;
									getline(cin, cidade->nome);
									cin.clear();

									if(THash_Pesquisa(hash, cidade) == 0)
										cOut("BUSCA NAO REALIZADA - REGISTRO NAO ENCONTRADO");
									else {
										cOut("BUSCA REALIZADA COM SUCESSO");
										TCidade_MostrarDados(*cidade, true);
									}

									break;
								case 5: // Exibir todos os registros
										if(THash_PesquisarTodos(*hash) == 0)
											cOut("NENHUM REGISTRO ENCONTRADO");

									break;
								case 6: // Encerrar programa
									cOut("Obrigado por usar o programa.");
									return 0;
									break;
								default:
									cOut("Opcao Invalida. Tente novamente");
									break;
							}

						} while (opMenu != 6);
					break;


			}
	return 0;
}

char* strdup(const char* s)
{
	char *p = new char(strlen(s)+1);
	if(p)
		strcpy(p,s);
		return p;
}

NoLista* novo_no_lista(NoArvore* arvore)
{
	NoLista* novo = new NoLista;

	novo-> no = arvore;
	novo-> prox = NULL;

	return novo;
}

NoArvore* novo_no_Arvore(unsigned char letra, int frequencia, NoArvore* esq, NoArvore* dir)
{
	NoArvore* novo = new NoArvore;

	//atribui os valores a arvore
	novo ->letra = letra;
	novo ->frequencia = frequencia;
	novo ->esq = esq;
	novo ->dir = dir;

	return novo;
}

void insere_na_lista(NoLista* no, Lista* lista)
{

	if(lista -> head == NULL){
		lista -> head = no;
	}

  else if(no ->no-> frequencia < lista->head->no->frequencia)
  {
    	no ->prox = lista -> head;
    	lista -> head = no;
  }

	else
  {
    	NoLista* aux = lista->head->prox;
    	NoLista* aux2 = lista->head;

			while(aux && aux->no->frequencia <= no->no->frequencia)
			{
	    		aux2 = aux;
	    		aux = aux2->prox;
	    }

      aux2->prox = no;
      no->prox = aux;

    }
    lista->elementos++;
}

NoArvore* retira_menor_frequencia_lista(Lista* l)
{
	NoLista* aux = l->head;
	NoArvore* aux2 = aux->no;
	l->head = aux->prox;

	delete aux;
	aux = NULL;

	l->elementos--;

	return aux2;
}

void buscar_frequencia(FILE* entrada, unsigned int* lista)
{
	unsigned char c;

	while(fread(&c,1,1,entrada) >= 1)
	{
		lista[(unsigned char)c]++;
	}
	rewind(entrada);

}

bool pega_codigo(NoArvore* no, unsigned char letra, char* buffer, int tamanho)
{
    if(!(no->esq || no->dir) && no->letra == letra)
    {
    	buffer[tamanho] = '\0';
    	return true;
    }

    else
    {
    	bool encontrado = false;

    	if(no->esq)
    	{
            buffer[tamanho] = '0';

            encontrado = pega_codigo(no->esq, letra, buffer, tamanho + 1);

    	}

    	if(!encontrado && no->dir)
    	{
    		buffer[tamanho] = '1';
    		encontrado = pega_codigo(no->dir, letra, buffer, tamanho+1);
    	}

    	if(!encontrado)
    	{
    		buffer[tamanho] = '\0';
    	}

    	return encontrado;
    }
}

NoArvore* construir_arvoreHuffman(unsigned* listaBytes)
{
    lista l = {NULL, 0};

    for(int i=0; i<256; i++)
    {
    	if(listaBytes[i])
    	{
            insere_na_lista( novo_no_lista(novo_no_Arvore(i, listaBytes[i], NULL, NULL)), &l);
    	}
    }

    while(l.elementos > 1)
    {

        NoArvore* No_esq = retira_menor_frequencia_lista(&l);
        NoArvore* No_dir = retira_menor_frequencia_lista(&l);

        NoArvore* soma = novo_no_Arvore('#',No_esq->frequencia + No_dir->frequencia,No_esq,No_dir);

        insere_na_lista(novo_no_lista(soma), &l);
    }

    return retira_menor_frequencia_lista(&l);
}

void libera_arvoreHuffman(NoArvore* no)
{

	if(!no)
		return;
	else
	{
		NoArvore* esq = no->esq;
		NoArvore* dir = no->dir;

		delete no;

		libera_arvoreHuffman(esq);
		libera_arvoreHuffman(dir);
	}
}

int geraBit(FILE* entrada, int posicao, unsigned char* aux)
{

	 (posicao % 8 == 0) ? fread(aux, 1, 1, entrada) : NULL == NULL ;

	  return !!((*aux) & (1 << (posicao % 8)));
}

void erroArquivo()
{
	cout << "Arquivo nao encontrado "<< endl;
}

void comprimir(const char* arquivo_entrada, const char* arquivo_saida)
{
	clock_t inicio, final;
	double tempoGasto;
	inicio = clock();

	unsigned listaBytes[256] = {0};

	FILE* entrada = fopen(arquivo_entrada, "rb");
	if(!entrada)
	{
		erroArquivo();
	}

	FILE* saida = fopen(arquivo_saida, "wb");
	if(!saida)
	{
		erroArquivo();
	}

	buscar_frequencia(entrada, listaBytes);

  NoArvore* raiz = construir_arvoreHuffman(listaBytes);

  fwrite(listaBytes, 256, sizeof(listaBytes[0]), saida);

  fseek(saida, sizeof(unsigned int), SEEK_CUR);

  unsigned char c;
  unsigned tamanho = 0;
  unsigned char aux = 0;

  while(fread(&c,1,1,entrada) >= 1)
  {
        char buffer[1024] = {0};

        pega_codigo(raiz, c, buffer, 0);

        for(char* i = buffer; *i; i++)
        {

        	if(*i == '1')
        	{
                aux = aux | (1 << (tamanho % 8));
        	}
        	tamanho++;

        	if(tamanho % 8 == 0)
        	{
        		fwrite(&aux,1,1,saida);
        		aux = 0;
        	}
        }
    }

    fwrite(&aux, 1, 1, saida);

    fseek(saida, 256 * sizeof(unsigned int), SEEK_SET);

    fwrite(&tamanho, 1, sizeof(unsigned), saida);

    final = clock();
    tempoGasto = (double)(final - inicio) / CLOCKS_PER_SEC;

    fseek(entrada, 0L, SEEK_END);
    double tamanhoEntrada = ftell(entrada);

    fseek(saida, 0L, SEEK_END);
    double tamanhoSaida = ftell(saida);

    libera_arvoreHuffman(raiz);

    cout << "Arquivo de entrada: "<< arquivo_entrada<<" " << tamanhoEntrada/1000<<" bytes "<<endl;
    cout << "Arquivo de saida: "<< arquivo_saida<<" " << tamanhoSaida/1000<<" bytes "<<endl;
    cout << "Tempo gasto: "<<tempoGasto<<endl;
    cout << "Taxa de compressão: "<< ((tamanhoSaida*100)/tamanhoEntrada) <<endl;

    fclose(entrada);
    fclose(saida);
}

void descomprime(const char* arquivo_entrada, const char* arquivo_saida)
{
	clock_t inicio, final;
    double tempoGasto;
    inicio = clock();

    unsigned listaBytes[256] = {0};

    FILE *entrada = fopen(arquivo_entrada, "rb");
    if(!entrada)
    {
    	erroArquivo();
    }

    FILE *saida = fopen(arquivo_saida, "wb");
    if(!saida)
    {
    	erroArquivo();
    }

    fread(listaBytes, 256, sizeof(listaBytes[0]), entrada);

    NoArvore* raiz = construir_arvoreHuffman(listaBytes);

    unsigned tamanho;
    fread(&tamanho, 1, sizeof(tamanho), entrada);

    unsigned posicao = 0;
    unsigned char aux = 0;

    while (posicao < tamanho)
    {
    	NoArvore* noAtual = raiz;

    	while(noAtual->esq || noAtual->dir)
    	{
    		noAtual = geraBit(entrada, posicao++, &aux) ? noAtual->dir : noAtual->esq;
    	}

    	fwrite(&(noAtual->letra), 1, 1, saida);
    }

    libera_arvoreHuffman(raiz);

    final = clock();
    tempoGasto = (double)(final - inicio) / CLOCKS_PER_SEC;

    fseek(entrada, 0L, SEEK_END);
    double tamanhoEntrada = ftell(entrada);

    fseek(saida, 0L, SEEK_END);
    double tamanhoSaida = ftell(saida);

    cout << "Arquivo de entrada: "<< arquivo_entrada<<" " << tamanhoEntrada/1000<<" bytes "<<endl;
    cout << "Arquivo de saida: "<< arquivo_saida<<" " << tamanhoSaida/1000<<" bytes "<<endl;
    cout << "Tempo gasto: "<<tempoGasto<<endl;
    cout << "Taxa de compressão: "<< ((tamanhoSaida*100)/tamanhoEntrada) <<endl;

    fclose(saida);
    fclose(entrada);
}
