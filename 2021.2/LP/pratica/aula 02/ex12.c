#include <stdio.h>

// QUESTAO 1b LISTA 2

int fat_rec(int n);
int comb(int n, int m);

int main(){
    printf("%d\n", comb(5, 3));
    return 0;
}

int fat_rec(int n) {
    // CASO BASE
    if(n == 0) {
        return 1;
    }
    return n*fat_rec(n-1);
}

int comb(int n, int m) {
    return fat_rec(n) / (fat_rec(m) * fat_rec(n - m));
}