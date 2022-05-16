#include <stdio.h>

char maiuscula(char c);

int main() {
    char c = 'd';

    printf("%c ", maiuscula(c));
    printf("\n");

    return 0;
}

char maiuscula(char c) {
    if(c >= 'a' && c <= 'z') {
        c = c - ('a' - 'A');
    }
    return c;
}