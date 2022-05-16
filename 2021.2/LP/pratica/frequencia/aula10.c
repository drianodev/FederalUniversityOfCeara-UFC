#include <stdio.h>
#include <math.h>

int palidromo(int x);
int binario(int n);

int main(){
    int x;

    printf("Lista 2\n");
    printf("Questão 4\n");
    printf("Digite um número: ");
    scanf("%d", &x);
    printf("\n");

    printf("O número %d é palindromo == %d (1-True e 2-False)\n", x, palidromo(x));

    printf("\n");
    printf("---------------------------------------------");
    printf("\n");
/*-------------------------------------------*/
    int n;

    printf("Questão 5\n");
    printf("Digite um número: ");
    scanf("%d", &n);
    printf("\n");

    printf("O número binário %d convertido para decimal == %d\n", n, binario(n));

    printf("\n");
    return 0;
}

/*-------------------------------------------*/
int palidromo(int x) {
    int i, j = 0;

    for(i = x; i != 0; i = i / 10) {
        j = j + i % 10;
        j = j * 10;
    }

    if(x == j / 10) {
        return 1;
    } else {
        return 0;
    }
}

int binario(int n) {
    int i, decimal = 0;

    for(i = 0; n != 0; i++) {
        decimal += (n % 10) * pow(2.0, i);
        n = n / 10;
    }
    return decimal;
}