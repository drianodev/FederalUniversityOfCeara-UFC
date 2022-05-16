#include <stdio.h>

char maiuscula(char c);

int main() {
    FILE *f, *fs;
    char c = 'a', saida[121], entrada[121];

    printf("Entrada: ");
    scanf("%s", entrada);

    printf("Saida: ");
    scanf("%s", saida);

    f = fopen(entrada, "rt");
    if(f == NULL) {
        printf("ERRO ENT\n");
        exit(1);
    }

    fs = fopen(saida, "wt");
    if(fs == NULL) {
        printf("ERRO SAI\n");
        exit(1);
    }

    while((c = fgetc(f)) != EOF) {
        fputc(maiuscula(c), fs);
    }

    fclose(f);
    fclose(fs);

    return 0;
}

char maiuscula(char c) {
    if(c >= 'a' && c <= 'z') {
        c = c - ('a' - 'A');
    }
    return c;
}