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
    
    aux = fim;
    printf("\n Imprimindo lista em ordem contraria ...\n");
       for(int i =0 ; i<tam; i++){
           
           printf("%d ", aux->valor);
           aux = aux->ant;
       }
    
    printf("\n");
}

int remover(int pos){
 
    int retorno;
    NO *lixo;
    if(pos >= 0 && pos < tam){
        
        if(pos == 0){ //caso: inicio
            
            lixo = inicio;
            
            if(tam == 1){ // um unico no na lista
                
                inicio = NULL;
                fim = NULL;
                
            }else{ //mais de um no na lista
                inicio = inicio->prox;
                inicio->ant = NULL;
            }
            
            
        }else if(pos == tam -1){ //caso: fim
          
            lixo = fim;
            fim->ant->prox = NULL;
            fim = fim->ant;

        }else{ //meio
            NO *aux = inicio;
            for(int i =0; i < pos-1; i++){
                aux = aux->prox;
            }
            lixo = aux->prox;
            //aux->prox = lixo->prox; //apagar!!!
            //ou uma segunda forma de operacao
            aux->prox = aux->prox->prox;
            
        }
        
        retorno = lixo->valor;
        free(lixo);
        tam--;
    }
    
    return retorno;
}




int main(){
    
    
    adicionar(8, 0);
    adicionar(10, 1);
    adicionar(3, 2);
    adicionar(8, 3);
    adicionar(5, 4);
    imprimir();

    remover(4);
    imprimir();
    
        
    
    return 0;
}



