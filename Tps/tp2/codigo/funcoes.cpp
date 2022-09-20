#include <iostream>
#include "funcoes.hpp"
#include <cmath>
#include <cstring>
#include <string>

using namespace std;

struct Circ
{
  double raio;
};

struct Ret
{
  double lado1, lado2;
};

struct Tri
{
  double l1, l2, l3;
};

struct FilaNo
{
  void* obj;
  int ident;
  FilaNo* prox;
};

struct Func
{
  char nome[8];
  int dia, mes;
};

struct Fila
{
  FilaNo* primeiro;
};

struct PilhaNo
{
  int info;
  PilhaNo* prox;
};

struct Pilha
{
  PilhaNo* prim;
};

struct ListaINo
{
  int ci;
  string ni;
  ListaINo* proxi;
};

struct ListaI
{
  ListaINo* primi;
};

struct ListaPNo
{
  int cp;
  string np;
  ListaPNo* proxp;
  ListaI* pratoi;
};

struct ListaP
{
  ListaPNo* primp;
};

ListaP* cria_lista()
{
  ListaP* pratos = new ListaP;

  pratos->primp = NULL;


  return pratos;
}

int lista_prato_vazia(ListaP* pratos)
{
  if(pratos->primp == NULL)
    return 1;//retorna 1 se a lista de prato está vazia

  return 0;//retorna 0 caso contrário
}

void insere_prato(ListaP* pratos, int codigo, string nome)//insere pratos
{
  ListaPNo* prato = new ListaPNo;

  prato->cp = codigo;
  prato->np = nome;

  prato->proxp = pratos->primp;
  pratos->primp = prato;

  ListaI* ingredientes = new ListaI;

  cout <<"Digite:\n-1: Sair"<< endl;
  do
  {
    cout <<"Digite o código do ingrediente que deseja inserir: ";
    cin >> codigo;

    if(codigo == -1)
      break;

    cout <<"\nDigite o nome do ingrediente que deseja inserir: ";
    cin >> nome;


    ListaINo* ingrediente = new ListaINo;

    ingrediente->ci = codigo;
    ingrediente->ni = nome;

    ingrediente->proxi = ingredientes->primi;
    ingredientes->primi = ingrediente;

  }while(1);

  pratos->primp->pratoi = ingredientes;
}

int apagar_prato(ListaP* pratos, int codigo)//apaga um prato dado seu código
{
  ListaPNo* p = pratos->primp;
  ListaPNo* antp = NULL;

  ListaINo* i;
  ListaINo* iaux;


  while(p != NULL && p->cp != codigo)//procura elemento
  {
    antp = p;
    p = p->proxp;
  }

  if(p != NULL)//se achar p é diferente de NULL
  {
    if(antp == NULL)//se o anterior for nulo insere na primeira posicao
    {
      pratos->primp = p->proxp;

    }

    else//remove no meio ou no final
    {
      antp->proxp = p->proxp;

    }

    i = p->pratoi->primi;

    while(i != NULL)//deleta ingredientes
    {
        iaux = i->proxi;

        delete i;

        i = iaux;
    }

    delete p;//deleta prato

    return 1;//retorna 1 se a remoção do prato foi um sucesso
  }

  return 0;//se não achar o código do prato retorna 0
}

void imprime_prato_ingredientes(ListaP* pratos, int codigo)//inprime todos os ingredientes de um prato dado o código
{
  ListaPNo* p = pratos->primp;

  int contador = 0;


  while(p != NULL && p->cp != codigo)//procura elemento
  {
    p = p->proxp;
  }

  if(p != NULL)//achou o codigo
  {
    cout <<"\nPrato\nNome: " << p->np << "\nCódigo: "<< p->cp << endl;

    for(ListaINo* i = p->pratoi->primi; i != NULL; i = i->proxi)
    {
      contador++;

      cout <<"\nIngrediente " << contador << " :\nNome: " <<i->ni <<"\nCódigo: " << i->ci << endl;
    }
  }

  else//NÃO ACHOU O CÓDIGO
  {
    cout <<"\nCódigo não existe" << endl;
  }
}

void adicionar_ingrediente(ListaP* pratos, int codigo, string nom, int cod)//adiciona um ingrediente em um prato dado o código
{
  ListaPNo* p = pratos->primp;
  ListaINo* i;


  while(p != NULL && p->cp != codigo)//procura elemento
  {
    p = p->proxp;
  }

  if(p != NULL)//achou o codigo
  {
      i = new ListaINo;
      i->ni = nom;
      i->ci = cod;

      i->proxi = p->pratoi->primi;

      p->pratoi->primi = i;
  }

  else//nao achou o código
  {
    cout <<"Código não existe" << endl;
  }
}

