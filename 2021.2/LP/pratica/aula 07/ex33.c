#include <stdio.h>

char maiuscula(char c);

int main() {
    FILE *f;
    char c = 'a', s[51];

    f = fopen("arq.txt", "rt");

    if(f == NULL) {
        printf("ERRO \n");
        exit(1);
    }

    while(fgets(s, 50, f) != NULL){
        printf("%s", s);
    }

    fclose(f);

    return 0;
}

char maiuscula(char c) {
    if(c >= 'a' && c <= 'z') {
        c = c - ('a' - 'A');
    }
    return c;
}