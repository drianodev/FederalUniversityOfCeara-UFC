#include <stdio.h>

int main(){
    int x;
    printf("Digite um número: ");
    scanf("%d", &x);
    // se colocar um zero no parametro o computador considera False,
    // pois ele só considera números
    if(x%2 == 0) {
        printf("Número é par\n");
    } else {
        printf("Número é ímpar\n");
    }
    return 0;
}