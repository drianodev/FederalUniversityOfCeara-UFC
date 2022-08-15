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

void preordem(No *pt) {
    printf("%d[%d] ", pt->chave, pt->bal);

    if(pt->esq != NULL) {
        preordem(pt->esq);
    }

    if(pt->dir != NULL) {
        preordem(pt->dir);
    }
    
}


int main(){

    // Teste inicial = 10 15 16 8 6 9 12 18 11 13 14 17 19
    /*
    No *ptraiz = NULL;
    bool h = false;
    printf("\nInserir o NO 10, 15\n");
    inserirAVL(10, &ptraiz, &h);
    inserirAVL(15, &ptraiz, &h);

    if(ptraiz != NULL) 
        preordem(ptraiz);
    else
        printf("\nVazia\n");

    printf("\nInserir o NO 16\n");
    inserirAVL(16, &ptraiz, &h);

    if(ptraiz != NULL) 
        preordem(ptraiz);
    else
        printf("\nVazia\n");

    printf("\nInserir o NO 8\n");
    inserirAVL(8, &ptraiz, &h);

    if(ptraiz != NULL) 
        preordem(ptraiz);
    else
        printf("\nVazia\n");

    printf("\nInserir o NO 6\n");
    inserirAVL(6, &ptraiz, &h);

    if(ptraiz != NULL) 
        preordem(ptraiz);
    else
        printf("\nVazia\n");

    printf("\nInserir o NO 9\n");
    inserirAVL(9, &ptraiz, &h);

    if(ptraiz != NULL) 
        preordem(ptraiz);
    else
        printf("\nVazia\n");


    printf("\nInserir o NO 12, 18, 11, 13\n");
    inserirAVL(12, &ptraiz, &h);
    inserirAVL(18, &ptraiz, &h);
    inserirAVL(11, &ptraiz, &h);
    inserirAVL(13, &ptraiz, &h);

    if(ptraiz != NULL) 
        preordem(ptraiz);
    else
        printf("\nVazia\n");

    printf("\nInserir o NO 14\n");
    inserirAVL(14, &ptraiz, &h);

    if(ptraiz != NULL) 
        preordem(ptraiz);
    else
        printf("\nVazia\n");

    printf("\nInserir o NO 17\n");
    inserirAVL(17, &ptraiz, &h);

    if(ptraiz != NULL) 
        preordem(ptraiz);
    else
        printf("\nVazia\n");

    printf("\nInserir o NO 19\n");
    inserirAVL(19, &ptraiz, &h);

    if(ptraiz != NULL) 
        preordem(ptraiz);
    else
        printf("\nVazia\n");

    printf("\n\n\nRemovendo o NO 11\n");
    removerAVL(11, &ptraiz, &h);

    if(ptraiz != NULL) 
        preordem(ptraiz);
    else
        printf("\nVazia\n");

    printf("\nRemovendo o NO 8\n");
    removerAVL(8, &ptraiz, &h);

    if(ptraiz != NULL) 
        preordem(ptraiz);
    else
        printf("\nVazia\n");
    */
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

    for (int i = 0; i < 1000; i++) { //1.000 AVL's
        
        ptraiz = NULL;
        h = false;

        int valores[10000]; 

        for (int j = 0; j < 10000; j++) { //10.000 nós
            
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
    printf("\n\n");
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
        //printf("\nRotação simples a esquerda no NO %d\n", (*pt)->chave);
        (*pt)->esq = ptu->dir;
        ptu->dir = (*pt);
        (*pt) = ptu;
        (*pt)->dir->bal = 0;
        
    } else {
        //printf("\nRotação dupla a esquerda no NO %d\n", (*pt)->chave);
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
        //printf("\nRotação simples a direita no NO %d\n", (*pt)->chave);
        (*pt)->dir = ptu->esq;
        ptu->esq = (*pt);
        (*pt) = ptu;
        (*pt)->bal = 0;
        (*pt)->esq->bal = 0;
        
    } else {
        //printf("\nRotação dupla a direita no NO %d\n", (*pt)->chave);
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
        //printf("\nRotação simples a esquerda no NO %d\n", (*pt)->chave);
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
        //printf("\nRotação dupla a esquerda no NO %d\n", (*pt)->chave);
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
        //printf("\nRotação simples a direita no NO %d\n", (*pt)->chave);
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
        
    } else{
        //printf("\nRotação dupla a direita no NO %d\n", (*pt)->chave);
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
/*
Inserir o NO 10, 15
10[1] 15[0] 

Inserir o NO 16
Rotação simples a direita no NO 10
15[0] 10[0] 16[0] 

Inserir o NO 8
15[-1] 10[-1] 8[0] 16[0] 

Inserir o NO 6
Rotação simples a esquerda no NO 10
15[-1] 8[0] 6[0] 10[0] 16[0] 

Inserir o NO 9
Rotação dupla a esquerda no NO 15
10[0] 8[0] 6[0] 9[0] 15[1] 16[0] 

Inserir o NO 12, 18, 11, 13
10[1] 8[0] 6[0] 9[0] 15[0] 12[0] 11[0] 13[0] 16[1] 18[0] 

Inserir o NO 14
Rotação dupla a direita no NO 10
12[0] 10[-1] 8[0] 6[0] 9[0] 11[0] 15[0] 13[1] 14[0] 16[1] 18[0] 

Inserir o NO 17
Rotação dupla a direita no NO 16
12[0] 10[-1] 8[0] 6[0] 9[0] 11[0] 15[0] 13[1] 14[0] 17[0] 16[0] 18[0] 

Inserir o NO 19
12[1] 10[-1] 8[0] 6[0] 9[0] 11[0] 15[1] 13[1] 14[0] 17[1] 16[0] 18[1] 19[0] 


Removendo o NO 11
Rotação simples a esquerda no NO 10
12[1] 8[1] 6[0] 10[-1] 9[0] 15[1] 13[1] 14[0] 17[1] 16[0] 18[1] 19[0] 

Removendo o NO 8
Rotação simples a direita no NO 12
15[0] 12[0] 9[0] 6[0] 10[0] 13[1] 14[0] 17[1] 16[0] 18[1] 19[0] */