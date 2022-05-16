#include <stdio.h>
#include <stdlib.h>

float* q7(int n, float *x, float *y);
void q8(int k, int *x);
//int q9(int n, int *v);

int main(){
//     printf("Lista 3\n");
//     printf("Questão 7\n");

//     int n;
//     float *x, *y, *z;

//     printf("Digite n: \n");
//     scanf("%d", &n);
    
//     x = (float*)malloc(n*sizeof(float));
//     y = (float*)malloc(n*sizeof(float));

//     if(x == NULL || y == NULL) {
//         printf("MEMORIA INSUFICIENTE \n");
//         return 1;
//     }

//     for (int i = 0; i < n; i++) {
//         printf("Digite um número para x[%d]: ", i);
//         scanf("%f", &x[i]);
//     }
//     printf("\n");

//     for (int j = 0; j < n; j++) {
//         printf("Digite um número para y[%d]: ", j);
//         scanf("%f", &y[j]);
//     }
//     printf("\n");

//     z = q7(n, x, y);
//     for (int k = 0; k < 2*n; k++) {
//         printf("%.1f ", z[k]);
//     }

//     printf("\n");
//     printf("---------------------------------------------\n");
//     printf("\n");
// /*-------------------------------------------*/
//     printf("Questão 8\n");

//     int tam, *v;

//     printf("Digite n: \n");
//     scanf("%d", &tam);
    
//     v = (int*)malloc(tam*sizeof(int));

//     if(v == NULL) {
//         printf("MEMORIA INSUFICIENTE \n");
//         return 1;
//     }

//     for (int l = 0; l < tam; l++) {
//         printf("Digite um número para v[%d]: ", l);
//         scanf("%d", &v[l]);
//     }
//     printf("\n");

//     q8(tam, v);

//     printf("\n");
//     printf("---------------------------------------------\n");
//     printf("\n");
/*-------------------------------------------*/
    printf("Questão 9\n");

    int num, *vetor;

    printf("Digite n: \n");
    scanf("%d", &num);
    
    vetor = (int*)malloc(num*sizeof(int));

    if(vetor == NULL) {
        printf("MEMORIA INSUFICIENTE \n");
        return 1;
    }

    for (int m = 0; m < num; m++) {
        printf("Digite um número para vetor[%d]: ", m);
        scanf("%d", &vetor[m]);
    }
    printf("\n");

    if(q9(num, vetor) > 0) {
        printf("%d-alternate \n" , q9(num, vetor));
    } else {
        printf("Não é alternate\n");
    }

    printf("\n");
    return 0;
}

float* q7(int n, float *x, float *y) {
    int i = 0, j = 0;
    float *z;

    z = (float*)malloc(2*n*sizeof(float));

    for (int k = 0; k < 2*n; k++) {
        if(i == n) {
            z[k] = y[j];
            j++;
        } else if(j == n) {
            z[k] = x[i];
            i++;
        }
        
        if(i < n && j < n) {
            if(x[i] < y[j]) {
                z[k] = x[i];
                i++;
            } else {
                z[k] = y[j];
                j++;
            }
        }
    }
    return z;
}

void q8(int k, int *x) {
    int m, j;

    for (int i = 0; i < k; i++) {
        m = 1;

        while(i + 2 * m - 1 < k) {
            j = 0;
            while(j < m) {
                if(x[i+j] != x[i+j+m]) {
                    j = m+1;
                }
                j++;
            }
            if(j == m) {
                printf("i = %d, m = %d \n", i, m);
            }
            m++;
        }
    }
    
}

int q9(int n, int *v) {
    int ip = (v[0]+1) % 2;
    int k, i = 0;

    for(k = 1; k <= n; k++) {
        if (n % k == 0) {
        
            for (i = 0; i < n; i++) {
                if (i % k == 0) {
                    ip = (ip + 1) % 2;
                }

                if (v[i] % 2 != ip) {
                    i = n + 1;
                }
            }
            if(i == n) {
                    return k;
            }
        }
    }

    return 0;
}
