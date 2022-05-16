#include <stdio.h>

struct ponto{
    float x, y;
};

typedef struct ponto Ponto;

int main() {
    // Ponto == struct ponto
    Ponto A, B; // cada um com 2 floats

    A.x = 1.0;
    A.y = 1.0;

    B.x = 5.0;
    B.y = 4.0;

    printf("A = (%.1f, %.1f)", A.x, A.y);
    printf("\n");
    printf("B = (%.1f, %.1f)", B.x, B.y);
    printf("\n");

    return 0;
}