void deletar_ingrediente(ListaP* pratos, int codigo, string nome)//deleta ingredientes dado um código de um prato
{
  ListaPNo* p = pratos->primp;

  ListaI* aux;
  ListaINo* i;
  ListaINo* iant;

  while(p != NULL && p->cp != codigo)//procura elemento
  {
    p = p->proxp;
  }

  if(p != NULL)//se achar p é diferente de NULL
  {
    aux =  p->pratoi;
    i = aux->primi;

    while(i != NULL && i->ni != nome)//procura elemento
    {
      iant = i;
      i = i->proxi;
    }

    if(i != NULL)//se achar i é diferente de NULL
    {

      if(iant == NULL)//se o anterior for nulo insere na primeira posicao
      {
        aux->primi = i->proxi;

      }

      else//remove no meio ou no final
      {
        iant->proxi = i->proxi;
      }
    }

    else
    {
      cout <<"\nNome do ingrediente não existe" << endl;
    }

    cout <<"\nRemovido com sucesso" << endl;
  }

  else
  {
    cout <<"\nCódigo não existe" << endl;
  }
}

void lista_completa(ListaP* pratos)
{
  int contador_de_pratos = 0, contador_de_ingredientes;


  for(ListaPNo* p = pratos->primp; p != NULL; p = p->proxp)
  {
    contador_de_ingredientes = 0;
    contador_de_pratos++;

    cout <<"\nPrato " << contador_de_pratos <<"\nNome: " << p->np << "\nCódigo: "<< p->cp << endl;

    for(ListaINo* i = p->pratoi->primi; i != NULL; i = i->proxi)
    {
      contador_de_ingredientes++;

      cout <<"\nIngrediente " << contador_de_ingredientes++ << " :\nNome: " <<i->ni <<"\nCódigo: " << i->ci << endl;
    }
  }
}

void libera(ListaP* pratos)
{
  ListaPNo* p = pratos->primp;
  ListaPNo* auxp;

  ListaINo* i;
  ListaINo* auxi;

  while(p != NULL)
  {
    auxp = p->proxp;

    i = p->pratoi->primi;

    while(i != NULL)
    {
      auxi = i->proxi;

      delete i;

      i = auxi;
    }
    delete p;

    p = auxp;
  }
}

Func* cria_func(int n)
{
  Func* f = new Func[n];

  return f;
}

void define_func(Func* f)
{
  strcpy(f[0].nome, "Kevin");
  f[0].dia = 22;
  f[0].mes = 1;

  strcpy(f[1].nome, "Aquila");
  f[1].dia = 22;
  f[1].mes = 1;

  strcpy(f[2].nome, "Barbara");
  f[2].dia = 15;
  f[2].mes = 3;

  strcpy(f[3].nome, "Ivone");
  f[3].dia = 10;
  f[3].mes = 4;

  strcpy(f[4].nome, "Avel");
  f[4].dia = 7;
  f[4].mes = 5;

  strcpy(f[5].nome, "Fabiana");
  f[5].dia = 9;
  f[5].mes = 4;
}

void imprime_func(Func* f, int n)
{
  for(int i = 0; i < n; i++)
  {
    cout <<"\nFuncionário: "<< i+1 << endl;
    cout <<"Nome: " << f[i].nome << endl;
    cout <<"Mês: " << f[i].mes << endl;
    cout <<"Dia: " << f[i].dia << endl;
  }
}

Pilha* cria_pilha()
{
  Pilha* p = new Pilha;
  p->prim = NULL;

  return p;
}

void pilha_push(Pilha* p, int v)
{
  PilhaNo* aux = new PilhaNo;
  aux->info = v;

  aux->prox = p->prim;
  p->prim = aux;
}

void pilha_pop(Pilha* p)
{
  PilhaNo* aux;

  aux = p->prim;

  p->prim = aux->prox;

  delete aux;
}

int pilha_vazia(Pilha* p)
{
  if(p->prim == NULL)
    return 1;

  return 0;
}

void deleta_pilha(Pilha* p)
{
  PilhaNo* aux1, *aux2;
  aux1 = p->prim;

  while(aux1 != NULL)
  {
    aux2 = aux1->prox;

    delete aux1;

    aux1 = aux2;
  }
}


Fila* cria_fila()
{
  Fila* f = new Fila;
  f->primeiro = NULL;

  return f;
}

