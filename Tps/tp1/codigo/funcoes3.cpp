#include <iostream>
#include "funcoes3.hpp"
using namespace std;

int potenciacao(int base, int expoente)//função recurssiva que calcula portência
{
  if(expoente == 0)
    return 1;

  else
    if(expoente % 2 == 0)
      base = potenciacao(base*base, expoente/2);

    else
      base *= potenciacao(base*base, (expoente-1)/2);


  return base;

}
