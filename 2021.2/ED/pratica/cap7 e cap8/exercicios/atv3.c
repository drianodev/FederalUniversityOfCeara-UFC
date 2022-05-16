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
        return aux;
    }else if(x < aux->chave){ //esq
        if(aux->esq == NULL){
            return aux;
        }else{
            return buscar(x, aux->esq);
        }
    }else{ //dir
        if(aux->dir == NULL){
            return aux;
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

void pre_ordem(VERTICE *aux){

    printf("%d ", aux->chave);

    if(aux->esq != NULL){
        pre_ordem(aux->esq);
    }

    if(aux->dir != NULL){
        pre_ordem(aux->dir);
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

void pos_ordem(VERTICE *aux){

    if(aux->esq != NULL){
        pos_ordem(aux->esq);
    }

    if(aux->dir != NULL){
        pos_ordem(aux->dir);
    }

    printf("%d ", aux->chave);
    
}

int altura_no(int chave) {
    int altura = 0;
    VERTICE* aux = buscar(chave, raiz);

    
    if(aux->esq != NULL || aux->dir != NULL){
        altura_no(aux->chave);
        altura++;
    }

    return altura;
}

int main(){

    adicionar(8);
    adicionar(3);
    adicionar(10);
    adicionar(1);
    adicionar(6);
    adicionar(14);
    adicionar(4);
    adicionar(7);
    adicionar(13);
    printf("\nImprimindo arvore in-ordem...\n");
    in_ordem(raiz);
    printf("\n");
    printf("\nImprimindo arvore pos-ordem...\n");
    pos_ordem(raiz);
    printf("\n");
    printf("\nImprimindo arvore pre-ordem...\n");
    pre_ordem(raiz);
    printf("\n");
    printf("\nALTURA DO 8: %d\n", altura_no(8));
    printf("\n");
    printf("\nALTURA DO 4: %d\n", altura_no(4));
    printf("\n");
    printf("\nALTURA DO 10: %d\n", altura_no(10));
    printf("\n");
    printf("\nALTURA DO 14: %d\n", altura_no(14));
    printf("\n");
    return 0;
}
