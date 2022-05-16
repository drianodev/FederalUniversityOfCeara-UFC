#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float media(int n, float *x);
float variancia(int n, float *x);
float desvio(int n, float *x);
void q6(int vetor, float *z);

int main(){
    int n;
    float *x, med = 0, var = 0, des = 0;

    printf("Lista 3 \n");
    printf("Questão 3° \n");
    printf("Digite n: \n");
    scanf("%d", &n);

    x = (float*)malloc(n*sizeof(float));

    if(x == NULL) {
        printf("MEMORIA INSUFICIENTE \n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Digite x%d: ", i);
        scanf("%f", &x[i]);
        med += x[i];
    }

    med = media(n, x);
    
    var = variancia(n, x);

    des = desvio(n, x);

    printf("media = %.2f\n", med);
    printf("variancia = %.2f\n", var);
    printf("desvio padrão = %.2f\n", des);

    printf("\n");
    printf("---------------------------------------------\n");
    printf("\n");
/*-------------------------------------------*/
    printf("Questão 6\n");

    int vetor;
    float *z;

    printf("Digite n: \n");
    scanf("%d", &vetor);
    
    z = (float*)malloc(vetor*sizeof(float));

    if(z == NULL) {
        printf("MEMORIA INSUFICIENTE \n");
        return 1;
    }

    for (int l = 0; l < vetor; l++) {
        printf("Digite um número para z[%d]: ", l);
        scanf("%f", &z[l]);
    }
    printf("\n");

    q6(vetor, z);

    printf("\n");
    return 0;
}

float media(int n, float *x) {
    float med = 0;

    for (int i = 0; i < n; i++) {
        med += x[i];
    }

    return  med = med / (float)n;
}

float variancia(int n, float *x) {
    float med = media(n, x);
    float var = 0;

    for (int i = 0; i < n; i++) {
        var = var + (x[i] - med) * (x[i] - med);
    }

    return var = var / (float)n;
}

float desvio(int n, float *x) {
    float var = variancia(n, x);
    float des = 0;

    des = sqrt(var);

    return des;
}

void q6(int vetor, float *z) {
    int aux = 0, i, j;

    while(i < vetor) {
        j = 0;
        while (j < i) {
            if (z[i] == z[j]) {
                j = i + 1;
            }
            j++;
        }

        if (i == j) {
            aux = 1;
            for (j = i+1; j < vetor; j++) {
                if (z[i] == z[j]) {
                    aux++;
                }
            }
            if (aux == 1) {
                printf("%.1f ocorre 1 vez.\n", z[i]);
            } else {
                printf("%.1f ocorre %d vez.\n", z[i], aux);
            }
        }
        i++;
    }
    
}