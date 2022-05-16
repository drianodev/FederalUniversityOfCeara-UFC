#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int funcA(int n);
void funcB(int n);

int main(){
    int n;

    printf("Digite n: \n");
    scanf("%d", &n);
    printf("\n");

    funcA(n);
    funcB(n);

    printf("\n");
    return 0;
}

int funcA(int n){
    int verifica = 0;

    for (int k = 1; k <= n; k++) {

        verifica = pow(2, k) - 1;

        if(verifica == n) {
            printf("retorna 1\n");
            printf("\n");
            return 1;
        } else if(verifica > n) {
            printf("retorna 0\n");
            printf("\n");
            return 0;
        }
    }
    
}

void funcB(int n){
    int verifica = 0;

    for (int k = 1; k <= n; k++) {
        for(int i = 1; i <= k; i++) {

            verifica = pow(2, i) - 1;

            if(verifica == k) {
                printf("%d\n", verifica);
            }
        } 
    }
}