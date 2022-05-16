#include <stdio.h>

int q2(char **M, int n, char *s){
    int tam = 0, aux = 0;

    // PEGA O TAMANHO DA STRING
    for(int i = 0; s[i] != '\0'; i++){
        printf("%s ", s[i]);
        tam++;
    }

    // HORIZONTAL
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(s[j] == M[i][j]){
                printf("letra %s em i = %d e j = %d", s[j], i, j);
                aux++;
            }
        }
    }
    if(aux == tam) {
        return 1;
    } else {
        aux = 0;
    }

    // VERTICAL
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(s[j] == M[j][i]){
                printf("letra %s em i = %d e j = %d", s[j], i, j);
                aux++;
            }
        }
    }
    if(aux == tam) {
        return 1;
    } else {
        aux = 0;
    }

    // DIAGONAL
    for(int i = 0; i < n; i++) {
        if(s[i] == M[i][i]){
            printf("letra %s em i = %d", s[i], i);
            aux++;
        }
    }
    if(aux == tam) {
        return 1;
    } else {
        aux = 0;
    }
    
    
    return 0;
}

int main() {
    int n;

    printf("Digite o n da matriz NxN: ");
    scanf("%d", &n);

    char **M, s[25];

    M = (char**)malloc(n*sizeof(char*)); 
    
    for (int i = 0; i < n; i++) {
        M[i] = malloc(n*sizeof(char));
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("Digite um caractere para a posicao %d x %d da matriz: ", i, j);
            scanf(" %c", &M[i][j]);
        }
    }
    printf("\n");

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%c ", M[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("Digite a string: ");
    scanf("%s", s);
    printf("\n");
    
    printf("return %d \n", q2(M, n, s));
    
    return 0;
}

