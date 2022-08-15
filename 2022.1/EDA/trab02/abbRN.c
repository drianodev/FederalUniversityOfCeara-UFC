#include<stdio.h>
#include<stdlib.h>
#include <time.h>


typedef struct no {
	int chave;
	char cor; // R ou N
	struct no *esq, *dir, *pai;
} No;

typedef struct {
	No *raiz, *externo;
} T;


T criarRN() {
	T ptraiz;

	ptraiz.externo = (No*)malloc(sizeof(No));
	ptraiz.externo->cor = "N";
	ptraiz.raiz = ptraiz.externo;

	return ptraiz;
}

/*VALORES*/
int *buscarValores(int quantidadeValores);
/*VERIFICACAO*/
int alturaSub(No *x, No *externo);
int altura(No *x, No *externo);
int verificaRN(No *x, No *externo);
int quantidadeNo(No *x, No *externo);
/*AUXILIARES*/
No *buscaNo(No *x, No *externo, int chave);
No *sucessor(T *ptraiz, No *x);
void moverPai(No *u, No *v, T *ptraiz);
void rotacaoE(T *ptraiz, No *pt);
void rotacaoD(T *ptraiz, No *pt);
/*INSERIR*/
void inserirRN(T *ptraiz, int chave);
void rotaRN(No *z, T *ptraiz);
/*REMOCAO*/
void removerRN(T *ptraiz, int chave);
void rotaRemoverRN(T *ptraiz, No *x);
/*LIBERAR*/
// void liberarSub(No *x, No *externo);
// void liberarRN(T *ptraiz);


int main() {
/*
1. Árvore Rubro-Negra - implementações
    1. Implementar as funções inserir e remover para Árvore Rubro-Negra. Essas implementações devem
    seguir os algoritmos vistos em aula (mesma do livro do Cormen).
    2. Implementar uma função que verifica se uma árvore é Rubro-Negra fazendo o cálculo das alturas
    negras das subárvores de cada nó e verificar se essas alturas não iguais.
    3. Implementar uma função que conta a quantidades de nós de uma Árvore Rubro-Negra.

2. Testes
    1. Deve-se criar 1.000 Árvores Rubro-Negras.
    2. Em cada Árvore Rubro-Negra deve-se inserir aleatoriamente 10.000 nós onde a chave de cada nó está
    entre 0 e 100.000 (verificar se a Árvore Rubro-Negra possui os 10.000 pelo algoritmo de contagem de
    nós)
    3. Após todas as inserções verificar se a árvore continua Rubro-Negra pelo algoritmo de verificação.
    4. Remover 1.000 nós (verificar se a Árvore Rubro-Negra possui os 9.000 nós pelo algoritmo de contagem
    de nós)
    5. Após todas as remoções verificar se a árvore continua Rubro-Negra pelo algoritmo de verificação.
    O processo anterior pode ser realizado com uma Árvore Rubro-Negra por vez, isto é, não é necessário ter
    1.000 Árvores Rubro-Negras ao mesmo tempo em sua memória, mas apenas 1 por vez.
*/
	/*
	for (int i = 0; i < 1000; i++) { //1.000 arvores

		T ptraiz = criarRN();
        
		int *valores = buscarValores(10000);

		printf("\n");

		for(int i = 0; i < 10000; i++) // inserir 10.000 nós
			inserirRN(&ptraiz, valores[i]);

        printf("\n\nRubro Negra Nº -> %d com %d nos.\n", i+1, quantidadeNo(ptraiz.raiz, ptraiz.externo));

		if(verificaRN(ptraiz.raiz, ptraiz.externo))
			printf("É RN.\n");

		printf("Removendo...\n");

		for(int i = 0; i < 1000; i++) // remover 1000 nós
			removerRN(&ptraiz, valores[i]);

		printf("Rubro Negra Nº -> %d com %d nos.\n", i+1, quantidadeNo(ptraiz.raiz, ptraiz.externo));

		if(verificaRN(ptraiz.raiz, ptraiz.externo))
			printf("É RN.\n");

		printf("\n");

		//free(valores);
		//liberarRN(&ptraiz);
	}*/

	/*TESTE APRESENTAÇÃO*/
	for (int i = 0; i < 100; i++) { //100 arvores

		T ptraiz = criarRN();
        
		int *valores = buscarValores(10000);

		printf("\n");

		for(int i = 0; i < 10000; i++) // inserir 10.000 nós
			inserirRN(&ptraiz, valores[i]);

        printf("\n\nRubro Negra Nº -> %d com %d nos.\n", i+1, quantidadeNo(ptraiz.raiz, ptraiz.externo));

		if(verificaRN(ptraiz.raiz, ptraiz.externo))
			printf("É RN.\n");

		printf("Removendo...\n");

		for(int i = 0; i < 1000; i++) // remover 1000 nós
			removerRN(&ptraiz, valores[i]);

		printf("Rubro Negra Nº -> %d com %d nos.\n", i+1, quantidadeNo(ptraiz.raiz, ptraiz.externo));

		if(verificaRN(ptraiz.raiz, ptraiz.externo))
			printf("É RN.\n");

		printf("\n");
	}

	return 0;
}

