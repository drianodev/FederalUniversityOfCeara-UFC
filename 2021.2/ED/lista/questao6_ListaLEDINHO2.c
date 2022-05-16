#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    
    //qualquer informação pode vir dentro do nó
    //depende da aplicação
    int valor;

    
    //MUITO IMPORTANTE
    //mecanismo de ligacao <3 - PONTEIROS
    struct no * prox;
    struct no * ant;
    
}NO;

NO * inicio = NULL;
NO * fim = NULL;
int tam = 0;


void adicionar(int valor, int pos){
    
    if(pos>= 0 && pos<=tam){
        
        //criação no NOVO nó!!!
        NO * novo = malloc(sizeof(NO)); //1
                
        novo->valor = valor; //2
                
        novo->prox = NULL; //3
        
        novo->ant = NULL; //4
                
                
        //qual a posicao eu coloco o no???
        
        //1 - lista esta vazia! - ok!
        if(inicio == NULL){
          
            inicio = novo;
            fim = novo;
            
        //2 - pos == 0 e lista não esta vazia
        }else if(pos == 0){ //caso: inicio - ok!
            
            novo->prox = inicio;
            inicio->ant = novo;
            inicio = novo;
        
        }if(pos == tam){ //3 - caso: fim
            
            fim->prox = novo;
            novo->ant = fim;
            fim = novo;
            
        }else{ //caso: meio
            
            NO * aux = inicio;
            
            for(int i =0 ; i<pos; i++){
                aux = aux->prox;
            }
            
            novo->prox = aux;
            aux->ant->prox = novo;
            novo->ant = aux->ant;
            aux->ant = novo;
            
        }
        tam++;
    }
}

void imprimir(){
    
    NO * aux = inicio;
    printf("\n Imprimindo lista em ordem ...\n");
    for(int i =0 ; i<tam; i++){
        
        printf("%d ", aux->valor);
        aux = aux->prox;
    }
    
    printf("\n");
}

int posicao() {
    int pos = rand() % 10;

    return pos;
}

int main(){
    
    adicionar(8, posicao());
    imprimir();
    adicionar(10, posicao());
    imprimir();
    adicionar(3, posicao());
    imprimir();
    adicionar(8, posicao());
    imprimir();
    adicionar(5, posicao());
    imprimir();
        
    
    return 0;
}