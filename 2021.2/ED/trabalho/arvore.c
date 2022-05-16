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

VERTICE* remover(VERTICE* aux, int chave){
    // valor nao encontrado
    if(aux == NULL) {
        printf("valor não encontrado\n"); 
        return aux;
    } else {
        if(aux->chave == chave) {
            // nó sem filhos
            if(aux->esq == NULL && aux->dir == NULL) {
                free(aux);
                return NULL;
            } else {
                // nó tem dois filhos
                if(aux->esq != NULL && aux->dir != NULL) {
                    // temporario = temp
                    VERTICE* temp = aux->esq;
                    while(temp->dir != NULL) {
                        temp = temp->dir;
                    }
                    aux->chave = temp->chave;
                    temp->chave = chave;
                    aux->esq = remover(aux->esq, chave);
                    return aux;
                } else {
                    // apenas um filho
                    VERTICE* temp;
                    if(aux->esq != NULL) {
                        temp = aux->esq;
                    } else {
                        temp = aux->dir;
                    }
                    free(aux);
                    return temp;
                }    
            }
        } else {
            if(chave < aux->chave) {
                aux->esq = remover(aux->esq, chave);
            } else {
                aux->dir = remover(aux->dir, chave);
            }
            return aux;
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

int main(){

    adicionar(8);
    adicionar(5);
    adicionar(10);
    adicionar(2);
    adicionar(1);
    adicionar(6);
    adicionar(9);
    adicionar(7);
    adicionar(3);
    adicionar(4);
    adicionar(20);
    adicionar(25);
    adicionar(11);
    adicionar(13);
    adicionar(15);
    adicionar(18);
    adicionar(16);
    adicionar(12);
    adicionar(19);
    adicionar(14);
    printf("\nImprimindo arvore in-ordem...\n");
    in_ordem(raiz);
    printf("\n");
    // printf("\nImprimindo arvore pos-ordem...\n");
    // pos_ordem(raiz);
    // printf("\n");
    // printf("\nImprimindo arvore pre-ordem...\n");
    // pre_ordem(raiz);
    // printf("\n");
    remover(raiz, 1); // folha
    remover(raiz, 6); // um filho
    remover(raiz, 20); // dois filhos
    remover(raiz, 8); // raiz
    printf("\nImprimindo arvore in-ordem após remoção...\n");
    in_ordem(raiz);
    printf("\n");
    remover(raiz, 19); // folha
    remover(raiz, 3); // um filho
    remover(raiz, 10); // dois filhos
    remover(raiz, 7); // raiz
    printf("\nImprimindo arvore in-ordem após remoção...\n");
    in_ordem(raiz);
    printf("\n");
    return 0;
}



