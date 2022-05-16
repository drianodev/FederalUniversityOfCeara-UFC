#include <stdio.h>
#include <stdlib.h>

typedef struct ImoveisDaRua{
    char *complemento;
    char imovelComercial;
    int numero;

    struct ImoveisDaRua * prox;
}IDR;

int main(){
    
    IDR *casa342 = malloc(sizeof(IDR));
    IDR *apartamento17 = malloc(sizeof(IDR));
    IDR *mercantil = malloc(sizeof(IDR));

    casa342 -> numero = 342;
    casa342 -> imovelComercial = "N";
    casa342 -> complemento = "Casa, 284 m²";

    apartamento17 -> numero = 17;
    apartamento17 -> complemento = "Predio, 4 Andares, 182 m²";
    apartamento17 -> imovelComercial = "N";

    mercantil -> numero = 1;
    mercantil -> imovelComercial = "S";
    mercantil -> complemento = "Casa Comercial, 521 m²";
    mercantil -> imovelComercial = "N";

    casa342 -> prox = apartamento17;
    apartamento17 -> prox = mercantil;
    mercantil -> prox = NULL;

    IDR *aux = casa342;

    printf("--- INICIO DA LISTA ---\n");

    while(aux != NULL) {
        printf("%d ", aux -> numero );
        aux = aux -> prox;
    }

    printf("--- FIM DA LISTA ---\n");

    return 0;
}