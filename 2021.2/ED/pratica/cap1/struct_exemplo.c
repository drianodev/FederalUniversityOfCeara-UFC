#include<stdio.h>
#include<stdlib.h>

typedef struct no{
    
    //qualquer informação pode vir dentro do nó
    //depende da aplicação
    int valor;
    
    
    //MUITO IMPORTANTE
    //mecanismo de ligacao <3 - PONTEIROS
    struct no * prox;
    
}NO;



int main(){
    
    NO n1;
    n1.valor = 10;
    
    NO n2;
    n2.valor = 5;
    
    NO n3;
    n3.valor = 8;
    
    
    int i = 10;
    int *p = &i;
    
    
    printf("Endereco que esta armazendo no ponteiro p: %p\n", p);
    printf("Valor que esta armazendo no ponteiro p: %d\n", *p);
    printf("Endereco do ponteiro p: %p\n", &p);
    printf("Tamanho de ponteiro para inteiros: %lu\n", sizeof(int *));
    
    
    return 0;
}



