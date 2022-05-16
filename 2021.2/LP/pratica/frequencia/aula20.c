#include <stdio.h>
#include <stdlib.h>

int q1(int **mat, int m, int n);
int q2a(int **A, int n);
int** q2b(int n);

int main(){
    printf("Lista 4\n");
    printf("Questão 1\n");

    int **mat, m, m1;

    printf("Digite m: \n");
    scanf("%d", &m);

    printf("Digite n: \n");
    scanf("%d", &m1);
    
    mat = (int**)malloc(m*sizeof(int*));

    for (int i = 0; i < m; i++) {
        mat[i] = malloc(m1*sizeof(int));
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m1; j++) {
            printf("vetor %d e coluna %d -> ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
    printf("\n\n");

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m1; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");

    printf("É matriz de permutação %d (1-sim | 0-não)\n\n", q1(mat, m, m1));

    for (int i = 0; i < m ; i++) {
        free(mat[i]);
    }
    free(mat);
/*-------------------------------------------------------------------------------------------------*/
    printf("Questão 2\n");
    printf("Item a)\n");

    int **A, n;

    printf("Digite n: \n");
    scanf("%d", &n);
    
    A = (int**)malloc(n*sizeof(int*));

    for (int i = 0; i < n; i++) {
        A[i] = malloc(n*sizeof(int));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("vetor %d e coluna %d -> ", i, j);
            scanf("%d", &A[i][j]);
        }
    }
    printf("\n\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");

    printf("A matriz é quadrado mágico %d (1-sim | 0-não)\n\n", q2a(A, n));

    for (int i = 0; i < n ; i++) {
        free(A[i]);
    }
    free(A);
/*-------------------------------------------------------------------------------------------------*/
    printf("Item b)\n");

    int N;

    printf("Digite n: \n");
    scanf("%d", &N);

    printf("\nMatriz quadrado mágico: \n\n");

    A = q2b(N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < N ; i++) {
        free(A[i]);
    }
    free(A);

    printf("\n");
    return 0;
}

int q1(int **mat, int m, int n) {
    int aux1 = 0, aux2 = 0;

    for (int i = 0; i < m; i++) {
        aux1 = aux2 = 0;
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 0) {
                aux1++;
            }
            if (mat[i][j] == 1) {
                aux2++;
            }
        }
        if(aux1 != m-1 || aux2 != 1) {
            return 0;
        }
    }

    for (int i = 0; i < n; i++) {
        aux1 = aux2 = 0;
        for (int j = 0; j < m; j++) {
            if (mat[j][i] == 0) {
                aux1++;
            }
            if (mat[j][i] == 1) {
                aux2++;
            }
        }
        if(aux1 != m-1 || aux2 != 1) {
            return 0;
        }
    }
    return 1;
}

int q2a(int **A, int n) {
    int soma = 0, aux = 0;

    for (int i = 0; i < n; i++) {
        soma += A[i][i];
    }

    for (int i = 0; i < n; i++) {
        aux += A[i][n-i-1];
    }

    if(soma != aux) {
        return 0;
    }

    for(int i = 0; i < n; i++) {
        aux = 0;
        for (int j = 0; j < n; j++) {
            aux += A[i][j];
        }
        if(soma != aux) {
            return 0;
        }
    }

    if(soma == aux) {
        return 1;
    }
}

int** q2b(int n) {
    int **A;

    A = (int**)malloc(n*sizeof(int*));

    for (int i = 0; i < n; i++) {
        A[i] = malloc(n*sizeof(int));
    }

    while (1) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                A[i][j] = rand()%n;
            }
        }
        if (q2a(A, n) == 1) {
            return A;
        }
    }
}