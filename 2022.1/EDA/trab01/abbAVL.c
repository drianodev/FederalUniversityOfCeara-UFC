#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct no{
    int chave;
    int bal;
    struct no *esq, *dir;
};

typedef struct no No;


/*-----------------  ALGORITMO VERIFICAÇÃO   -----------------*/
int altura(No *pt);
int verificaAVL(No *pt);
int quantidade_nos(No *ptraiz);
/*-----------------  ALGORITMO INSERIR   -----------------*/
void caso1(No **pt, bool *h);
void caso2(No **pt, bool *h);
void inserirAVL(int x, No **pt, bool *h);
/*-----------------  ALGORITMO REMOVER   -----------------*/
void caso1R(No **pt, bool *h);
void caso2R(No **pt, bool *h);
void balancear(No **pt, int R, bool *h);
void trocar(No **pt, No **paiS);
void removerAVL(int x, No **pt, bool *h);


int main(){

    /*
    1. Deve-se criar 1.000 AVL’s
	2. Em cada AVL deve-se inserirAVL aleatoriamente 10.000 nós onde a chave de cada nó está entre 0 e 100.000
    (verificar se a AVL possui os 10.000 pelo algoritmo de contagem de nós)
	3. Após todas as inserções verificar se a árvore é AVL pelo algoritmo de verificação.
	4. Remover 1.000 nós (verificar se a AVL possui os 9.000 nós pelo algoritmo de contagem de nós)
	5. Após todas as remoções verificar se a árvore é AVL pelo algoritmo de verificação.
    */

    No *ptraiz = NULL;
    bool h = false;
    int aux = 1;

    for (int i = 1; i <= 1000; i++) { //1.000 AVL's
        
        ptraiz = NULL;
        h = false;

        int valores[10000]; 

        for (int j = 1; j <= 10000; j++) { //10.000 nós
            
            do {
                aux = 1;
                int x = (rand() % 100000);
                
                for (int k = 0; k < j; k++){
                    if (valores[k] == x){
                        aux = 0;
                    }
                }

                if (aux){
                    valores[j] = x;
                    inserirAVL(x, &ptraiz, &h);
                }
            } while (!aux);
        }

        printf("\n\nAVL Nº -> %d com %d nos.", i, quantidade_nos(ptraiz));
        printf("\nbal = %d, é AVL", verificaAVL(ptraiz));
        printf("\nRemovendo os nos...");

        for (int l = 0; l < 1000; l++){
            removerAVL(valores[l], &ptraiz, &h);
        }

        printf("\nAVL Nº -> %d com %d nos.", i, quantidade_nos(ptraiz));
        printf("\nbal = %d, é AVL\n\n\n", verificaAVL(ptraiz));
    }
    
    return 0;
}

/*-----------------  ALGORITMO VERIFICAÇÃO   -----------------*/

int altura(No *pt) {
    if (pt == NULL) 
        return -1; // altura da árvore vazia
    else {
        int he = altura (pt->esq);
        int hd = altura (pt->dir);
        if (he < hd) return hd + 1;
        else return he + 1;
    }
    
}

int verificaAVL(No *pt) {
    if (pt == NULL){
        return;
    }

    int bal = (altura(pt->dir) - altura(pt->esq));
    
    if (bal <= 1 || bal >= -1){
        return bal;
    }
    
    verificaAVL(pt->esq);
    verificaAVL(pt->dir);
}

int quantidade_nos(No *ptraiz) {
    if(ptraiz == NULL)
        return 0;
    else
        return 1 + quantidade_nos(ptraiz->esq) + quantidade_nos(ptraiz->dir);
}


/*-----------------  ALGORITMO INSERIR   -----------------*/

void caso1(No **pt, bool *h) {
    
    No *ptu = (*pt)->esq;
    
    if (ptu->bal == -1){
        (*pt)->esq = ptu->dir;
        ptu->dir = (*pt);
        (*pt) = ptu;
        (*pt)->dir->bal = 0;
    } else {
        No *ptv = ptu->dir;
        ptu->dir = ptv->esq;
        ptv->esq = ptu;
        (*pt)->esq = ptv->dir;
        ptv->dir = (*pt);

        if (ptv->bal == 1) {
            (*pt)->bal = 0;
            ptu->bal = -1;
        } else if (ptv->bal == 0) {
            (*pt)->bal = 0;
            ptu->bal = 0;
        } else {
            (*pt)->bal = 1;
            ptu->bal = 0;
        }
        (*pt) = ptv;
    }
    (*pt)->bal = 0;
    *h = false;
}

void caso2(No **pt, bool *h) {
    
    No *ptu = (*pt)->dir;

    if (ptu->bal == 1){
        (*pt)->dir = ptu->esq;
        ptu->esq = (*pt);
        (*pt) = ptu;
        (*pt)->bal = 0;
        (*pt)->esq->bal = 0;
    } else {
        No *ptv = ptu->esq;
        ptu->esq = ptv->dir;
        ptv->dir = ptu;
        (*pt)->dir = ptv->esq;
        ptv->esq = (*pt);

        if (ptv->bal == 1) {
            (*pt)->bal = -1;
            ptu->bal = 0;
        } else if (ptv->bal == 0) {
            (*pt)->bal = 0;
            ptu->bal = 0;
        } else {
            ptu->bal = 1;
            (*pt)->bal = 0;
        }
        (*pt) = ptv;
    }
    (*pt)->bal = 0;
    *h = false;
}

