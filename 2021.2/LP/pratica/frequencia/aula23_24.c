#include <stdio.h>
#include <stdlib.h>

void q3a(int **L, int n, int k);
int q3b(int **L, int n);
int q3c(int **L, int n, int k);

int main(){
    printf("Lista 4\n");
    printf("Questão 3\n");
    printf("Item a)\n");

    int **L, n, k;

    printf("Digite n: \n");
    scanf("%d", &n);

    printf("Digite k: \n");
    scanf("%d", &k);
    
    L = (int**)malloc(n*sizeof(int*));

    for (int i = 0; i < n; i++) {
        L[i] = malloc(n*sizeof(int));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("vetor %d e coluna %d -> ", i, j);
            scanf("%d", &L[i][j]);
        }
    }
    printf("\n\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", L[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");

    q3a(L, n, k);

    printf("\n\n");
/*-------------------------------------------------------------------------------------------------*/
    printf("Item b)\n");

    printf("A cidade que chega o maior número de estradas nela é a cidade %d.", q3b(L, n));

    printf("\n\n");
/*-------------------------------------------------------------------------------------------------*/
    printf("Item c)\n");

    int kc;

    printf("Digite k: \n");
    scanf("%d", &kc);
    printf("\n");

    printf("As ligações da cidade %d são de mão dupla, return %d.(1 - sim | 0 - não)", kc, q3c(L, n, kc));

    printf("\n\n");

    for (int i = 0; i < n; i++) {
        free(L[i]);
    }
    free(L);

    printf("\n");
    return 0;
}

void q3a(int **L, int n, int k) {
    int soma_linha = 0, soma_coluna = 0, i = 0;

    while(i < n) {
        soma_linha += L[k][i];
        soma_coluna += L[i][k];
        i++;
    }
    printf("k = %d -> saem da cidade = %d e chegam a cidade = %d \n", k, soma_linha, soma_coluna);
}

int q3b(int **L, int n) {
    int soma = 0, aux = 0, cidade = 0;

    for (int i = 0; i < n; i++) {
        aux = 0;
        for (int j = 0; j < n; j++) {
            if (L[j][i] > 0) {
                    aux += L[j][i];
            }
        }
        if (aux > soma) {
            soma = aux;
            cidade = i;
        }
    }

    return cidade;
}

int q3c(int **L, int n, int k) {
    int aux = 0, i = 0;

    while(i < n) {
        if (k != i) { 
            if ((L[i][k] == 1) && (L[k][i] == 1)) {
                aux++;
            }
        }
        i++;
    }
    if (aux > 0) {
        return 1;
    } else {
        return 0;
    }
}