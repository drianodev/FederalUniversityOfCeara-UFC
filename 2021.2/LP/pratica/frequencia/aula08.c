#include <stdio.h>

int fat_rec(int n);
int comb(int n, int m);

int main(){
    int n;

    printf("Lista 2\n");
    printf("Questão 1\n");
    printf("Digite um número: ");
    scanf("%d", &n);
    printf("\n");

    printf("item a) %d\n", fat_rec(n));
    printf("\n");
/*-------------------------------------------*/
    int n1, m;

    printf("Digite um número: ");
    scanf("%d", &n1);
    printf("\n");
    printf("Digite outro número: ");
    scanf("%d", &m);
    printf("\n");

    printf("item b) %d\n", comb(n1, m));
    printf("\n");
/*-------------------------------------------*/
    int k;

    printf("Digite um número: ");
    scanf("%d", &k);
    printf("\n");

    printf("item c)\n");
    pascal(k);
    printf("\n");

    return 0;
}
/*-------------------------------------------*/
int fat_rec(int n) {
    if(n == 0) {
        return 1;
    }
    return n*fat_rec(n-1);
}

int comb(int n, int m) {
    return fat_rec(n) / (fat_rec(m) * fat_rec(n - m));
}

void pascal(int k) {
    int i, j;

    for(i = 0; i <= k; i++) {
        for(j = 0; j <= i; j++) {
            printf("%d ", comb(i, j));
        }
        printf("\n");
    }
}