#include <stdio.h>

int main() {
    char cid[] = {'R', 'u', 's', 's', 'a', 's', '\0'}; // string é um vetor de caracteres
    char cidade[] = "Russas"; // tem diferença em aspas dupla e simples
    char cidade2[80] = "Russas";

    printf("%s ", cid);
    printf("\n");
    printf("%s ", cidade);
    printf("\n");
    
    scanf("%[aeiou]", cidade2);
    printf("%s ", cidade2);
    printf("\n");
    scanf("%[^aeiou]", cidade2);
    printf("%s ", cidade2);
    printf("\n");
    scanf("%[^\n]", cidade2);
    printf("%s ", cidade2);
    printf("\n");

    return 0;
}