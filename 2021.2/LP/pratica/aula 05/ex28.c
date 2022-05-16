#include <stdio.h>

void imprimir(char *s);
int tam(char *s);
void copia(char *dest, char *orig);
void concat(char *dest, char *orig);

int main() {
    char cid[80] = "Russas";
    char cid2[80];

    imprimir(cid);
    printf("\n");
    printf("tam = %d \n", tam(cid));
    copia(cid2, cid);
    imprimir(cid2);
    printf("\n");

    concat(cid2, cid);
    imprimir(cid2);
    printf("\n");

    return 0;
}

void imprimir(char *s){
    for (int i = 0; s[i] != '\0'; i++) {
        printf("%c", s[i]);
    }
    
}

int tam(char *s){
    int cont = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        cont++;
    }
    return cont;
}

void copia(char *dest, char *orig){
    int i;

    for (i = 0; orig[i] != '\0'; i++) {
        dest[i] = orig[i];
    }
    dest[i] = orig[i];
}

void concat(char *dest, char *orig){
    int i = 0;

    while(dest[i] != '\0') {
        i++;
    }

    for(int j = 0; orig[j] != '\0'; j++){
        dest[j] = orig[j];
        i++;
    }
    dest[i] = '\0';
}
