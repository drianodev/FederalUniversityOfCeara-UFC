#include<stdio.h>
#include<stdlib.h>

typedef struct personagem{

    char nome[80];
    char historia[120];
    struct personagem *prox;
    
}Personagem;

Personagem * inicio = NULL;
Personagem * fim = NULL;
int tam = 0;


void adicionar(char *name, char *history, int pos){

    if(pos >= 0 && pos <= tam) {

        Personagem *Novo = malloc(sizeof(Personagem));
        Novo->nome = name;
        Novo->historia = history;

        if(inicio == NULL){
          
            inicio = Novo;
            fim = Novo;
            
        }else if(pos == 0){
            
            Novo->prox = inicio;
            inicio = Novo;
            
        }else if(pos == tam){
            
            fim->prox = Novo;
            fim = Novo;
           
        }else{
            
            Personagem *aux = inicio;

            for(int i = 0; i < pos-1; i++) {
                aux = aux->prox;
            }

            Novo->prox = aux->prox;
            aux->prox = Novo;
            
        }
        tam++;
    } else {
        printf("Posição Invalida ! \n");
    }
}


void remover(int pos){
    
    if(pos >= 0 && pos <= tam) {

        if(tam == 1){
            
            Personagem *lixo = inicio;
            inicio = NULL;
            fim = NULL;
            free(lixo);
            
        }else if(pos == 0){
            
            Personagem *lixo = inicio;
            inicio = inicio->prox;
            inicio->prox = NULL;
            free(lixo);
            
        }else if(pos == tam-1){
            
            Personagem *lixo = fim;
            Personagem *aux = inicio;
            for(int i = 0; i < tam-1; ++i) {
                aux = aux->prox; 
            }
            aux->prox = NULL;
            fim = aux;
            free(lixo);
           
        }else{
            
            Personagem *lixo = fim;
            Personagem *aux = inicio;
            for(int i = 0; i < pos-1; ++i) {
                aux = aux->prox; 
            }
            aux->prox = aux->prox->prox;
            aux->prox->prox = NULL;
            free(lixo);
            
        }
        tam--;
    } else {
        printf("Posição Invalida ! \n");
    }
}


int main(){
    
    return 0;
    
}


