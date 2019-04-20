// Implementa��o do M�todo da Bissec��o
// Giovanna Simioni
// Disciplina: M�todos Num�ricos e Computacionais

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

double epson, a, b, fa, fb, raiz, pontoMedio, fPontoMedio;
int k=0;

double funcao (double x){
    double y;
    //y = (3*(powf(x, 2)))-1;
    //y = (powf(x, 3) - (4 * powf(x, 2)) + x + 6);
    return y;
}

double bissecao(double a, double b, double epson){

    fa = funcao(a);
    fb = funcao(b);
    fPontoMedio = funcao(pontoMedio);

    while((fabs(b-a)> epson) && (fabs(funcao(pontoMedio))> epson)){ //erro de crit�rio de parada

        pontoMedio = (a+b)/2;
        printf("Ponto m�dio = %lf\n", pontoMedio);
        fPontoMedio = funcao(pontoMedio);
        printf("f(ponto m�dio) = %lf\n\n", fPontoMedio);

        if ((funcao(a)*funcao(pontoMedio))<0){
            b = pontoMedio;
            printf("b = %lf\n", b);
            fb = fPontoMedio;
            printf("f(b) = %lf\n\n", fb);
        }else if ((funcao(a)*funcao(pontoMedio))>0){
            a = pontoMedio;
            printf("a = %lf\n", a);
            fa = fPontoMedio;
            printf("f(a) = %lf\n\n", fa);
            }
            k++;
}

    return pontoMedio;
}
void main(){
    setlocale(LC_ALL,"portuguese");

    printf("\tMNC: M�todo da Bisse��o\n");
    printf("Digite a precis�o: \n");
    scanf("%lf", &epson);
    printf("Entre com o primeiro n�mero do intervalo: \n");
    scanf("%lf", &a);
    printf("Entre com o segundo n�mero do intervalo: \n");
    scanf("%lf", &b);
    system("cls");
    printf("Seu intervalo � [%lf ; %lf]\n", a, b);
    fa = funcao(a);
    printf("f(a) = %lf\n", fa);
    fb = funcao(b);
    printf("f(b) = %lf\n", fb);
    printf("\n");
    printf("\n");

    //verificar se fa e fb tem sinais opostos, se bolzano � satisfeito
    if (fa*fb > 0){
        printf("O m�todo da bisse��o n�o pode ser utilizado, pois n�o � satisfeito o Teorema de Bolzano nesse intervalo. :( \n");
    }else if (fabs(funcao(a)) < epson){ //verificar se |f(a)| < epson, ou seja, f(a) j� � raiz
        printf("F(a) j� � a ra�z, ou seja, |f(%lf)| < precis�o requerida de %lf.\n", a, epson);
         printf("|f(%lf)| = %lf < precis�o de %lf.\n", a, fabs(funcao(a)), epson);
         printf("\n");
    }else if (fabs(funcao(b)) < epson){ //verificar se |f(b)| < epson, ou seja, f(b) j� � raiz
        printf("F(b) j� � a ra�z, ou seja, |f(%lf)| < precis�o requerida de %lf.\n", b, epson);
        printf("|f(%lf)| = %lf < precis�o de %lf.\n", b, fabs(funcao(b)), epson);
        printf("\n");
    }else{
        pontoMedio = bissecao(a, b, epson);
        printf("Raiz aproximada = %lf e |f(%lf)|= %lf\n\n", pontoMedio, pontoMedio, fabs(funcao(pontoMedio)));
        printf("N�mero de itera��es feitas: %d\n", k);
    }

    system("pause");
}
