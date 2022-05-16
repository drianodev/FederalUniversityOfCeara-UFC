#include<stdio.h>
#include<stdlib.h>

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
    for(int i =0 ; i<tam-1; i++){
        
        printf("%d ", aux->valor);
        aux = aux->prox;
    }
    printf("\n");

    aux = fim;
    printf("\n Imprimindo nó 'ignorado' ...\n");
    printf("%d ", aux->valor);
    printf("\n");

    // TRAZENDO A MEDIA PARA O FIM
    int media = 0;
    aux = inicio;
    printf("\n Imprimindo lista com a média no fim...\n");
    for(int i =0 ; i<tam; i++){
        
        media += aux->valor;
        printf("%d ", aux->valor);
        aux = aux->prox;

        if (i == tam-1) {
            printf("%d ", media/(i+1));
        }
        
    }
    printf("\n");
}

void buscar() {
    NO * aux = inicio;

    int soma = 0;
    int media = 0;

    // MEDIA
    for(int i =0 ; i<tam; i++){
        
        soma += aux->valor;
        media = soma/(i+1);

        aux = aux->prox;
        
    }
    // BUSCANDO
    int contador = 0;
    aux = inicio;
    printf("\n Buscando...\n");
    for(int i = 0 ; i<tam; i++){
        if(aux->valor == media) {
            contador++;
        }

        aux = aux->prox;

    }
    if(contador > 0) {
        printf("O valor buscado %d, foi encontrado :) \n", media);
    } else {
        printf("O valor buscado %d, não existe :( \n", media);
        printf("return -1");
    }
    printf("\n");

}

int main(){
    adicionar(1, 0);
    adicionar(2, 1);
    adicionar(5, 2);
    adicionar(4, 3);
    adicionar(5, 4);
    imprimir();
    buscar();
    
        
    
    return 0;
}
