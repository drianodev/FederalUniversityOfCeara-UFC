#include <stdio.h>
#include <stdlib.h>

void q4(int n, int *v);
int q5(int tam, int *x, int *y);
void q6(int vetor, float *z);

int main(){
    printf("Lista 3\n");
    printf("Questão 4\n");

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

    q4(n, v);

    printf("\n");
    printf("---------------------------------------------\n");
    printf("\n");
/*-------------------------------------------*/
    printf("Questão 5\n");

    int tam, *x, *y;

    printf("Digite n: \n");
    scanf("%d", &tam);
    
    x = (int*)malloc(tam*sizeof(int));
    y = (int*)malloc(tam*sizeof(int));

    if(x == NULL) {
        printf("MEMORIA INSUFICIENTE \n");
        return 1;
    }
    if(y == NULL) {
        printf("MEMORIA INSUFICIENTE \n");
        return 1;
    }

    for (int j = 0; j < tam; j++) {
        printf("Digite um número para x[%d]: ", j);
        scanf("%d", &x[j]);
    }
    printf("\n");

    for (int k = 0; k < tam; k++) {
        printf("Digite um número para y[%d]: ", k);
        scanf("%d", &y[k]);
    }
    printf("\n");

    printf("O produto escalar de x e y = %d \n", q5(tam, x, y));

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

void q4(int n, int *v) {
    int maior = v[0], menor = v[0];

    for (int i = 1; i < n; i++) {
        if(maior < v[i]) {
            maior = v[i];
        } else if(menor > v[i]) {
            menor = v[i];
        }
    }
    printf("Maior = %d, menor = %d \n", maior, menor);
}

int q5(int tam, int *x, int *y) {
    int produto = 0;

    for (int i = 0; i < tam; i++) {
        produto += (x[i] * y[i]);    
    }
    return produto;
}

void q6(int vetor, float *z) {
    int aux = 0, j;

    for (int i = 0; i < vetor; i++) {
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
        
    }
}