/*VALORES*/

int *buscarValores(int quantidadeValores) {
    
	int *valores = malloc(sizeof(int) * quantidadeValores);
    int x = 1;

	srand(time(NULL));

    for (int j = 1; j <= 10000; j++) { //10.000 nós
            
            do {
                x = 1;
                int x = (rand() % 100000);// entre 0 e 100.000
                
                for (int k = 0; k < j; k++){
                    if (valores[k] == x){
                        x = 0;
                    }
                }

                if (x){
                    valores[j] = x;
                }
            } while (!x);
        }

	return valores;
}

/*VERIFICACAO*/

int alturaSub(No *x, No *externo) {
	if(x == externo) {
		return 1;
    }

	int alturaE = alturaSub(x->esq, externo),
	    alturaD = alturaSub(x->dir, externo);

    int aux;

    if(x->cor == "N") {
        aux = 1;
    } else {
        aux = 0;
    }

	if(alturaE != alturaD || alturaE == -1) {
		return -1;
    } else {
		return alturaE + aux;
    }
}

int altura(No *x, No *externo) {
	if(x == externo)
		return 1;

	int alturaE = alturaSub(x->esq, externo),
	    alturaD = alturaSub(x->dir, externo);

	if(alturaE != alturaD || alturaE == -1)
		return -1;
	else
		return alturaE;
}

int verificaRN(No *x, No *externo) {
	if(x == externo)
		return 1;

	if(altura(x, externo) != -1)
		if(verificaRN(x->esq, externo))
			return verificaRN(x->dir, externo);

	return 0;
}

int quantidadeNo(No *x, No *externo) {
	if(x == externo)
		return 0;

	return 1 + quantidadeNo(x->esq, externo) + quantidadeNo(x->dir, externo);
}

/*AUXILIARES*/

No *buscaNo(No *x, No *externo, int chave) {
	if(x == externo) {
		return externo; 
    }

    if(chave < x->chave) {
		buscaNo(x->esq, externo, chave);
    } else if(chave > x->chave) {
		buscaNo(x->dir, externo, chave);
	} else {
		return x;
    }
}

No *sucessor(T *ptraiz, No *x) {

	while(x->esq != ptraiz->externo) {
		x = x->esq;
    }
	return x;
}

void moverPai(No *u, No *v, T *ptraiz) {

	if(u->pai == ptraiz->externo) {
		ptraiz->raiz = v;
	} else {
        if(u == u->pai->esq)
		    u->pai->esq = v;
	    else
		    u->pai->dir = v;
    }
	v->pai = u->pai;
}

void rotacaoE(T *ptraiz, No *pt) {

	No *y = pt->dir;
	pt->dir = y->esq;

	if(y->esq != ptraiz->externo) {
		y->esq->pai = pt;
    }

	y->pai = pt->pai;

	if(pt->pai == ptraiz->externo) {
		ptraiz->raiz = y;
    } else if(pt == pt->pai->esq) {
		pt->pai->esq = y;
    } else {
		pt->pai->dir = y;
    }

	y->esq = pt;
	pt->pai = y;
}

void rotacaoD(T *ptraiz, No *pt) {

	No *y = pt->esq;
	pt->esq = y->dir;

	if(y->dir != ptraiz->externo) {
		y->dir->pai = pt;
    }

	y->pai = pt->pai;

	if(y->pai == ptraiz->externo) {
		ptraiz->raiz = y;
    } else if (pt == pt->pai->dir) {
		pt->pai->dir = y;
	} else {
		pt->pai->esq = y;
    }

	y->dir = pt;
	pt->pai = y;
}

/*INSERIR*/

