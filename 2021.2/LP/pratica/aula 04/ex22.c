#include <stdio.h>

int main() {
    float mat[4][3] = {{3.0, 6.0, 9.0},
                        {12.0, 15.0, 18.0},
                        {21.0, 24.0, 27.0},
                        {30.0, 33.0, 36.0}}; 
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; i < 3; j++) {
            printf("%.0f ", mat[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}