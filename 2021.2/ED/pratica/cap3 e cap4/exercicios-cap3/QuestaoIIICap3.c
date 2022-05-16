#include<stdio.h>
#include<stdlib.h>

typedef struct no{
    
    //qualquer informação pode vir dentro do nó
    //depende da aplicação
    float valor;

    
    //MUITO IMPORTANTE
    //mecanismo de ligacao <3 - PONTEIROS
    struct no * prox;
    
}NO;

NO * inicio = NULL; //lista vazia!!!!
NO * fim = NULL;
int tam = 0;

void iniciarlista(){
    
    NO * novo = malloc(sizeof(NO));
    novo->valor = 0.0;
    novo->prox = NULL;
    
    inicio = novo;
    fim = novo;
    
}


void adicionar(float valor, int pos){
    
    if(pos>= 0 && pos<=tam){
        
        //criação no NOVO nó!!!
        NO * novo = malloc(sizeof(NO)); //1
                
        novo->valor = valor; //2
                
        novo->prox = NULL; //3
                
                
        //qual a posicao eu coloco o no???
        
        //1 - lista esta vazia!!! :D
        //if(inicio == NULL){
          
            //inicio = novo;
            
            
        //2 - pos == 0 e lista NÃo esta vazia
        //}else
        if(pos == 0){ //inicio
            
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
       
        fim->valor = ((fim->valor*tam) + novo->valor)/(tam+1);
       
        tam++;
    }
}

void imprimir(){
    
    NO * aux = inicio;
    printf("\n Imprimindo lista ...\n");
    for(int i =0 ; i<tam; i++){
        
        printf("%f ", aux->valor);
        aux = aux->prox;
    }
    
    printf("\n");

    printf("Media = %f\n", fim->valor);
}






int main(){
    
    iniciarlista(); //solicionar a questao 3 - cap 3
    adicionar(10, 0);
    adicionar(20, 1);
    adicionar(30, 2);
    adicionar(40, 3);
    imprimir();
        
    
    return 0;
}



