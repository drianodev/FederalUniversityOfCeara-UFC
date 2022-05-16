#include <stdio.h>

int main(){
/*QUESTÃO 1*/
    int n1, n2, aux, pares, impares;

    printf("Digite um número: ");
    scanf("%d", &n1);

    n2 = 1;
    aux = 0;
    pares = 1;
    impares = 1;
/*------------------------------------------------------------------------------*/
    printf("Questão 1 item a)\n");

    while(n2 <= n1) {
        printf("%d\n", n2);
        aux += n2;
        n2++;
    }
    printf("soma dos números = %d\n", aux);
    printf("\n");
/*------------------------------------------------------------------------------*/
    printf("Questão 1 item b)\n");
    aux = 0;
    while(pares <= n1) {
        if(pares % 2 == 0) {
            printf("%d\n", pares);
            aux += pares;
        }
        pares++;
    }
    printf("soma dos números pares = %d\n", pares);
    printf("\n");
/*------------------------------------------------------------------------------*/
    printf("Questão 1 item c)\n");
    aux = 0;
    while(impares <= n1) {
        if(impares % 2 != 0) {
            printf("%d\n", impares);
            aux += impares;
        }
        impares++;
    }
    printf("soma dos números impares = %d\n", impares);
    printf("\n");
/*------------------------------------------------------------------------------*/
/*QUESTÃO 2*/
    int n, m;
    
    printf("Questão 2 item a)\n");
    printf("Digite um número: ");
    scanf("%d", &n);
    printf("Digite outro número: ");
    scanf("%d", &m);

    if(n % m == 0) {
        printf("O número %d é divisor de %d\n", m, n);
    } else {
        printf("O número %d não é divisor de %d\n", m, n);
    }
    printf("\n");
/*------------------------------------------------------------------------------*/
    int num, divisores;

    divisores = 1;
    
    printf("Questão 2 item b)\n");
    printf("Digite um número: ");
    scanf("%d", &num);
    printf("\n");
    
    while(divisores <= num) {
        if(num % divisores == 0) {
            printf("%d\n", divisores);
        }
        divisores++;
    }
    printf("\n");
/*------------------------------------------------------------------------------*/
    int num_perfeito, divisores_positivos, auxiliar;

    divisores_positivos = 1;
    auxiliar = 0;
    
    printf("Questão 2 item c)\n");
    printf("Digite um número: ");
    scanf("%d", &num_perfeito);
    printf("\n");
    
    while(divisores_positivos < num_perfeito) {
        if(num_perfeito % divisores_positivos == 0) {
            printf("%d\n", divisores_positivos);
            auxiliar += divisores_positivos;
        }
        divisores_positivos++;
    }
    if(num_perfeito == auxiliar) {
        printf("O número %d é um número perfeito\n", num_perfeito);
    } else {
        printf("O número %d não é um número perfeito\n", num_perfeito);
    }
    printf("\n");
/*------------------------------------------------------------------------------*/
    int num_primo, i, contador = 0;
    
    printf("Questão 2 item d)\n");
    printf("Digite um número: ");
    scanf("%d", &num_primo);
    printf("\n");
    
    for(i = 2; i <= num_primo / 2; i++) {
        if (num_primo % i == 0) {
            contador++;
        }
    }

    if(contador == 0) {
        printf("%d é um número primo\n", num_primo);
    } else {
        printf("%d não é um número primo\n", num_primo);
    }

    return 0;
}