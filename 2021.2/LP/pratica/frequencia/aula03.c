#include <stdio.h>

int main(){
/*QUESTÃO 3*/
    int x, y; 

    printf("Questão 3\n");
    printf("Digite um número: ");
    scanf("%d", &x);
    printf("Digite outro número maior que o anterior: ");
    scanf("%d", &y);
    printf("\n");
/*------------------------------------------------------------------------------*/
    printf("Item a)\n");

    int contador_pares, pares;

    pares = 0;
    contador_pares = x;

    while(contador_pares <= y) {
        if(contador_pares % 2 == 0) {
            pares += contador_pares;
        }
        contador_pares++;
    }
    printf("soma dos números pares do intervalo [%d,%d] = %d", x, y, pares);
    printf("\n");
/*------------------------------------------------------------------------------*/
    printf("Item b)\n");

    int contador_perf, aux_perf, perfeitos_total, perfeitos_parcial;

    perfeitos_parcial = 0;
    perfeitos_total = 0;

    for (contador_perf = x; contador_perf <= y; contador_perf++) {
        perfeitos_parcial = 0;
        for(aux_perf = 1; aux_perf < contador_perf; aux_perf++){
            if(contador_perf % aux_perf == 0) {
                perfeitos_parcial = perfeitos_parcial + aux_perf;
            }
        }
        if(perfeitos_parcial == contador_perf){
            perfeitos_total += contador_perf;
        }
    }

    printf("soma dos números perfeitos do intervalo [%d,%d] = %d", x, y, perfeitos_total);
    printf("\n");
/*------------------------------------------------------------------------------*/
    printf("Item c)\n");

    int contador_primos, aux_primos, primos_parcial, primos_total;

    primos_parcial = 0;
    primos_total = 0;

    for(contador_primos = x; contador_primos <= y; contador_primos++){
        primos_parcial = 0;
        for(aux_primos = 1; aux_primos <= contador_primos; aux_primos++){
            if(contador_primos % aux_primos == 0) {
                primos_parcial ++;
            }
        }
       if(primos_parcial == 2) {
            primos_total += contador_primos;
        }
    }

    printf("soma dos números primos do intervalo [%d,%d] = %d", x, y, primos_total);
    printf("\n");
    printf("\n");
/*------------------------------------------------------------------------------*/
/*QUESTÃO 4*/
    int n, i, contador1, contador2, aux1, aux2, primo1, primo2; 

    printf("Questão 4\n");
    printf("Digite um número: ");
    scanf("%d", &n);
    printf("\n");

    primo1 = 0;
    primo2 = 0;
    aux1 = 0;
    aux2 = 0;

    for(i = 1; i <= n; i++){
        contador1 = 0;
        for(aux1 = 1; aux1 <= i; aux1++){
            if(i % aux1 == 0) {
                contador1 ++;
            }
        }
        if(contador1 == 2 && i != 2) {
            primo1 = i;
            primo2 = i + 2;
            contador2 = 0;
            for(aux2 = 1; aux2 <= primo2; aux2++) {
                if(primo2 % aux2 == 0) {
                    contador2++;
                }
            }
            if(contador2 == 2) {
                printf("Primos gêmeos são %d e %d\n", primo1, primo2);
            }
        }
    }

    printf("\n");
    printf("\n");
/*------------------------------------------------------------------------------*/
/*QUESTÃO 5*/
    int auxiliar, num;
    float n_harmonico;

    printf("Questão 5\n");
    printf("Digite um número maior que zero: ");
    scanf("%d", &num);
    printf("\n");
    
    n_harmonico = 0;
    auxiliar = 1;

    while(auxiliar <= num) {
        n_harmonico += (1.0 / auxiliar);
        auxiliar++;
    }

    printf("O número harmônico H%d = %f \n", num, n_harmonico); 
    
    return 0;
}