
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float q2();
void imprimir();
void adicionar(int valor, int pos);

typedef struct no{
    int valor;
    //mecanismo de ligacao <3 - PONTEIROS
    struct no * prox;
}No;

int tam = 0;
No* inicio = NULL;


int main(){
    adicionar(2, 0);
    adicionar(3, 1);
    adicionar(4, 1);
    adicionar(5, 2);
    adicionar(6, 0);
    imprimir();
    q2();

    return 0;
}

float q2() {
    int soma = 0;
    No *aux = inicio;
    
    for(int i =0 ; i<tam; i++){
        
        if (aux->valor % 2 == 0) {
            soma += aux->valor;
        }
        
        aux = aux->prox;
    }
    printf("%d ", soma);
    printf("\n");

    printf("%.0f ", pow(soma, 2));
    printf("\n");

    return 0;
}

void adicionar(int valor, int pos) {

    if(pos >= 0 && pos <= tam) {

        // Criação do novo nó
        No *novo = malloc(sizeof(No)); //1

        novo->valor = valor; //2

        novo->prox = NULL; //3

        //1 - lista vazia
        if(inicio == NULL) {

            inicio = novo;

        //2 - pos == 0 e lista não esta vazia    
        } else if(pos == 0) {

            novo->prox = inicio;
            inicio = novo;

        //3 - não ser no inicio da lista - meio ou fim    
        } else {

            No *aux = inicio;

            int i;

            for(i = 0; i < pos - 1; i++) {
                aux = aux->prox;
            }

            novo->prox = aux->prox;
            aux->prox = novo;
        }
        tam++;
    }
}

void imprimir(){
    
    No *aux = inicio;
    printf("\n Imprimindo lista ...\n");
    for(int i =0 ; i<tam; i++){
        
        printf("%d ", aux->valor);
        aux = aux->prox;
    }
    
    printf("\n");
    
}