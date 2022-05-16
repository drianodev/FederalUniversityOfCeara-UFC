#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void q1(int n, float *x, float *y);

int main(){
    int n;
    float *x, *y;

    printf("Digite n: \n");
    scanf("%d", &n);
    
    x = (float*)malloc(n*sizeof(float));
    y = (float*)malloc(n*sizeof(float));

    if(x == NULL || y == NULL) {
        printf("MEMORIA INSUFICIENTE \n");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        printf("Digite um número para x[%d]: ", i);
        scanf("%f", &x[i]);
    }
    printf("\n");

    for (int j = 0; j < n; j++) {
        printf("Digite um número para y[%d]: ", j);
        scanf("%f", &y[j]);
    }
    printf("\n");

    q1(n, x, y);

    printf("\n");
    return 0;
}

void q1(int n, float *x, float *y) {
    float dist_euclid = 0, soma = 0;

    for(int i = 0; i < n; i++) {
        soma += pow((x[i] - y[i]), 2);
    }
    dist_euclid = sqrt(soma);
    printf("A distancia euclidiana desses dois vetores é %.2f", dist_euclid);

    printf("\n");
}