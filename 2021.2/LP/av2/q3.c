#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ITEM A)
typedef struct produto {
    char nome[51];
    int codigo;
    float valor;
    char descricao[121];
} Produto;

// ITEM B)
typedef struct cliente {
    char nome[51];
    char cpf[12]; // tipo int na realidade
    char endereco[121];
    Produto compras[300];
} Cliente;

void item_c(Cliente c);

int main() {
    printf("Questão 3 \n");

    // ITEM C)
    Cliente cliente1;

    strcpy(cliente1.nome, "Adriano");
    strcpy(cliente1.cpf, "09616941305");
    strcpy(cliente1.endereco, "rua 1,553");

    strcpy(cliente1.compras->nome[0], "pao");
    // cliente1.compras->codigo[0] = 1;
    // cliente1.compras->valor[0] = 10;
    strcpy(cliente1.compras->descricao[0], "2 paes");

    // strcpy(cliente1.compras->nome, "suco");
    // cliente1.compras->codigo = 2;
    // cliente1.compras->valor = 50;
    // strcpy(cliente1.compras->descricao, "5 sucos");

    // strcpy(cliente1.compras->nome, "leite");
    // cliente1.compras->codigo = 3;
    // cliente1.compras->valor = 20;
    // strcpy(cliente1.compras->descricao, "2 leites");

    item_c(cliente1);

    printf("\n");
    return 0;
}

void item_c(Cliente c){
    printf("Nome do cliente: %s \n", c.nome);
    printf("CPF do cliente: %s \n", c.cpf); // %ld
    printf("Endereço do cliente: %s \n", c.endereco);
    printf("Nome do produto: %s \n", c.compras->nome[0]);

    printf("Produtos do cliente: \n");
    // for(int i = 0; i < sizeof(c.compras); i++) {
    //     printf("Codigo do produto: %d \n", c.compras[i]->codigo);
    //     printf("Nome do produto: %s \n", c.compras[i]->nome);
    // }
}