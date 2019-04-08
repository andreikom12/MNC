#include <stdio.h>
#include <math.h>

#define log10(x) log(x)/log(10);

float f(float x) {
   return pow(x,2)-4; // Fun��o cuja raiz deve ser determinada
}

// Implementa��o do M�todo da Bissec��o para zeros de fun��es
// Autor: Renan Birck
// Disciplina: M�todos Num�ricos e Computacionais
// Curso: Eng. El�trica - Universidade Federal de Santa Maria
// Santa Maria, maio de 2010.

int main() {

   // eps: erro
   // a0 e b0: pontos iniciais
   // tam: tamanho do intervlao
   // pm: ponto m�dio
   // it: n�mero de itera��es

   float eps, a0, b0, tam, pm, it;
   int bolzano_ok = 0; // flag do teorema de Bolzano

   printf("Digite a precis�o requerida: \n");
   scanf("%f",&eps);

   printf("Digite o intervalo onde deve se buscar a raiz (ex. [0;5] = digite 0 5): \n");
   scanf("%f %f",&a0,&b0);

   // O teorema de Bolzano (valor intermedi�rio) foi satisfeito?
   // f(a0) * f(b0) < 0 -> existe troca de sinal no intervalo dado e, portanto
   // existe raiz nele.
    bolzano_ok = (f(a0)*f(b0) > 0?0:1);

   // N�o, ent�o pedir um novo intervalo inicial.
   while(bolzano_ok == 0) {
      printf("\nIntervalo [%f;%f] n�o satisfaz as condi��es do teorema de Bolzano. Tente outro.\n Intervalo: ",a0,b0);
      scanf("%f %f", &a0, &b0);
      bolzano_ok = (f(a0)*f(b0) > 0?0:1);
   }

   // Itera��s necess�rias

   it = log10(b0 - a0);
   it -= log10(eps);
   it /= log(2);

   printf("Ser�o necess�rias %.0f itera��es.\n",ceil(it));

   // Um dos extremos do intervalo � a raiz
   if(f(a0) == 0 || f(b0) == 0)  {
      printf("O valor %f � zero da express�o. \n", f(a0)==0?a0:b0);
      return 0;
   }

   // Implementa��o do m�todo da bisec��o


   while(tam > eps) {
      tam = b0-a0;
      pm = (a0+b0)/2;
      if(f(pm) == 0) {
         printf("SOLU��O EXATA ENCONTRADA!! x = %f\n",pm);
         return 0;
      }

      if(f(a0)*f(pm) < 0)  b0 = pm; // a solu��o est� a esquerda
       else a0 = pm;  // a solu��o est� a direita

   }

   printf("Intervalo final: [%f,%f]\n Solu��o aproximada: %f",a0,b0,(a0+b0)/2);

   return 0;
}
