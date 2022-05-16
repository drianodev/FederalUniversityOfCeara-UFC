#include<stdio.h>
#include<stdlib.h>

typedef struct no{
    
    int n1;
    int n2;
    
    struct no * prox;
    
}NO;

void q4(int n1, int n2);

int main(){
    
    q4(10, 100);
    
    return 0;
}

void q4(int n1, int n2) {
    NO *valor1;
    NO *valor2;

    int aux = n1;

    valor1->n1 = n2;
    valor1->prox = valor2;
    valor2->n2 = aux;
    valor2->prox = NULL;

    printf("O valor %d e %d trocaram de lugar \n", valor1->n1, valor2->n2);
}