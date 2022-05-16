#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    char *nome;
    int num_vidas;
    struct no *prox;
    struct no *ant;
}NO;

NO *inicio = NULL;
int tam =0;

void adicionar(char *nome, int num_vidas, int pos){

    NO *novo = malloc (sizeof (NO));	// 1 operação alocação de memoria
    novo->nome = nome;			// 1 operação alteração do valor do no novo
    novo->num_vidas = num_vidas;	// 1 operação alteração do valor do no novo
    novo->prox = NULL;			// 1 operação definição de referencia do prox
    novo->ant = NULL;			// 1 operação definição de referencia do ant
    					// Constantes 5 operações
/*--------------------------------------------------------------------*/
    if(tam == 0 && pos == 0){ 		// 3 operações (duas comparações e uma operação lógica)

        inicio = novo;			// 1 operação atualização do inicio
        tam++;				// 1 operação incremento
        				// 10 operações constantes
/*--------------------------------------------------------------------*/
    }else if(pos == 0){			// 1 operação de comparação

        novo->prox = inicio;		// 1 operação alteração do valor do proximo no novo
        inicio->ant = novo;		// 1 operação alteração do valor do anterior no novo
        inicio = novo;			// 1 operação atualização do inicio
        tam++;				// 1 operação incremento
        				// 10 operações constantes
/*--------------------------------------------------------------------*/
    }else if( pos > 0 && pos <= tam){	// 3 operações (duas comparações e uma operação lógica)

        NO * aux = inicio;		// 1 operação alteração do valor do no aux

        if(pos == tam) {			// 1 operação de comparação
            for(int i =0 ; i<pos -1; i++){	
                aux = aux->prox;		// 1 operação alteração do valor do no aux
            }
            novo->prox = aux->prox;		// 1 operação alteração do valor do proximo no novo
            aux->prox = novo;			// 1 operação alteração do valor do proximo no aux
            tam++;				// 1 operação incremento
            					// n operações lineares
        } else {
            for(int i = 0 ; i < pos - 1; i++){	
                aux = aux->prox;		// 1 operação alteração do valor do no aux
            }
            novo->prox = aux;			// 1 operação alteração do valor do proximo no novo
            aux->ant->prox = novo;		// 1 operação alteração do valor do no aux
            novo->ant = aux->ant;		// 1 operação alteração do valor do anterior no novo
            aux->ant = novo;			// 1 operação alteração do valor do anterior no aux
            tam++;				// 1 operação incremento
            					// n operações lineares
        }
/*--------------------------------------------------------------------*/
    }else{
        printf("insercao invalida! :/ \n");	// 1 operação
    }
}

void imprimir(){
    NO * aux = inicio;
    printf("\nImprimindo Personagens\n");
    for(int i =0 ; i<tam; i++){
        
        printf("%s ", aux->nome);
        printf("%d ", aux->num_vidas);
        aux = aux->prox;
    }
    printf("\n");
}

void remover(char *nome){
    if(tam == 1 && inicio->nome == nome){	// 3 operações (duas comparações e uma operação lógica)
        NO *lixo = inicio;			// 1 operação alteração do valor do no lixo
        inicio = NULL;				// 1 operação atualização do inicio
        free(lixo);				// 1 operação desalocação de memoria
        tam --;					// 1 operação decremento
        					// 7 operações constantes
        					
    }else if(tam > 1 && inicio->nome == nome){	// 3 operações (duas comparações e uma operação lógica)
        NO *lixo = inicio;			// 1 operação alteração do valor do no lixo
        inicio = inicio->prox;			// 1 operação atualização do inicio
        inicio->ant = NULL;			// 1 operação atualização do inicio
        free(lixo);				// 1 operação desalocação de memoria
        tam--;					// 1 operação decremento
        					// 8 operações constantes
        
    }else {

        NO *lixo = NULL;			// 1 operação alteração do valor do no lixo
        NO *aux = inicio;			// 1 operação alteração do valor do no aux
        for(int i =0; i < tam-1; i++){
            if (aux->prox->nome == nome) {	// 1 operação de comparação
                lixo = aux->prox;		// 1 operação alteração do valor do no lixo
                aux->prox = aux->prox->prox;	// 1 operação alteração do valor do no aux

                free(lixo);			// 1 operação desalocação de memoria
                tam--;				// 1 operação decremento
            }
            
            aux = aux->prox;			// 1 operação alteração do valor do no aux
        }
        					// n operações lineares
    }
}

char* persMaisVidas(){

    char *nome = NULL;
    int comparador = 0, temporario = 0;

    NO * aux = inicio;

    for(int i =0 ; i<tam; i++){


        if(i == 0){
            temporario = aux->num_vidas;
            nome = aux->nome;
        } else if(comparador < aux->num_vidas && temporario <= aux->num_vidas) {
            temporario = aux->num_vidas;
            nome = aux->nome;
        }
        comparador = aux->num_vidas;
        aux = aux->prox;
    }
    
    return nome;
}

int main(){

    adicionar("Mario", 2, 0);
    adicionar("Luigi", 9, 0);
    adicionar("Princesa", 7, 0);
    adicionar("Toad", 3, 0);
    imprimir();
    printf("\n");
    printf("Personagem c/ mais vidas: %s\n", persMaisVidas());
    return 0;
}