void inserirRN(T *ptraiz, int chave) {

	No *y = ptraiz->externo;
	No *pt = ptraiz->raiz;
	No *z = (No*)malloc(sizeof(No));
	z->chave = chave;

	while(pt != ptraiz->externo) {
		y = pt;

		if(z->chave < pt->chave)
			pt = pt->esq;
		else
			pt = pt->dir;
	}

    if(y != NULL) {
        z->pai = y;
        if(y == ptraiz->externo) {
		    ptraiz->raiz = z;
        } else {
            if(z->chave < y->chave) {
                y->esq = z;
            } else {
                y->dir = z;
            }
        }
    }
    z->cor = "R";
	z->esq = ptraiz->externo;
	z->dir = ptraiz->externo;

	rotaRN(z, ptraiz);
}

void rotaRN(No *z, T *ptraiz) {

	while(z->pai->cor == "R") {

		if(z->pai == z->pai->pai->esq) {

			No *y = z->pai->pai->dir;

			if(y->cor == "R") {
				z->pai->cor = "N";
				y->cor = "N";
				z->pai->pai->cor = "R";
				z = z->pai->pai;
			} else {
				if(z == z->pai->dir) {
					z = z->pai;
					rotacaoE(ptraiz, z);
				}

				z->pai->cor = "N";
				z->pai->pai->cor = "R";
				rotacaoD(ptraiz, z->pai->pai);
			}
		} else {
			No *y = z->pai->pai->esq;

			if(y->cor == "R") {
				z->pai->cor = "N";
				y->cor = "N";
				z->pai->pai->cor = "R";
				z = z->pai->pai;
			} else {
				if(z == z->pai->esq) {
					z = z->pai;
					rotacaoD(ptraiz, z);
				}

				z->pai->cor = "N";
				z->pai->pai->cor = "R";
				rotacaoE(ptraiz, z->pai->pai);
			}
		}
	}

	ptraiz->raiz->cor = "N";
}

/*REMOCAO*/

void removerRN(T *ptraiz, int chave) {

    No *y;
    No *x;
	No *z = buscaNo(ptraiz->raiz, ptraiz->externo, chave);

    y = z;
	char corOriginal = y->cor;

	if(z->esq == ptraiz->externo) {
		x = z->dir;
		moverPai(z, z->dir, ptraiz);
	} else {
        if(y->dir == ptraiz->externo) {
		    x = z->esq;
		    moverPai(z, z->esq, ptraiz);
        } else {
            y = sucessor(ptraiz, z->dir); // slides tem so z
            corOriginal = y->cor;
            x = y->dir;

            if(y->pai == z)
                x->pai = y;
            else {
                moverPai(y, x, ptraiz);
                y->dir = z->dir;
                y->dir->pai = y;
            }

            moverPai(z, y, ptraiz);
            y->esq = z->esq;
            y->esq->pai = y;
            y->cor = z->cor;
        }
    }

	if(corOriginal == "N") {
		rotaRemoverRN(ptraiz, x);
    }

	free(z);
}

void rotaRemoverRN(T *ptraiz, No *x) {

    No *w;

	while(x != ptraiz->raiz && x->cor != "R") {
		if(x == x->pai->esq) {

			w = x->pai->dir;

			if(w->cor == "R") {
				w->cor = "N";
				x->pai->cor = "R";
				rotacaoE(ptraiz, x->pai);
				w = x->pai->dir;
			}

			if(w->dir->cor == "N" && w->esq->cor == "N") {
				w->cor = "R";
				x = x->pai;
			} else {
				if(w->esq->cor == "R") {
					w->esq->cor = "N";
					w->cor = "R";
					rotacaoD(ptraiz, w);
					w = x->pai->dir;
				}

				w->cor = x->pai->dir->cor;
				w->dir->cor = "N";
				rotacaoE(ptraiz, x->pai);
				x = ptraiz->raiz;
			}
		} else {
			w = x->pai->esq;

			if(w->cor == "R") {
				w->cor = "N";
				x->pai->cor = "R";
				rotacaoD(ptraiz, x->pai);
				w = x->pai->esq;
			}

			if(w->dir->cor == "N" && w->esq->cor == "N") {
				w->cor = "R";
				x = x->pai;
			} else {
				if(w->dir->cor == "R") {
					w->dir->cor = "N";
					w->cor = "R";
					rotacaoE(ptraiz, w);
					w = x->pai->esq;
				}

				w->cor = x->pai->esq->cor;
				w->esq->cor = "N";
				rotacaoD(ptraiz, x->pai);
				x = ptraiz->raiz;
			}
		}
	}

	x->cor = "N";
}

/*LIBERAR*/
void liberarSub(No *x, No *externo) {
	if(x != externo) {
		liberarSub(x->esq, externo);
		liberarSub(x->dir, externo);
		free(x);
	}
}

void liberarRN(T *ptraiz) {
	liberarSub(ptraiz->raiz, ptraiz->externo);
	free(ptraiz->externo);
}