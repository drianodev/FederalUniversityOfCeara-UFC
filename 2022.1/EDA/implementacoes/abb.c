#include <stdio.h>

struct no{
    int chave;
    struct no *esq, *dir;
};

typedef struct no No;

void preordem(No *pt);
void buscar(int x, No ***pt, int *f);
void inserir(int x, No **ptraiz);
void remover(int x, No **ptraiz);

int main() {
    int f;
    No *ptraiz = NULL;
    No **pt = &ptraiz;
    No A, B, C;

    buscar(12, &pt, &f);
    printf("1° f = %d \n", f);

    A.chave = 12;
    B.chave = 70;
    C.chave = 9;

    ptraiz = &A;
    A.esq = &C;
    A.dir = &B;

    B.dir = B.esq = NULL;
    C.dir = C.esq = NULL;

    pt = &ptraiz;
    buscar(12, &pt, &f);
    printf("2° f = %d \n", f);

    pt = &ptraiz;
    buscar(60, &pt, &f);
    printf("3° f = %d \n", f);

    pt = &ptraiz;
    buscar(10, &pt, &f);
    printf("4° f = %d \n", f);

    printf("\n\n");
    inserir(10, &ptraiz);
    inserir(12, &ptraiz);
    inserir(60, &ptraiz);

    printf("\nABB: \n");
    if(ptraiz != NULL)
        preordem(ptraiz);
    else
        printf("arv. vazia");

    // testando funções
    ptraiz = NULL;
    printf("\nABB: \n");
    if(ptraiz != NULL)
        preordem(ptraiz);
    else
        printf("arv. vazia");

    inserir(10, &ptraiz);
    inserir(12, &ptraiz);
    inserir(60, &ptraiz);
    inserir(100, &ptraiz);
    inserir(1, &ptraiz);
    inserir(6, &ptraiz);
    
    printf("\nABB: \n");
    if(ptraiz != NULL)
        preordem(ptraiz);
    else
        printf("arv. vazia");

    remover(12, &ptraiz);

    printf("\nABB APÓS REMOVER: \n");
    if(ptraiz != NULL)
        preordem(ptraiz);
    else
        printf("arv. vazia");


    // testando rand
    ptraiz = NULL;
    for(int j = 0; j < 2; j++) {
        for(int i = 0; i < 10; i++) {
            inserir(rand()%1000, &ptraiz);
        }

        printf("\nABB: \n");
        if(ptraiz != NULL)
            preordem(ptraiz);
        else
            printf("arv. vazia");
    }
    

    printf("\n\n");
    return 0;
}

void preordem(No *pt){
    printf("%d ", pt->chave);

    if(pt->esq != NULL)
        preordem(pt->esq);

    if(pt->dir != NULL)
        preordem(pt->dir);
}

void buscar(int x, No ***pt, int *f){
    if ( (*(*pt)) == NULL ) {
        (*f) = 0;
    } else {
        if ( (*(*pt))->chave == x ) {
            (*f) = 1;
        } else {
            if( x < (*(*pt))->chave ) {
                if( (*(*pt))->esq == NULL ) {
                    (*f) = 2;
                } else {
                    (*pt) = &(*(*pt))->esq;
                    buscar(x, pt, f);
                }
            } else {
                if( (*(*pt))->dir == NULL ) {
                    (*f) = 3;
                } else {
                    (*pt) = &(*(*pt))->dir;
                    buscar(x, pt, f);
                }
            }
        }
    }
    
}

void inserir(int x, No **ptraiz){
    int f;
    No **pt = ptraiz;
    buscar(x, &pt, &f);

    if( f == 1 ) {
        printf("Elemento já existe\n");
    } else {
        No *novo = (No*)malloc(sizeof(No));
        novo->chave = x;
        novo->esq = novo->dir = NULL;

        if( f == 0 ){
            (*ptraiz) = novo;
        }
        if( f == 2 ){
            (*pt)->esq = novo;
        }
        if( f == 3 ){
            (*pt)->dir = novo;
        } 
    }
}

void remover(int x, No **ptraiz){
    int f;
    No **pt = ptraiz;
    buscar(x, &pt, &f);
    
    if( f != 1 ) {
        printf("Elemento não existe\n");
    } else {
        No *aux = (*pt);
        if( (*pt)->esq == NULL ){
            (*pt) = (*pt)->dir;
        } else {
            if( (*pt)->dir == NULL ){
                (*pt) = (*pt)->esq;
            } else {
                No *s = (*pt)->dir;
                if( s->esq != NULL ){
                    No *PaiS;
                    while( s->esq != NULL ){
                        PaiS = s;
                        s = s->esq;
                    }
                    PaiS->esq = s->dir;
                    s->dir = (*pt)->dir;
                }
                s->esq = (*pt)->esq;
                (*pt) = s;
            }
        }
        free(aux);
    }
}