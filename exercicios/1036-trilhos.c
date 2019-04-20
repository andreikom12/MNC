#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

char *alocavetor(int vagoes){
    float *vetor;
    vetor = (char *) malloc(vagoes * sizeof(char));
    return vetor;
}

void main(){
    int vagoes, i;
    char *vetor1, *vetor2;

    setlocale(LC_ALL,"portuguese");

    printf("\t1063 - Trilhos Novamente... Tra�ando Movimentos\n\n");
    printf("Digite o n�mero total de vag�es: ");
    scanf("%d", &vagoes);
    system("cls");
    vetor1 = alocavetor(vagoes);
    for(i = 0; i<vagoes; i++){
        printf("Digite o caracter do %d vag�o da sequ�ncia que v�m do lado A: \n", i+1);
        scanf(" %c", &vetor1[i]);
    }
    system("cls");

    vetor2 = alocavetor(vagoes);
    for(i = 0; i<vagoes; i++){
        printf("Digite o %d caractere da sequ�ncia que o chefe de organiza��o deseja como sa�da para o lado B: \n", i+1);
        scanf(" %c", &vetor2[i]);
    }



    free(vetor1);
    free(vetor2);
    system("pause");
}
