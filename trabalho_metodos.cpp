#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX

typedef struct{
	float a,b,c,d,exa,exb,exc,exd;
} Funcao;

float func (Funcao f, float x){
	float resu = f.a*pow(x,f.exa) + f.b*pow(x,f.exb) + f.c * pow(x,f.exc) + f.d * pow(x,f.exd);
	
	return resu;
}

float maximo(float a, float b)
{
	if (a>b){
		return a;
	};
	
	if (b>a){
		return b;
	}
	
	return a;
}

void Bissecao(float prec, int iteraMax, Funcao fun, float a, float b)

        {

            double erro = 1;

            int cont = 0;

            float raiz = a;

            float temp;

			float converge = 0;

	

			converge = func(fun, a) * func(fun, b);

	

			if (converge < 0)

			{

	            while (erro > prec && cont < iteraMax)

	            {

	                temp = raiz;

	                raiz = (a + b) / 2;

	                erro = fabs((raiz - temp) / raiz);

	                if (func(fun,a) * func(fun,raiz) < 0)

	                    b = raiz;

	                else

	                    a = raiz;

	                cont++;

	            }

	    	}

	    	else 

			{

				printf("\nNao Converge!\n");

	        }	

           printf("\nNumero de iteracoes efetuadas: %d \n Raiz aproximada da funcao: %0.4f\n", cont, raiz); 

        }

void PosicaoFalsa(float prec, int iteraMax, Funcao fun, float a, float b){
	
	float 	erro 	= fabs(b-a);
	float 	aoub	= 0;
	int 	itera 	= 0;
	float 	x 		= 0;
	float   converge = 0;
	
	converge = func(fun, a) * func(fun, b);
	
	if (converge < 0){
		while (fabs(func(fun, x)) > prec and erro > prec and itera < iteraMax){
		
		x = ((a*func(fun, b)) - (b*func(fun, a)))/(func(fun, b)-func(fun, a));
		
		aoub = func(fun, x) * func(fun, a);
		
		if (aoub < 0)
			b = x;
		else
			a = x;
		
		erro = fabs(b-a);
		
		itera ++;
		
		}
	
		printf("\nNumero de iteracoes efetuadas: %d \n Raiz aproximada da funcao: %0.4f\n", itera, x); 
	}
	else{
		printf("\nNao Converge!\n");
	}	
}

float df(float e, int max, Funcao f, float x)
{
	int i = 1;
	float h = 1;
	float f1, f2;
	float fDeriAnt, fDeriAt;
	// derivada da interação anterior e da atual
	float erro, erroAnt;
	float resu;

	f1 = func(f, x+h);
	f2 = func(f, x-h);
	
	fDeriAt = (f1 - f2)/(2*h);
	i++;
	while((i <= max and (erro > e)) or (erro > erroAnt) or (i == 2))
	{
		h = h/2.0;
		fDeriAnt = fDeriAt;
		erroAnt = erro;
		
		f1 = func(f, x+h);
		f2 = func(f, x-h);
		
		fDeriAt = (f1-f2)/(2*h);

		erro = fabs(fDeriAt - fDeriAnt)/maximo(fDeriAt, 1);			
		i++;
	}
	
	resu = fDeriAt;
	printf("Derivada primeira: %f", resu);
	return resu;
}


int Newton(float prec, int iteraMax, Funcao fun, float x0){
	
	int itera = 0;
	float converge = 0;
	float x1 = 0;
	float erro = prec+2;
	
	
	converge = df(prec, iteraMax, fun, x0);
	
	if (converge != 0) {
		
		while(fabs(func(fun, x1)) > prec and erro > prec and itera < iteraMax){
			
			x1 = x0 - (func(fun, x0)/df(prec, iteraMax, fun, x0));
			
			erro = fabs(x1 - x0)/MAX(x1, 1);
			
			x0 = x1;
			
			itera++;
		}
		
		printf("\nNumero de iteracoes efetuadas: %d \n Raiz aproximada da funcao: %0.4f\n", itera, x1); 
	
	}
	else{
		printf("\nNao Converge!\n");
	}		
}


