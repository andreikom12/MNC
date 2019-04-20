#include <locale.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct lista{
    char informacao;
    struct lista *proximo;
}pilha;

pilha *inicializa(){
    return NULL;
}

int vazia(pilha *p){
	if(p==NULL)
		return 1;
	else
		return 0;
}

pilha *push(pilha *l, char c){
    pilha *p; //ponteiro auxiliar
	p = l; //p recebe o endere�o referente ao in�cio da lista

	int aux;
	aux = vazia(p);

	//cada n� a ser inserido na lista � criado dinamicamente, conforme aprendido em aloca��o din�mica
	pilha *novo;
	novo = (pilha*) malloc(sizeof(pilha));
	novo->informacao = c;

	//se a lista est� vazia
	if(aux){
		//incluindo o primeiro n� da lista
		novo->proximo = NULL;
	}else{
		//se a lista n�o est� vazia
		novo->proximo = l; //aponta para o "antigo primeiro n�"
	}

	//'novo' � o in�cio da lista agora
	return novo;
}

pilha *pop(pilha *l){
	pilha *p; //ponteiro auxiliar
	p = l; //p recebe o endere�o referente ao in�cio da lista
	pilha *head; //n� auxiliar para armazenar o in�cio da lista ap�s exclus�o
    //o conte�do armazenado no ponteiro 'prox' do primeiro n� da lista dever� ser o endere�o do in�cio da lista ap�s exclus�o
    head = p->proximo;
    //o antigo in�cio da lista deve passar a apontar para NULL antes de ser exclu�do
    p->proximo = NULL;
    free(p);//liberando endere�o de mem�ria no qual o primeiro n� estava armazenado
    return head;
}


void main(){
    setlocale(LC_ALL,"portuguese");

    char expressao[1001];
    int i;

    pilha *p = (pilha *) malloc(sizeof(pilha));
    inicializa(p);

    printf("\tPARENTES�S\n");
    printf("Digite a express�o: \n");
    scanf("%s",&expressao);

        for(i=0; i<strlen(expressao); i++){
            if (expressao[i] == '('){
               p= push(&p, expressao[i]);
            }
            if(expressao[i] == ')'){
                    if(vazia(p)){
                        printf("incorrect\n");
                    }else{
                   p= pop(p);
                    }

            }
        }
        if (vazia(p)){
        printf("correct\n");
        }else{
        printf("incorrect\n");
        }

system("pause");
}