void inserirAVL(int x, No **pt, bool *h) {
    if(*pt == NULL) {
        No *novo = (No *)malloc(sizeof(No));
        novo->chave = x;
        novo->bal = 0;
        novo->esq = NULL;
        novo->dir = NULL;
        (*pt) = novo;
        *h = true;
    } else {
        if ((*pt)->chave == x){
            printf("\nElemento encontrado\n");
        }
        
        if(x < (*pt)->chave) {

            inserirAVL(x, &(*pt)->esq, h);
            
            if(*h == true) {
                if((*pt)->bal == 1){
                    (*pt)->bal = 0;
                    *h = false;
                } else if ((*pt)->bal == 0){
                    (*pt)->bal = -1;
                } else if ((*pt)->bal == -1) {
                    caso1(pt, h);
                }
            }
        } else {
            
            inserirAVL(x, &(*pt)->dir, h);
            
            if(*h == true) {
                if((*pt)->bal == -1){
                    (*pt)->bal = 0;
                    *h = false;
                } else if ((*pt)->bal == 0){
                    (*pt)->bal = 1;
                } else if ((*pt)->bal == 1) {
                    caso2(pt, h);
                }
            }
        }
    }
}


/*-----------------  ALGORITMO REMOVER   -----------------*/

void caso1R(No **pt, bool *h) {

    No *ptu = (*pt)->esq;

    if(ptu->bal <= 0) {
        (*pt)->esq = ptu->dir;
        ptu->dir = (*pt);
        (*pt) = ptu;
        if(ptu->bal == -1) {
            ptu->bal = (*pt)->dir->bal = 0;
            *h = true;
        } else {
            ptu->bal = 1;
            (*pt)->dir->bal = -1;
            *h = false;
        }
    } else {
        No *ptv = ptu->dir;
        ptu->dir = ptv->esq;
        ptv->esq = ptu;
        (*pt)->esq = ptv->dir;
        ptv->dir = (*pt);

        if (ptv->bal == -1) {
            ptu->bal = 0;
            (*pt)->bal = 1;
        } else if (ptv->bal == 0) {
            ptu->bal = 0;
            (*pt)->bal = 0;
        } else {
            ptu->bal = -1;
            (*pt)->bal = 0;
        }
        (*pt) = ptv;
        (*pt)->bal = 0;
        *h = true;
    }
}

void caso2R(No **pt, bool *h) {

    No *ptu = (*pt)->dir;

    if (ptu->bal >= 0){
        (*pt)->dir = ptu->esq;
        ptu->esq = (*pt);
        (*pt) = ptu;

        if ((*pt)->bal == 1){
            (*pt)->bal = 0;
            (*pt)->esq->bal = 0;
            *h = true;
        }
        else{
            (*pt)->bal = -1;
            (*pt)->esq->bal = 1;
            *h = false;
        }   
    }
    else{
        No *ptv = ptu->esq;
        ptu->esq = ptv->dir;
        ptv->dir = ptu;
        (*pt)->dir = ptv->esq;
        ptv->esq = (*pt);

        if (ptv->bal == 1) {
            ptu->bal = 0;
            (*pt)->bal = -1;
        } else if (ptv->bal == 0) {
            ptu->bal = 0;
            (*pt)->bal = 0;
        } else {
            ptu->bal = 1;
            (*pt)->bal = 0;
        }
        (*pt) = ptv;
        (*pt)->bal = 0;
        *h = true;
    }
}

void balancear(No **pt, int R, bool *h) {
    if(*h == true) {
        if(R) {
            if((*pt)->bal == 1) {
                (*pt)->bal = 0;
            } else if ((*pt)->bal == 0) {
                (*pt)->bal = -1;
                *h = false;
            } else if((*pt)->bal == -1) {
                caso1R(pt, h);
            }
        } else {
            if((*pt)->bal == -1) {
                (*pt)->bal = 0;
            } else if ((*pt)->bal == 0) {
                (*pt)->bal = 1;
                *h = false;
            } else if((*pt)->bal == 1) {
                caso2R(pt, h);
            }
        }
    }
}

void trocar(No **pt, No **paiS) {
    int x = (*pt)->chave;
    (*pt)->chave = (*paiS)->chave;
    (*paiS)->chave = x;
}

void removerAVL(int x, No **pt, bool *h) {
    // R == E == 0
    // R == D == 1

    if ((*pt) == NULL){
        //printf("\nElemento não existe\n");
        *h = false;
    } else {
        if (x < (*pt)->chave) {
            removerAVL(x, &(*pt)->esq, h);
            balancear(pt, 0, h);
        } else if (x > (*pt)->chave) {
            removerAVL(x, &(*pt)->dir, h);
            balancear(pt, 1, h);
        } else {
            No *aux = (*pt);

            if ((*pt)->esq == NULL) {
                (*pt) = (*pt)->dir;
                *h = true;
                free(aux);
            } else if ((*pt)->dir == NULL) {
                (*pt) = (*pt)->esq;
                *h = true;
                free(aux);
            } else {
                No *s = (*pt)->dir;
                if(s->esq == NULL){
                    s->esq = (*pt)->esq;
                    s->bal = (*pt)->bal;
                    (*pt) = s;
                    *h = true;
                } else {
                    No *paiS;
                    while (s->esq != NULL){
                        paiS = s;
                        s = s->esq;
                }
                    trocar(pt, &paiS->esq);
                    removerAVL(x, &(*pt)->dir, h);
                }
                balancear(pt, 1, h);
            }
        }
    }
}