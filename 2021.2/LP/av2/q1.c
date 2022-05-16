#include <stdio.h>

int q1(char *s);

int main() {
    printf("Questão 1 \n");

    char s[121];

    printf("Digite a string: ");
    scanf("%s", s);
    printf("\n");

    printf("return %d", q1(s));

    printf("\n");
    return 0;
}

int q1(char *s){
    int tam = 0, i = 0, aux = 0;

    // PEGA O TAMANHO DA STRING
    for(int j = 0; s[j] != '\0'; j++){
        tam++;
    }

    // ÚLTIMO INDICE VÁLIDO DA STRING
    tam--;

    while(tam >= i){
        if(s[i] != s[tam])
            aux ++; // CONTA AS LESTRAS DIFERENTES
        i++;
        tam--;
    }

    if(aux == 0)
        // palíndroma
        return 1;
    else
        // não é palíndroma
        return 0;
}
