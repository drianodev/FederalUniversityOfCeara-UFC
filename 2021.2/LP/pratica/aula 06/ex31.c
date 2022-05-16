#include <stdio.h>
#include <math.h>

struct ponto{
    float x, y;
};
typedef struct ponto Ponto;

typedef struct circulo {
    Ponto c;
    float r;
} Circulo;


float dist(Ponto *A, Ponto *B){
    float d;

    d = sqrt((B->x - A->x)*(B->x - A->x) + (B->y - A->y) * (B->y - A->y));

    return d;
}

int interior(Circulo *cir, Ponto *p){
    float d = dist(&cir->c, p);

    return (d < cir->r);
}

int main() {
    float d;

    Ponto A, B;
    Circulo cir;

    A.x = 1.0;
    A.y = 1.0;

    B.x = 5.0;
    B.y = 4.0;

    cir.c.x = 5.0;
    cir.c.y = 4.0;
    cir.r = 2.0;

    printf("A = (%.1f, %.1f)", A.x, A.y);
    printf("\n");
    printf("B = (%.1f, %.1f)", B.x, B.y);
    printf("\n");
    printf("Circulo: c = (%.1f, %.1f) r = %.1f", cir.c.x, cir.c.y, cir.r);
    printf("\n");

    d = sqrt((B.x - A.x)*(B.x - A.x) + (B.y - A.y) * (B.y - A.y));

    printf("Distancia = %.1f \n", d);

    printf("Distancia = %.1f \n", dist(&A, &B));

    printf("Interior = %d \n", interior(&cir, &A));

    return 0;
}