void libera_fila(Fila* f)
{
  int aux;
  Circ* circulo;
  Ret* retangulo;
  Tri* triangulo;


  FilaNo* fi = f->primeiro;

  while(fi != NULL)
  {
    FilaNo* fil = fi->prox;

    aux = fi->ident;

    switch(aux)
    {
      case 1://é um circulo

        circulo = (Circ*)fi->obj;

        if(circulo != NULL)
        {
          delete circulo;
        }

      break;

      case 2://é um retangulo

        retangulo =  (Ret*)fi->obj;

        if(retangulo != NULL)
        {
          delete retangulo;
        }

      break;

      case 3://é um triangulo

        triangulo = (Tri*)fi->obj;

        if(triangulo != NULL)
        {
          delete triangulo;
        }

      break;
    }


    delete fi;

    fi = fil;
  }
}

int fila_vazia(Fila* f)
{
  if(f->primeiro == NULL)
    return 1;

  return 0;
}

void cria_e_insere(Fila* f, int id)
{
  FilaNo* novo = new FilaNo;
  double var1, var2, var3;
  Circ* circulo;
  Ret* retangulo;
  Tri* triangulo;
  FilaNo* aux;

  switch(id)
  {
    case 1://circulo

      cout <<"\nDigite o raio: ";
      cin >> var1;

      circulo = new Circ;
      circulo->raio = var1;

      novo->obj = circulo;
      novo->ident = 1;

    break;

    case 2://retangulo

      cout <<"\nDigite a base e a altura: ";
      cin >> var1 >> var2;

      retangulo = new Ret;

      retangulo->lado1 = var1;
      retangulo->lado2 = var2;

      novo->obj = retangulo;
      novo->ident = 2;

    break;

    case 3://triangulo

      cout <<"\nDigite os 3 lados: ";
      cin >> var1 >> var2 >> var3;

      triangulo = new Tri;

      triangulo->l1 = var1;
      triangulo->l2 = var2;
      triangulo->l3 = var3;

      novo->obj = triangulo;
      novo->ident = 3;

    break;
  }

  if(fila_vazia(f))
  {
    novo->prox = f->primeiro;
    f->primeiro = novo;
  }

  else
  {
    for(FilaNo* p = f->primeiro; p != NULL; p = p->prox)
    {
      if(p->prox == NULL)
        aux = p;
    }

    aux->prox = novo;
    novo->prox = NULL;
  }
}

int remover(Fila* f)
{
  if(fila_vazia(f))
    return 0;

  else
  {
    FilaNo* aux = f->primeiro;

    f->primeiro = aux->prox;

    if(aux != NULL)
      delete aux;
  }

  return 1;
}

void calcula_area(Fila* f)
{
  double area, s;
  int contador = 0;

  Circ* circulo;
  Ret* retangulo;
  Tri* triangulo;

  for(FilaNo* p = f->primeiro; p != NULL; p = p->prox)
  {
    contador++;

      switch(p->ident)
      {
        case 1://area do circulo

          circulo = (Circ*)p->obj;

          area = 3.14*pow(circulo->raio, 2);


        break;

        case 2://area do retangulo

          retangulo = (Ret*)p->obj;

          area = (retangulo->lado1)*(retangulo->lado2);


        break;

        case 3://area do triangulo

          triangulo = (Tri*)p->obj;
          s = (triangulo->l1 + triangulo->l2 + triangulo->l3)/2;

          area = sqrt(s*(s-triangulo->l1)*(s-triangulo->l2)*(s-triangulo->l3));

        break;
      }

    cout <<"\nÁrea " << contador <<": "<< area << endl;
  }
}

void imprime_obj(Fila* f)
{
  int contador = 0;
  Circ* circulo;
  Ret* retangulo;
  Tri* triangulo;

  cout << endl;

  for(FilaNo* p = f->primeiro; p != NULL; p = p->prox)
  {
    contador++;

    cout <<"Figura " << contador << endl;

    switch(p->ident)
    {
      case 1://é um circulo

        circulo = (Circ*)p->obj;

        cout <<"Círculo" << endl;
        cout <<"Raio: " << circulo->raio << endl << endl;

      break;

      case 2://é um retangulo

        retangulo =  (Ret*)p->obj;

        cout <<"Retângulo" << endl;
        cout <<"Base: " << retangulo->lado1 << endl;
        cout <<"Altura: " << retangulo->lado2 << endl << endl;

      break;

      case 3://é um triangulo

        triangulo = (Tri*)p->obj;

        cout <<"Triângulo" << endl;
        cout <<"Lado 1: " << triangulo->l1 << endl;
        cout <<"Lado 2: " << triangulo->l2 << endl;
        cout <<"Lado 3: " << triangulo->l3 << endl << endl;

      break;
    }
  }
}

