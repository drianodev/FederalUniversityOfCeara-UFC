#include <stdio.h>

void q1(char *c, char *palavra);
void q4(char *s);

int main() {
    printf("Lista 5 \n");
    printf("Questão 1 \n");

    char c[2], palavra[61];

    printf("Digite uma palavra: ");
    scanf("%s", palavra);
    printf("\n");
    printf("Digite um caracter: ");
    scanf("%s", c);
    printf("\n");

    printf("A palavra armazenada foi: %s \n", palavra);
    printf("O caracter armazenado foi: %s \n", c);

    q1(c, palavra);
    printf("\n");
/*-------------------------------------------------------------------------------------------------*/  
    printf("Questão 4 \n");

    char s[61];

    printf("Digite uma palavra: ");
    scanf("%s", s);
    printf("\n");

    printf("A palavra armazenada foi: %s \n", s);

    q4(s);

    printf("\n");
    return 0;
}

void q1(char *c, char *palavra){
    int contador = 0;

    for(int i = 0; i < sizeof(palavra); i++) {
        if(c[0] == palavra[i]) {
            contador++;
        }
    }

    printf("Número de caracteres iguais = %d \n", contador);
}


void q4(char *s){

    for(int i = 0; i < sizeof(s); i++) {
        if(s[i] >= 'a' && s[i] <= 'z') {
            s[i] = s[i] - ('a' - 'A');
        }
    }
    printf("A palavra com letras maiúsculas correspondentes = %s \n", s);
}