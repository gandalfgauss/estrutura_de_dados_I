#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

void exe1();
long double fatorial(int n);

void exe2();

void exe3();
double** aloca_matriz(int linha, int coluna);
void preenche_matriz(double** mat, int linha, int coluna);
void desaloca_matriz(double** mat, int linha);
void calculo_mat(double** mat, int linha, int coluna);

void exe4();
int** aloca_mat(int linha, int coluna);
void desaloca_mat(int** mat, int linha);
void preenche_mat(int** mat, int linha, int coluna);
void nota(int** mat, int linha, int coluna);


int main()
{
  int  numero_do_exe;

  while(numero_do_exe != 0)
  {

    cin >> numero_do_exe;

    switch(numero_do_exe)
    {
        case 1:
            exe1();
        break;

        case 2:
            exe2();
        break;

        case 3:
            exe3();
        break;

        case 4:
            exe4();
        break;
    }
 }
    return 0;
}

long double fatorial(int n)
{
    long double fat = 1;

    for(int i = n; i > 0; i--)
        fat *= i;

    return fat;
}

void exe1()
{
    int numero_de_calculos;
    double x;
    int n;

    long double result = 0;

    cin >> numero_de_calculos;

    for(int i = 0; i < numero_de_calculos; i++)
    {
        int expo = 0;

        cin >> x;

        x *= 0.0174532925;

        cin >> n;

        for(int j = 1; j <= n; j++)
        {
            if(j == 1)
                result = 1;

            else if(j % 2 ==  0)
            {
                expo += 2;

                result -= pow(x,expo)/fatorial(expo);
            }

            else if(j % 2 !=  0)
            {
                expo += 2;
                result += pow(x,expo)/fatorial(expo);
            }

        }
            cout << fixed << setprecision(2) << x << " " << n << " " << setprecision(5) << result << endl;
    }
}

void exe2()
{
  int numero_de_sim, meses, superar;
  double montante_a, deposito_a, rendimento_a, montante_b, rendimento_b;

  cin >> numero_de_sim;

  for(int i = 0; i < numero_de_sim; i++)
  {
    superar = 0;

    cin >> montante_a >> deposito_a >> rendimento_a >> montante_b >> rendimento_b >> meses;

     if(rendimento_a >= rendimento_b)
        cout << "Rendimento de B invalido" << endl;

    else
    {
        for(int j = 1; j <= meses; j ++)
        {
            if(j == 1)
            {
              montante_a *= 1+(rendimento_a/100.0);
              montante_b *= 1+(rendimento_b/100.0);

              montante_a += deposito_a;

            }

            else
            {
              montante_a = montante_a*(1 + (rendimento_a/100.0)) + deposito_a;
              montante_b *= (1+ (rendimento_b/100.0));
            }

            if(montante_a < montante_b && superar == 0)
              superar = j;

        }

         if(superar != 0)
            cout << fixed << setprecision(2) << montante_a << " " << setprecision(2) << montante_b << " " << superar << endl;

         else
          cout << fixed << setprecision(2) << montante_a << " " << setprecision(2) << montante_b << " B nao supera A" << endl;

      }
  }
}

double** aloca_matriz(int linha, int coluna)
{
  double** mat = new double*[linha];

  for(int i = 0; i < linha; i++)
  {
    mat[i] = new double[coluna];
  }

  return mat;
}

void preenche_matriz(double** mat, int linha, int coluna)
{

  for(int i = 0; i < linha; i++)
      for(int j = 0; j < coluna; j++)
        cin >> mat[i][j];

}

void desaloca_matriz(double** mat, int linha)
{
  if(mat != NULL)
  {
       for(int i = 0; i < linha; i++)
           if(mat[i] != NULL)
             delete [] mat[i];

       delete [] mat;
  }
}

void calculo_mat(double** mat, int linha, int coluna)
{
  double maior = 0, menor, media = 0;

  for(int i = 0; i < linha; i++)
  {
    for(int j = 0; j < coluna; j++)
    {
        media += mat[i][j];

        if(mat[i][j] > maior)
          maior = mat[i][j];
    }
  }

  menor = maior;

  for(int i = 0; i < linha; i++)
    for(int j = 0; j < coluna; j++)
      if(mat[i][j] < menor)
        menor = mat[i][j];

  media = media/(linha*coluna);

  cout << maior << " "  << menor << " ";
  cout << setprecision(4) << media << endl;

}

void exe3()
{
  int vezes, linha, coluna;
  double** mat;

  cin >> vezes;



  for(int i = 0; i < vezes; i++)
  {
      cout << endl;

      mat = NULL;

      cin >> linha >> coluna;

      mat = aloca_matriz(linha, coluna);
      preenche_matriz(mat, linha, coluna);
      calculo_mat(mat, linha,coluna);

      desaloca_matriz(mat,linha);

  }
}

int** aloca_mat(int linha, int coluna)
{

  int** mat = new int*[linha];

  for(int i = 0; i < linha; i++)
  {
    mat[i] = new int[coluna];
  }

  return mat;
}

void desaloca_mat(int** mat, int linha)
{
  if(mat != NULL)
  {
       for(int i = 0; i < linha; i++)
           if(mat[i] != NULL)
             delete [] mat[i];

       delete [] mat;
  }
}

void preenche_mat(int** mat, int linha, int coluna)
{


  for(int i = 0; i < linha; i++)
  {
      for(int j = 0; j < coluna; j++)
      {
         if(i == 0 && j == coluna-1)
           mat[i][j] = 0;

         else
            cin >> mat[i][j];
      }
  }


}

void nota(int** mat, int linha, int coluna)
{
  int chamada, acerto = 0;

  for(int i = 1; i < linha; i++)
  {
      for(int j = 0; j < coluna; j++)
      {
        chamada = mat[i][coluna-1];

        if(mat[i][j] == mat[0][j] && j != coluna-1)
          acerto++;
      }

      cout << chamada << " " << acerto << endl;

      acerto = 0;
  }
}

void exe4()
{
    int** matr;
    int numero_de_questoes, alunos, linha, coluna;

    cin >> numero_de_questoes >> alunos;

    linha = alunos + 1;
    coluna = numero_de_questoes + 1;

    matr = aloca_mat(linha, coluna);

    preenche_mat(matr,linha, coluna);
    nota(matr, linha,coluna);
    desaloca_mat(matr,linha);




}