void atualiza(Fila* f, int n)
{
  int var1, var2, var3;
  Circ* circulo;
  Ret* retangulo;
  Tri* triangulo;
  FilaNo* aux;

  FilaNo* p = f->primeiro;

  for(int contador = 0; contador < n; contador++)
  {
    aux = p;
    p = p->prox;
  }//aux receberá a posicao desejada

  switch(aux->ident)
  {
    case 1://é um circulo

      circulo = (Circ*)aux->obj;

      cout <<"Círculo" << endl;
      cout <<"Raio: " << circulo->raio << endl << endl;

      cout <<"Digite o novo raio: ";
      cin >> var1;
      circulo->raio = var1;

    break;

    case 2://é um retangulo

      retangulo =  (Ret*)p->obj;

      cout <<"Retângulo" << endl;
      cout <<"Base: " << retangulo->lado1 << endl;
      cout <<"Altura: " << retangulo->lado2 << endl << endl;
      cout <<"Digite a nova base e nova altura: ";
      cin >> var1 >> var2;

      retangulo->lado1 = var1;
      retangulo->lado2 = var2;

    break;

    case 3://é um triangulo

      triangulo = (Tri*)p->obj;

      cout <<"Triângulo" << endl;
      cout <<"Lado 1: " << triangulo->l1 << endl;
      cout <<"Lado 2: " << triangulo->l2 << endl;
      cout <<"Lado 3: " << triangulo->l3 << endl << endl;

      cout <<"Digite os três lado do triângulo: ";
      cin >> var1 >> var2 >> var3;

      triangulo->l1 = var1;
      triangulo->l2 = var2;
      triangulo->l3 = var3;

    break;
  }
}

void QuickSort_particao(Func *v, int esq , int dir , int *i, int *j)
{
  Func  pivo , aux;

  *i = esq; *j = dir;

  pivo = v[(*i + *j)/2]; /*  obtem o pivo x */

  do
  {
    while  (!( pivo.mes  <= v[*i].mes))
      (*i)++;

    while (pivo.mes  <= v[*j].mes)
      (*j) --;

    if (*i <= *j)
    {

      aux = v[*i];

      v[*i] = v[*j];

      v[*j] = aux;

      (*i)++;
      (*j)--;
    }

  } while  (*i <= *j);
}

void QuickSort_iter(Func *v, int n)
{
  Pilha*  pilha_dir;
  Pilha*  pilha_esq;

  int esq , dir , i, j;

  pilha_dir = cria_pilha();
  pilha_esq = cria_pilha();

  esq = 0;

  dir = n-1;

  pilha_push(pilha_dir , dir);
  pilha_push(pilha_esq , esq);

  do
  {
      if (dir > esq)
      {

        QuickSort_particao(v, esq , dir , &i, &j);

        pilha_push(pilha_dir , j);
        pilha_push(pilha_esq , esq);

        esq = i;
      }

      else
      {
        pilha_pop(pilha_dir);
        pilha_pop(pilha_esq);
      }
    } while  (!pilha_vazia(pilha_dir));

    quick_dia(v, n);
    quick_nome(v, n);
    deleta_pilha(pilha_dir);
    deleta_pilha(pilha_esq);

}

void quick_dia(Func* f, int n)
{
  Func aux;

  for(int i = 0; i < n; i ++)
    for(int j = i; j < n; j++)
      if(f[i].mes == f[j].mes)
        if(f[i].dia > f[j].dia)
        {
          aux = f[i];
          f[i] = f[j];
          f[j] = aux;
        }
}

void quick_nome(Func* f, int n)
{
  Func aux;

  for(int i = 0; i < n; i ++)
    for(int j = i; j < n; j++)
      if(f[i].dia == f[j].dia)
        if(strcmp(f[i].nome, f[j].nome) >= 1)
        {
          cout << "\n\n" << strcmp(f[i].nome, f[j].nome) << endl;
          aux = f[i];
          f[i] = f[j];
          f[j] = aux;
        }
}

int busca(Func* vet, int chave, int Tam, int& lim_e, int& lim_d)
{
     int aux;
     int inf =  0;
     int sup = Tam-1;
     int meio;
     while (inf <= sup)
     {
          meio = (inf + sup)/2;
          if (chave == vet[meio].mes)
          {
              aux = meio;
              lim_e = aux;

              meio--;
              while(vet[meio].mes == chave)
              {
                  lim_e--;
                  meio--;
              }

              meio = aux;
              lim_d = aux;
              meio++;

              while(vet[meio].mes == chave)
              {
                lim_d++;
                meio++;
              }

              return 1;

          }
          if (chave < vet[meio].mes)
               sup = meio-1;
          else
               inf = meio+1;
     }
     return -1;
}

void niver(Func* vet, int lim_e, int lim_d)
{
    for(int i = lim_e; i <= lim_d; i++)
      cout << vet[i].nome  << ", ";

    cout << endl;
}
