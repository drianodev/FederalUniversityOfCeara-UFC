#include <stdio.h>

// LETRA A)
typedef struct ponto {
    float x;
    float y;
} Ponto;

// LETRA B)
typedef struct retangulo {
    Ponto l; //esquerdo
    Ponto r; //direito
} Retangulo;

// LETRA C)
typedef struct quadrado {
    Ponto e; //esquerdo
    int lado; //tamanho do lado
} Quadrado;

// LETRA D)
typedef struct desenho {
    Ponto *P[50];
    Retangulo *R[50];
    Quadrado *Q[50];
} Desenho;

int letra_e(Ponto p, Retangulo r, Quadrado q);

int main() {

    Ponto p1, p2, p3;
    Retangulo r;
    Quadrado q;

    p1.x = 2.0;
    p1.y = 4.0;
    p2.x = 10.0;
    p2.y = 6.0;
    p3.x = 3.0;
    p3.y = 5.0;

    r.l.x = 1.0;
    r.l.y = 6.0;
    r.r.x = 9.0;
    r.r.y = 3.0;
    
    q.e.x = 3.0;
    q.e.y = 4.0;
    q.lado = 2;

    printf("%d \n", letra_e(p1, r, q));
    printf("%d \n", letra_e(p2, r, q));
    printf("%d \n", letra_e(p3, r, q));

    return 0;
}

int letra_e(Ponto p, Retangulo r, Quadrado q){

    if(p.x < r.l.x || p.x > r.r.x) {
        return 0; // está fora
    } else { // está dentro do retangulo
        if(p.x < q.e.x) {
            return 0; // fora
        } else if (p.y < (q.lado+q.e.y)){
            return 1; // dentro de ambos
        }
    }
}