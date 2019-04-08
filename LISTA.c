#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int informacao;
    struct lista *proximo;
}node;

node *inicializa(){
    return NULL;
}

int lista_vazia(node *l){
	if(l==NULL)
		return 1;
	else
		return 0;
}

void percorre(node *l){
    node *auxiliar;
    auxiliar = l;

    while (auxiliar != NULL){
    printf("dado gravado: %d", auxiliar -> informacao);
    auxiliar = auxiliar -> proximo;
    }
}

node *insere_inicio(node *l, int num){
    node *auxiliar;
    auxiliar = l;

    int aux;
    aux = lista_vazia(auxiliar);

    node *novo = (node*) malloc(sizeof(node));
    novo -> informacao = num;

    if (aux){
    novo -> proximo = NULL;
    }else{
    novo -> proximo = l;
    }
    return novo; //'novo' � o in�cio da lista agora
}

node *excluir(node *l){
    node *auxiliar;
    auxiliar = l;

    int aux;
    aux = lista_vazia(auxiliar);

    if(aux){
        printf("\nVazia.\n");
		return l;
    }else{
        auxiliar = l; //auxiliar recebe o endere�o do in�cio da lista (n� q ser� exclu�do)
		node *cabeca; //auxiliar para armazenar o in�cio da lista ap�s exclus�o
        cabeca = auxiliar->proximo; //o 'proximo' do 1� n� da lista dever� ser o endere�o do in�cio da lista ap�s exclus�o
		auxiliar->proximo = NULL; //o antigo in�cio da lista deve passar a apontar para NULL antes excluir
		free(auxiliar); //libera endere�o de mem�ria no qual o primeiro n� estava armazenado
		printf("\nN� exclu�do!\n");

		return cabeca;
    }
}

void main (){
    node *l; //declara lista n�o inicializada

    l = inicializa();
    l = insere_inicio(l, 2);
    percorre(l);
    l= excluir(l);
    percorre(l);
}
