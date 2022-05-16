#include <stdio.h>

int main(){
    int n;

    printf("Digite n: \n");
    scanf("%d", &n);

    float x[n], med = 0, var = 0;

    for (int i = 0; i < n; i++) {
        printf("Digite x%d: ", i);
        scanf("%f", &x[i]);
        med += x[i];
    }

    med = med / (float)n;

    for (int i = 0; i < n; i++) {
        var = var + (x[i] - med) * (x[i] - med);
    }
    
    var = var / (float)n;

    printf("media = %.2f\n", med);
    printf("variancia = %.2f\n", var);
    
    return 0;
}