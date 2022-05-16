#include <stdio.h>

typedef struct ponto{
    float x, y;
} Ponto;

typedef struct retangulo{
    Ponto v1, v2;
} Retangulo;

typedef struct aluno{
    char nome[80], turma[120];
    int matricula;
    float nota1, nota2, nota3;
} Aluno;

int q5(Retangulo *r,Ponto *p);
void q6(Aluno *estudante);

int main() {
    printf("Lista 5 \n");
    printf("Questão 5 \n");

    Ponto p;
    Retangulo r;

    printf("Digite o valor de x para o v1: ");
    scanf("%f", &r.v1.x);
    printf("\n");
    printf("Digite o valor de y para o v1: ");
    scanf("%f", &r.v1.y);
    printf("\n");

    printf("Digite o valor de x para o v2: ");
    scanf("%f", &r.v2.x);
    printf("\n");
    printf("Digite o valor de y para o v2: ");
    scanf("%f", &r.v2.y);
    printf("\n");

    printf("Digite o valor de x para o ponto: ");
    scanf("%f", &p.x);
    printf("\n");
    printf("Digite o valor de y para ponto: ");
    scanf("%f", &p.y);
    printf("\n");
    printf("v1 = (%.1f, %.1f) \n", r.v1.x, r.v1.y);
    printf("v2 = (%.1f, %.1f) \n", r.v2.x, r.v2.y);
    printf("p = (%.1f, %.1f) \n", p.x, p.y);
    printf("\n");

    printf("return %d \n", q5(&r, &p));
/*------------------------------------------------------------------------------------*/
    printf("Questão 6 \n");

    Aluno estudante;

    printf("Digite o nome do aluno: ");
    scanf("%s", &estudante.nome);
    printf("\n");
    printf("Digite a turma do aluno: ");
    scanf("%s", &estudante.turma);
    printf("\n");
    printf("Digite a matricula: ");
    scanf("%d", &estudante.matricula);
    printf("\n");
    printf("Digite a nota 1: ");
    scanf("%f", &estudante.nota1);
    printf("\n");
    printf("Digite a nota 2: ");
    scanf("%f", &estudante.nota2);
    printf("\n");
    printf("Digite a nota 3: ");
    scanf("%f", &estudante.nota3);
    printf("\n");

    q6(&estudante);

    printf("\n");
    return 0;
}

int q5(Retangulo *r,Ponto *p){
    int n = 0;
    
    if(p->x > r->v1.x && p->x > r->v1.y && p->x < r->v2.x && p->x < r->v2.y) {
        n = 1;
    }

    return n;
}

void q6(Aluno *estudante){
    printf("matricula: %d \n", estudante->matricula);
    printf("nome: %s \n", estudante->nome);
    printf("media: %f \n", ((estudante->nota1 + estudante->nota2 + estudante->nota3)/3));
}