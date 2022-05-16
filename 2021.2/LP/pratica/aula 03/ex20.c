#include <stdio.h>
#include <stdlib.h>

float media(int n, float *x);
float variancia(int n, float *x);

int main(){
    int n;
    float *x, med = 0, var = 0;

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

    printf("media = %.2f\n", med);
    printf("variancia = %.2f\n", var);
    
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