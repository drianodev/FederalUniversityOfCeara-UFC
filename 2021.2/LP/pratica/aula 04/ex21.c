#include <stdio.h>

int main() {
    // não precisa declarar o número de vetores, só de colunas [][3]
    float mat[4][3] = {{3.0, 6.0, 9.0},
                        {12.0, 15.0, 18.0},
                        {21.0, 24.0, 27.0},
                        {30.0, 33.0, 36.0}}; //vetor de vetores
    
    printf("%.1f\n", mat[1][2]);
    return 0;
}