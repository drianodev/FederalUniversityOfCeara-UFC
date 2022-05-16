#include <stdlib.h>
#include <stdio.h>

typedef struct no{
    int valor;
    struct no *prox;
}NO;

NO *topo = NULL;
int tam = 0;

void adicionar(int valor){

    NO *novo = malloc(sizeof(NO));
    novo->valor = valor;

    //muito simples
    novo->prox = topo;
    topo = novo;
    tam++;

}

int remover(){

    if(tam > 0) {
        NO *lixo = topo;
        topo = topo->prox;

        int valor_removido = topo->valor;
        
        free(lixo);
        tam--;

        return valor_removido;

    } else {
        printf("Pilha está vazia \n");
        return -1;
    }
}

void imprimir(){

    NO* aux = topo;

    for(int i = 0; i < tam; i++){
        printf("%d\n", aux->valor);

        aux = aux->prox;
    }
}

int main(){

    printf("Adicionando \n\n");
    for(int i = 1000; i >= 1; i -= 10) {
        adicionar(i);
    }
    imprimir();

    // printf("\nRemovendo \n\n");
    // for(int i = 0; i < 99; i++) {
    //     remover(i);
    // }
    // imprimir();
}
