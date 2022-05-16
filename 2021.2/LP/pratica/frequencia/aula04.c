#include <stdio.h>              
#include <math.h>

int main(){
/*QUESTÃO 6*/
    int n, i; 
    float soma;

    printf("Questão 6\n");
    printf("Digite um número: ");
    scanf("%d", &n);
    printf("\n");

    i = 1;
    soma = 0.0;

    while (i <= n) {
        soma += i / (n - (i - 1.0));
        i++;
    } 

    printf("%.2f", soma);
    printf("\n");
    printf("\n");
/*------------------------------------------------------------------------------*/
/*QUESTÃO 7*/
    int num, j; 
    float sum;

    printf("Questão 7\n");
    printf("Digite um número: ");
    scanf("%d", &num);
    printf("\n");

    j = 1;
    sum = 0.0;

    while (j <= n) {
        sum += pow(-1.0, j - 1) / j;
        j++;
    } 

    printf("%.2f", sum);
    printf("\n");
    return 0;
}