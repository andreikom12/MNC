/*
    Emerson Andrei Almeida Correa
    Ronaldo ..
    Giovana ..
    Raphael ..
    Trabalho 1 - Disciplina M√©todos Num√©ricos Computacionais
    2019 ‚Ç¢ - UNESP - UNIVERSIDADE ESTADUAL PAULISTA - *Todos os direitos reservados*
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

typedef struct{
	double a;
    double b;
    double c;
    double d;
    double elea;
    double eleb;
    double elec;
    double eled;
} Funcao;

double x0;

void cabecalho(){
    system("cls");
    printf("UNESP - UNIVERSIDADE ESTADUAL PAULISTA - 2019\nMETODOS NUMERICOS COMPUTACIONAIS");
}

void exibeFuncao(Funcao f){
    printf("F(x)= ");
    if(f.a != 0)printf("(%lf)x", f.a);
    if(f.elea != 0)printf("^%lf + ", f.elea);
    if(f.b != 0)printf("(%lf)x", f.b);
    if(f.eleb != 0)printf("^%lf + ", f.eleb);
    if(f.c != 0)printf("(%lf)x", f.c);
    if(f.elec != 0)printf("^%lf + ", f.elec);
    if(f.d != 0)printf("(%lf)", f.d);
    if(f.eled != 0)printf("^%lf", f.eled);
}

int SelecionaFuncao(Funcao f1, Funcao f2, Funcao f3){
    int f = 0;
    do{
        cabecalho();
        printf("\n1) ");
        exibeFuncao(f1);
        printf("\n2) ");
        exibeFuncao(f2);
        printf("\n3) ");
        exibeFuncao(f3);
        printf("\n0) Sair ");
        printf("\n\nSelecione a funcao desejada:");
        scanf("%d", &f);
    }while (f > 3 || f < 0);
    
    if(f==0)exit(0);

    return f;
}

void exibeMenu(Funcao f, double epson){
    cabecalho();
    printf("\n\nSelecionada: ");
    exibeFuncao(f);
    printf("\nEpson: 10^-%lf", epson);
    printf("\n\n1 - Rotina Bissecao");
    printf("\n2 - Rotina Posicao Falsa");
    printf("\n3 - Rotina Newton");
    printf("\n4 - Rotina Diferenciacao");
    printf("\n5 - Rotina Diferenciacao Grau Dois");
    printf("\n0 - Retornar");
    printf("\n\nSelecione a opcao desejada:");
}

float func (Funcao f, float x){
	float resu = f.a*pow(x,f.elea) + f.b*pow(x,f.eleb) + f.c * pow(x,f.elec) + f.d * pow(x,f.eled);
	
	return resu;
}

double bissecao(Funcao f, double lInf, double lSup, double epson, int mIte, double* raiz, int* ite){
	return 0;
}

void selecionarDadosBissecao(Funcao f, double epson){
	double lInf, lSup, mIte;
	
	cabecalho();
    printf("\n\nSelecionada: ");
    exibeFuncao(f);
    printf("\nEpson: 10^-%lf", epson);
    
    printf("\n\nEntre com o primeiro numero do intervalo: \n");
    scanf("%lf", &lInf);
    printf("\n\nEntre com o segundo numero do intervalo: \n");
    scanf("%lf", &lSup);
    
    cabecalho();
    printf("\n\nSelecionada: ");
    exibeFuncao(f);
    printf("\nEpson: 10^-%lf", epson);
    printf("\nIntervalo: [%lf ; %lf]", lInf, lSup);
    
    printf("\n\nEntre com o x da funcao: \n");
    scanf("%lf", &x0);
    
    cabecalho();
    printf("\n\nSelecionada: ");
    exibeFuncao(f);
    printf("\nEpson: 10^-%lf", epson);
    printf("\nIntervalo: [%lf ; %lf]", lInf, lSup);
    printf("\nx0: %lf", x0);
    
    printf("\n\nEntre com o max de iteracoes: \n");
    scanf("%lf", &mIte);
    
    cabecalho();
    printf("\n\nSelecionada: ");
    exibeFuncao(f);
    printf("\nEpson: 10^-%lf", epson);
    printf("\nIntervalo: [%lf ; %lf]", lInf, lSup);
    printf("\nx0: %lf", x0);
    printf("\nMaximo de iteraÁıes: %lf", mIte);    
    
    double raiz;
	int ite;
	
	bissecao(f, lInf, lSup, epson, mIte, &raiz, &ite);
    
    system("pause");
}

void selecionaEpson(Funcao f, double* epson){
	cabecalho();
	printf("\n\nSelecionada: ");
    exibeFuncao(f);
    printf("\n\nDigite o epson a ser utilizado (10^-): ");
    scanf("%lf", epson);
}

int main(){
    setlocale(LC_ALL,"portuguese");

    // funcao 1
    Funcao f;
    f.a = 1;
    f.b = 1;
    f.c = 1;
    f.d = 1;
    f.elea = 3;
    f.eleb = 2;
    f.elec = 1;
    f.eled = 1;
    //funcao 2
    Funcao f2;
    f2.a = 2;
    f2.b = 2;
    f2.c = 2;
    f2.d = 2;
    f2.elea = 4;
    f2.eleb = 3;
    f2.elec = 2;
    f2.eled = 1;
    //funcao 3
    Funcao f3;
    f3.a = 3;
    f3.b = 3;
    f3.c = 3;
    f3.d = 3;
    f3.elea = 5;
    f3.eleb = 3;
    f3.elec = 1;
    f3.eled = 1;

    int n, fSelecionada, opcao;
    Funcao def;
    double epson;

    do{
        fSelecionada = SelecionaFuncao(f, f2, f3);
        
        if(fSelecionada == 1) def = f;
	    else if(fSelecionada == 2) def = f2;
	    else if(fSelecionada == 3) def = f3;
        
        selecionaEpson(def, &epson);
        do{
        	exibeMenu(def, epson);
        	scanf("%d", &opcao);
        	
        	switch(opcao){
        		case 1: //Rotina Bissecao
        			selecionarDadosBissecao(def, epson);
        			break;
        			
        		case 2: //Rotina Posicao Falsa
        			printf("\n\nSelecionada 2");
        			break;
        		
        		case 3: //Rotina Newton
        			printf("\n\nSelecionada 3");
        			break;
        		
        		case 4: //Rotina Diferenciacao
        			printf("\n\nSelecionada 4");
        			break;
        		
        		case 5: //Rotina Diferenciacao Grau Dois
        			printf("\n\nSelecionada 5");
        			break;
        		
        		case 0: //Voltar
        			printf("\n\nSelecionada 6");
        			break;
        			
        		default:
        			break;
			}
        	
		}while(opcao);
    }while(fSelecionada);
}