void DerivadaSegunda (float prec, int iteraMax, Funcao fun, float x)
{
      float erro = 0;
      float derivada1 = 0;
      float derivada2 = 0;
      float h = 1;
      int a = 0;
      
      do{
      a++;
      derivada1 = (func (fun, (x+2*h)) - 2*(func(fun, x)) + func (fun, (x-2*h)))/((2*h)*(2*h));
      h=h/2;
      derivada2 = (func (fun, (x+2*h)) - 2*(func(fun, x)) + func (fun, (x-2*h)))/((2*h)*(2*h));
      if(derivada2>1)
          erro = (abs(derivada2 - derivada1))/derivada2;
      else
          erro = (abs(derivada2 - derivada1))/1;
      }while((iteraMax>=a)||(erro>prec));
      printf("Derivada segunda: %f ", derivada2);
      
}

void sair()
{
    printf("Método Encerrado");
}

int opcoesmetodos()
{
		int opcao, escolhido;
		printf("\n\tESCOLHA O METODO A SER USADO\n\n");
        printf("1. Metodo da Bissecao\n");
        printf("2. Metodo da Posicao Falsa\n");
        printf("3. Metodo de Newton\n");
        printf("4. Funcao Real DF\n");
        printf("5. Funcao Real DF2\n");
        printf("0. Sair\n");
        
        scanf("%d", opcao);
        
        return escolhido;
}

int opcoesfuncoes(Funcao f1, Funcao f2, Funcao f3)
{
	int escolhido;
	
	printf("1) %f x ^ %f + %f x ^ %f + %f x ^ %f + %f x ^ %f \n", f1.a, f1.exa, f1.b, f1.exb, f1.c, f1.exc, f1.d, f1.exd);
	printf("2) %f x ^ %f + %f x ^ %f + %f x ^ %f + %f x ^ %f \n", f2.a, f2.exa, f2.b, f2.exb, f2.c, f2.exc, f2.d, f2.exd);
	printf("3) %f x ^ %f + %f x ^ %f + %f x ^ %f + %f x ^ %f", f3.a, f3.exa, f3.b, f3.exb, f3.c, f3.exc, f3.d, f3.exd);
	
	scanf("%d", &escolhido);
	return escolhido;
}
int main()
{
	Funcao f1;
	f1.a = 0;
	f1.exa = 0;
	f1.b = 1;
	f1.exb = 5;
	f1.c = -2;
	f1.exc = 2;
	f1.d = 7;
	f1.exd = 1;
	
	Funcao f2;
	f2.a = 1;
	f2.exa = 3;
	f2.b = -4;
	f2.exb = 2;
	f2.c = 9;
	f2.exc = 1;
	f2.d = 6;
	f2.exd = 0;
	
	Funcao f3;
	f2.a = 1;
	f2.exa = -1;
	f2.b = 0;
	f2.exb = 0;
	f2.c = 0;
	f2.exc = 0;
	f2.d = 0;
	f2.exd = 0;
	
	int opcaoMetodo;
	int fEscolhida;
	float xo, xo2, precisao;
	int maxIt;
	Funcao fM;
	opcaoMetodo = opcoesmetodos();
	system("clear");
    fEscolhida = opcoesfuncoes(f1,f2,f3);
    system("clear");
    if (opcaoMetodo != 1 and opcaoMetodo != 2)
    {
    	printf("\nDigite o xo : ");
    	scanf("%f",xo);
	
	}
	else
	{
		printf("\nDigite o limite inferior: ");
		scanf("%f", &xo);
		printf("\nDigite o limite superior: ");
		scanf("%f", &xo2);
	}

    printf("\nDigite a precisao: ");
    scanf("%f", precisao);
    printf("\nDigite o numero máximo de iterações: ");
    scanf("%f", maxIt);
    system("clear");
    
    
    switch(fEscolhida)
	{
		case 1:
		fM = f1;
		break;
		
		case 2:
		fM = f2;
		break;
		
		case 3:
		fM = f3;
		break;	
	}

int escolhido;

	switch(opcaoMetodo)

        {
            case 1:
            	escolhido = 1;
            	Bissecao(precisao, maxIt, fM, xo, xo2);
                break;
            case 2:
            	PosicaoFalsa(precisao, maxIt, fM, xo, xo2);
                break;
            case 3:
				Newton(precisao, maxIt, fM, xo);
                break;
			case 4:
				df(precisao, maxIt, fM, xo);
				break;
			case 5: 
				DerivadaSegunda(precisao, maxIt, fM, xo);
				break;
            case 0:
                sair();
                break;
            default:
                printf("Digite uma opcao valida\n");
        }
}	
