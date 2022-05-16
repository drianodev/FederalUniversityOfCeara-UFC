#include <stdio.h>

float** trp(float **M, int m, int n);

int main() {
    int m, n;
    float **M, **transposta, aux = 3.0;

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
    printf("\n\n");

    transposta = trp(M, m, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%.0f ", transposta[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for (int i = 0; i < m ; i++) {
        free(M[i]);
        free(transposta[i]);
    }
    free(M);
    free(transposta);
    
    return 0;
}

float** trp(float **M, int m, int n) {
    float **transposta;

    transposta = (float**)malloc(n*sizeof(float*)); 
    
    for (int i = 0; i < n; i++) {
        transposta[i] = malloc(m*sizeof(float));
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            transposta[j][i] = M[i][j];
        }
    }

    return transposta;
}