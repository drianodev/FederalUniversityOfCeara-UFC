#include<stdio.h>
#include<stdlib.h>

typedef struct no{
    
    int numero;
    int validade;
    int cvv;
    
    struct no * prox;
    
}NO;



int main(){
    
    NO n1;
    n1.numero = 123456;
    
    NO n2;
    n2.validade = 1021;
    
    NO n3;
    n3.cvv = 155;
    
    
    printf("Numero do cartao: %d\n", n1.numero);
    printf("Validade do cartao: %d\n", n2.validade);
    printf("CVV do cartao: %d\n", n3.cvv);
    
    
    return 0;
}
