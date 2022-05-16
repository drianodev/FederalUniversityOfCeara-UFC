#include <stdio.h>

int main() {
    char c = 'a'; // uma string utiliza apenas aspas simples
    printf("%c \n", c);
    printf("%d \n", c);
    printf("%c \n", 97);

    for(char i = 'A'; i <= 'Z'; i++) {
        printf("%c ", i);
    }
    printf("\n");

    for(char i = 'a'; i <= 'z'; i++) {
        printf("%c ", i);
    }
    printf("\n");

    for(char i = 'A'; i <= 'z'; i++) {
        printf("%c ", i);
    }
    printf("\n");

    return 0;
}