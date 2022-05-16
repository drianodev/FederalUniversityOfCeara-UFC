#include <stdio.h>

int main(){
/*QUESTÃO 8*/
    int nPi, i, count; 
    float pi;

    printf("Questão 8\n");
    printf("Digite um número: ");
    scanf("%d", &nPi);
    printf("\n");

    count = 1;
    pi = 0;

    for(i = 1; i <= nPi; i+=2) {
        if(count % 2 != 0) {
            pi = pi + 4 / i;
        } else {
            pi = pi - 4 / i;
        }
        count++;
    }

    printf("pi = %.2f", pi);
    printf("\n");
    printf("\n");
/*------------------------------------------------------------------------------*/
/*QUESTÃO 9*/
    int num, j, fatorial; 

    printf("Questão 9\n");
    printf("Letra a)\n");
    printf("Digite um número: ");
    scanf("%d", &num);
    printf("\n");

    fatorial = 1;

    if(num == 0) {
        fatorial = 1;
    } else {
        for(j = 1; j <= num; j++) {
            fatorial *= j;
        }
    }

    printf("O fatorial de %d = %d", num, fatorial);
    printf("\n");
/*------------------------------------------------------------------------------*/

    int n, fatorN, k, fatorK, aux1, aux2, fatorNK, aux3, binominal;

    printf("Letra b)\n");
    printf("Digite um número: ");
    scanf("%d", &n);
    printf("Digite outro número, sendo menor que o anterior: ");
    scanf("%d", &k);
    printf("\n");

    fatorN = 1;
    fatorK = 1;
    fatorNK = 1;

    if(n == 0) {
        fatorN = 1;
    } else {
        for(aux1 = 1; aux1 <= n; aux1++) {
            fatorN *= aux1;
        }
    }
    printf("O fatorial de %d = %d\n", n, fatorN);

    if(k == 0) {
        fatorK = 1;
    } else {
        for(aux2 = 1; aux2 <= k; aux2++) {
            fatorK *= aux2;
        }
    }
    printf("O fatorial de %d = %d\n", k, fatorK);

    if(n - k == 0) {
        fatorNK = 1;
    } else {
        for(aux3 = 1; aux3 <= n - k; aux3++) {
            fatorNK *= aux3;
        }
    }
    printf("O fatorial de %d - %d = %d\n", n, k, fatorNK);

    binominal = fatorN / (fatorK * fatorNK);

    printf("O binominal = %d", binominal);
    printf("\n");
/*------------------------------------------------------------------------------*/
/*QUESTAO 9C NAO CONSEGUIR FAZER*/
/*------------------------------------------------------------------------------*/
/*QUESTÃO 10*/
    int termo1, termo2, auxiliar, l, fibonacci;

    printf("Questão 10\n");
    printf("Digite um número: ");
    scanf("%d", &fibonacci);
    printf("\n");

    termo1 = 0;
    termo2 = 1;

    printf("%d\n", termo1);
    printf("%d\n", termo2);

    for(l = 0; l < fibonacci; l++) {

        auxiliar = termo1 + termo2;
        termo1 = termo2;
        termo2 = auxiliar;

        printf("%d\n", auxiliar);
    }

    printf("\n");
    return 0;
}