#include <stdio.h>
#include <math.h>

struct ponto{
    float x, y;
};

typedef struct ponto Ponto;

float dist(Ponto *A, Ponto *B){
    float d;

    d = sqrt((B->x - A->x)*(B->x - A->x) + (B->y - A->y) * (B->y - A->y));

    return d;
}

int main() {
    float d;

    Ponto A, B;

    A.x = 1.0;
    A.y = 1.0;

    B.x = 5.0;
    B.y = 4.0;

    printf("A = (%.1f, %.1f)", A.x, A.y);
    printf("\n");
    printf("B = (%.1f, %.1f)", B.x, B.y);
    printf("\n");

    d = sqrt((B.x - A.x)*(B.x - A.x) + (B.y - A.y) * (B.y - A.y));

    printf("Distancia = %.1f \n", d);

    printf("Distancia = %.1f \n", dist(&A, &B));

    return 0;
}