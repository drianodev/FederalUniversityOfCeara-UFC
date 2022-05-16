#include <stdio.h>

int main(){
/*QUESTÃO 6*/
    int n, i; 
    float soma;

    printf("Questão 6\n");
    printf("Digite um número: ");
    scanf("%d", &n);
    printf("\n");

    i = 0;
    soma = 0.0;

    while (i < n) {
        soma += (float) (i+1) / (float) (n - i);
        i++;
    } 

    printf("%.3f", soma);
    printf("\n");
    printf("\n");
/*QUESTÃO 7*/
    int num, j; 
    float sum;

    printf("Questão 7\n");
    printf("Digite um número: ");
    scanf("%d", &num);
    printf("\n");

    j = 1;
    sum = 0.0;

    while (j <= num) {
        if(j % 2 == 0) {
            sum -= 1.0 / (float)j;
            j++;
        } else {
            sum += 1.0 / (float)j;
            j++;
        }
    } 

    printf("soma = %.3f", sum);
    
    return 0;
}