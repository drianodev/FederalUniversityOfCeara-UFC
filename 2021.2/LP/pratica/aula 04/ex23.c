#include <stdio.h>

int main() {
    int m, n;
    float **M, aux = 3.0;

    printf("Digite m: \n");
    scanf("%d", &m);

    printf("Digite n: \n");
    scanf("%d", &n);
    
    M = (float**)malloc(m*sizeof(float*)); 
    
    for (int i = 0; i < m; i++) {
        M[i] = malloc(n*sizeof(float));
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            M[i][j] = aux;
            aux += 3.0;
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.0f ", M[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < m ; i++) {
        free(M[i]);
    }
    free(M);
    
    return 0;
}