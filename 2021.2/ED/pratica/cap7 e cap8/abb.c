#include<stdio.h>
#include<stdlib.h>

typedef struct vertice{
    int chave;
    struct vertice * dir;
    struct vertice * esq;
}VERTICE;


VERTICE * raiz = NULL; //vazia!!!!
int tam = 0;

/*procedimento busca-arvore(x, pt, f)
    se pt = vazio então f = 0
    senão se x = pt.chave então f = 1
    senão se x < pt.chave então
            se pt.esq = vazio então f = 2
                senão pt = pt.esq
                    busca-arvore(x, pt, f)
            senão se pt.dir = vazio então f = 3
                senão pt = pt.dir
                    busca-arvore(x, pt, f)*/

VERTICE* buscar(int x, VERTICE *aux){
    if(aux == NULL){
        return NULL; //vazia
    }else if (x == aux->chave){
        return aux; // propio vertice que contem a chave
    }else if(x < aux->chave){ //esq
        if(aux->esq == NULL){
            return aux; // pai
        }else{
            return buscar(x, aux->esq);
        }
    }else{ //dir
        if(aux->dir == NULL){
            return aux; // pai
        }else{
            return buscar(x, aux->dir);
        }
    }
}

void adicionar(int chave){
   VERTICE* aux = buscar(chave, raiz);
    if(aux != NULL && aux->chave == chave){
        //chave já existe na árvore!
        printf("insercao invalida!\n");
    }else{
        VERTICE* novo = malloc(sizeof(VERTICE));
        novo->chave = chave;
        novo->esq = NULL;
        novo->dir = NULL;
        if(aux == NULL){ //vazia
            raiz = novo;
        }else if(chave < aux->chave){//esq
            aux->esq = novo;
        }else{ //dir
            aux->dir = novo;
        }
    }
}

void in_ordem(VERTICE *aux){
    
    if(aux->esq != NULL){
        in_ordem(aux->esq);
    }
    
    printf("%d ", aux->chave);
    
    if(aux->dir != NULL){
        in_ordem(aux->dir);
    }
}

int main(){

    adicionar(8);
    adicionar(5);
    adicionar(2);
    adicionar(1);
    adicionar(6);
    adicionar(7);
    adicionar(4);
    printf("\nImprimindo arvore...\n");
    in_ordem(raiz);
    return 0;
}



