#include <stdio.h>

int main(){
    int n;
    float x, med = 0;

    printf("Digite n: \n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Digite x%d: ", i);
        scanf("%f", &x);
        med += x;
    }

    med = med / (float)n;

    printf("media = %.2f\n", med);
    
    return 0;
}