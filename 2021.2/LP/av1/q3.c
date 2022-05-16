#include <stdio.h>
#include <stdlib.h>

void q3(int n, int *v);

int main(){
    int n, *v;

    printf("Digite n: \n");
    scanf("%d", &n);
    
    v = (int*)malloc(n*sizeof(int));

    if(v == NULL) {
        printf("MEMORIA INSUFICIENTE \n");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        printf("Digite um número para v[%d]: ", i);
        scanf("%d", &v[i]);
    }
    printf("\n");

    q3(n, v);

    printf("\n");
    return 0;
}

void q3(int n, int *v) {
    int soma = 0, *S;

    S = (int*)malloc((n/2)*sizeof(int));

    if(n == 0) {
        printf("subsequência de tamanho zero tem soma %d \n", soma);
    } else {

        for (int i = 0; i <= n/2; i++) {
            S[i] = v[i + n/2];
        }
    }

    printf("A subsequência: ");
    for(int j = 0; j <= n/2; j++) {
        printf("%d ", S[j]);
        soma += S[j];
    }
    printf("\n");
    printf("soma total = %d", soma);
    printf("\n");
}