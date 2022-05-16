#include<stdio.h>
#include<stdlib.h>

typedef struct no{

    int valor;
    struct no * prox;
    
}NO;

typedef struct lista{
    NO * inicio;
    NO * fim;
    int tam;
}LISTA;



void adicionar(LISTA *l, int valor, int pos){
    
    if(pos>= 0 && pos<= l->tam){
        
        //criação no NOVO nó!!!
        NO * novo = malloc(sizeof(NO)); //1
                
        novo->valor = valor; //2
                
        novo->prox = NULL; //3
                
                
        //qual a posicao eu coloco o no???
        
        //1 - lista esta vazia!!! :D
        if(l->inicio == NULL){
          
            l->inicio = novo;
            l->fim = novo;
            
        //2 - pos == 0 e lista NÃo esta vazia
        }else if(pos == 0){
            
            novo->prox = l->inicio;
            l->inicio = novo;
            
         //3 - não ser no inicio da lista - meio ou fim
        }else if(pos == l->tam){
            //no fim
           
        }else{
            //no meio
        }
        l->tam++;
    }
}

void imprimir(LISTA *l){
    
    NO * aux = l->inicio;
    printf("\n Imprimindo lista ...\n");
    for(int i =0 ; i<l->tam; i++){
        
        printf("%d ", aux->valor);
        aux = aux->prox;
    }
    
    printf("\n");
    
}

LISTA* iniciaLista(LISTA *l){
    l = malloc(sizeof(LISTA));
    l->inicio = NULL;
    l->fim = NULL;
    l->tam = 0;
    return l;
}

int main(){
    //exemplo de uma lista vazia
    LISTA *l1;
    l1 = iniciaLista(l1);
    
    adicionar(l1, 10, 0);
    adicionar(l1, 20, 0);
    adicionar(l1, 30, 0);
    imprimir(l1);
    
    LISTA *l2;
       l2 = iniciaLista(l1);
       
       adicionar(l2, 40, 0);
       adicionar(l2, 50, 0);
       adicionar(l2, 60, 0);
       imprimir(l2);

    LISTA *l3;
       l3 = iniciaLista(l1);
       
       adicionar(l3, 70, 0);
       adicionar(l3, 80, 0);
       adicionar(l3, 90, 0);
       imprimir(l3);
    
    return 0;
    
}


