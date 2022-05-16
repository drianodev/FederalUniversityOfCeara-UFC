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

NO * inicio = NULL; //lista vazia!!!!
int tam = 0;


void adicionar(int valor, int pos){
    
    if(pos>= 0 && pos<=tam){
        
        //criação no NOVO nó!!!
        NO * novo = malloc(sizeof(NO)); //1
                
        novo->valor = valor; //2
                
        novo->prox = NULL; //3
                
                
        //qual a posicao eu coloco o no???
        
        //1 - lista esta vazia!!! :D
        if(inicio == NULL){
          
            inicio = novo;
            
            
        //2 - pos == 0 e lista NÃo esta vazia
        }else if(pos == 0){
            
            novo->prox = inicio;
            inicio = novo;
            
         //3 - não ser no inicio da lista - meio ou fim
        }else{ //pos = 2
            
            NO * aux = inicio;
            
            for(int i =0 ; i<pos -1; i++){
                aux = aux->prox;
            }
            
            novo->prox = aux->prox;
            aux->prox = novo;
            
        }
        tam++;
    }
}

void imprimir(){
    
    NO * aux = inicio;
    printf("\n Imprimindo lista ...\n");
    for(int i =0 ; i<tam; i++){
        
        printf("%d ", aux->valor);
        aux = aux->prox;
    }
    
    printf("\n");
    
}



int remover(int pos){
 
    int retorno;
    NO *lixo;
    if(pos >= 0 && pos < tam){
        
        if(pos == 0){ //remover do inicio!
            lixo = inicio;
            if(tam == 1){ // um unico no na lista
                inicio = NULL;
            }else{ //mais de um no na lista
                
                inicio = inicio->prox;
            }
            
            
        }else{ //meio - fim
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
    
    
    adicionar(10, 0);
    adicionar(20, 1);
    adicionar(30, 2);
    adicionar(40, 3);
    imprimir();
    printf("\nValor removido: %d\n", remover(2));
    imprimir();
        
    
    return 0;
}



