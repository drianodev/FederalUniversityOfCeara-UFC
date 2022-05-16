#include <stdlib.h>
#include <stdio.h>

typedef struct no{
    char valor;
    struct no *prox;
}NO;

NO *topo = NULL;
int tam = 0;

void adicionar(char valor){

    NO *novo = malloc(sizeof(NO));
    novo->valor = valor;

    //muito simples
    novo->prox = topo;
    topo = novo;
    tam++;

}

char remover(){

    if(tam > 0) {
        NO *lixo = topo;
        topo = topo->prox;

        char valor_removido = topo->valor;
        
        free(lixo);
        tam--;

        return valor_removido;

    } else {
        printf("Pilha está vazia \n");
        return ' ';
    }
}

void imprimir(){

    NO* aux = topo;

    for(int i = 0; i < tam; i++){
        printf("%c\n", aux->valor);

        aux = aux->prox;
    }
}

int main(){

    char texto[8];
    texto[0] = 'L';
    texto[1] = 'Q';
    texto[2] = 'P';
    texto[3] = 'A';
    texto[4] = 'R';
    texto[5] = 'S';
    texto[6] = 'U';
    texto[7] = '\n';

    printf("Texto inicial: \n");
    for(int i = 0; i < 8; i++) {
        printf("%c", texto[i]);
    }

    // LOGICA DA QUESTÃO
    int indice_inicial = -1; //não foi encontrado sequencia de consoante

    for(int i = 0; i < 8; i++) {
        int aux = texto[i];
        if(aux != 65 && aux != 69 && aux != 73 && aux != 79 && aux != 85) {
            //consoante
            if(indice_inicial == -1) { //primeira da sequencia
                indice_inicial = i;
            }
            adicionar(texto[i]);
        } else {
            //vogal
            //1 - verificar se a pilha nao esta vazia
            //2 - desempilhar trocando a sequencia de consosantes para o inverso

            while(topo != NULL) { //nao esta vazia
                texto[indice_inicial] = remover();
                indice_inicial++;
            }
            indice_inicial = -1; // nao encontrei sequencias de consoante
        }
    }
    // termina com consoante
    while(topo != NULL) { //nao esta vazia
        texto[indice_inicial] = remover();
        indice_inicial++;
    }

    printf("\n\nTexto cripto: \n");
    for(int i = 0; i < 8; i++) {
        printf("%c", texto[i]);
    }

    return 0;
}
