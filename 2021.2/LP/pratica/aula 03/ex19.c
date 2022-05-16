#include <stdio.h>

float media(int n, float *x);
float variancia(int n, float *x);

int main(){
    int n = 3;
    float x[] = {8.0, 9.0, 10.0}, med = 0, var = 0;

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