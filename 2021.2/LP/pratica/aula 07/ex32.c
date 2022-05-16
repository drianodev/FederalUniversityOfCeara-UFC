#include <stdio.h>

char maiuscula(char c);

int main() {
    FILE *f;

    f = fopen("arq.txt", "at");

    if(f == NULL) {
        printf("ERRO \n");
        exit(1);
    }

    fprintf(f, "\n\n\nHello world \n");
    fprintf(f, "Olá mundo \n");

    fclose(f);

    return 0;
}

char maiuscula(char c) {
    if(c >= 'a' && c <= 'z') {
        c = c - ('a' - 'A');
    }
    return c;
}