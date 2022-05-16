#include <stdio.h>

// QUESTAO 1a LISTA 2
// RECURSIVIDADE - FUNCAO DENTRO DE FUNCAO

// PROTOTIPO:
int fat(int n);
int fat_rec(int n);

int main(){
    printf("%d\n", fat(5));
    printf("%d\n", fat_rec(5));
    return 0;
}

int fat(int n) {
    int i, p = 1;

    if(n == 0) {
        return 1;
    } else {
        for(i = 1; i <= n; i++) {
            p *= i;
        }
    }
    return p;
}

int fat_rec(int n) {
    // CASO BASE
    if(n == 0) {
        return 1;
    }
    return n*fat_rec(n-1);
}