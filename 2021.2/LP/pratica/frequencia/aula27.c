#include <stdio.h>

char q8(char *s);

int main() {
    FILE *f;
    char s[121];

    printf("Digite uma palavra: ");
    scanf("%s", s);
    printf("\n");

    printf("A palavra armazenada foi: %s \n", s);

    f = fopen("q8.txt", "wt");
    if(f == NULL) {
        printf("ERRO \n");
        exit(1);
    }

    q8(s);
    fprintf(f, "%s", s);

    fclose(f);

    return 0;
}

char q8(char *s){

    for(int i = 0; i < sizeof(s); i++) {
        if(s[i] >= 'a' && s[i] <= 'z') {
            s[i] = s[i] - ('a' - 'A');
        }
    }
    return s;
}