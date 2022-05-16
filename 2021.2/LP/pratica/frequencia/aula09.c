#include <stdio.h>
#include <time.h>

int fibonacci_rec(int n);
int fibonacci_ite(int n);
int digitos(int n);
int digitos_que_possui(int n, int m);
int permutacao(int x, int y);
int sufixo(int x, int y);
int segmento(int x, int y);

int main(){
    int n, i;

    printf("Lista 2\n");
    printf("Questão 2\n");
    printf("item a)\n");
    printf("Digite um número: ");
    scanf("%d", &n);
    printf("\n");

    for(i = 1; i <= n; i++) {
        printf("%d ", fibonacci_rec(i));
    }
    printf("\n");
    printf("---------------------------------------------");
    printf("\n");
/*-------------------------------------------*/
    int m, j;

    printf("item b)\n");
    printf("Digite um número: ");
    scanf("%d", &m);
    printf("\n");

    for(j = 1; j <= m; j++) {
        printf("%d ", fibonacci_ite(j));
    }
    printf("\n");
    printf("---------------------------------------------");
    printf("\n");
/*-------------------------------------------*/
    int o, k, l;
    clock_t tempo_inicial_rec, tempo_final_rec, tempo_inicial_ite, tempo_final_ite;

    printf("item c)\n");
    printf("Digite um número: ");
    scanf("%d", &o);
    printf("\n");

    printf("Inicio da marcação de tempo da função recursiva\n");
    tempo_inicial_rec = clock();

    for(k = 1; k <= o; k++) {
        fibonacci_rec(k);
    }
    tempo_final_rec = clock();
    printf("Termino da marcação de tempo da função recursiva\n");

    printf("\n");

    printf("Inicio da marcação de tempo da função iterativa\n");
    tempo_inicial_ite = clock();

    for(l = 1; l <= o; l++) {
        fibonacci_rec(l);
    }
    tempo_final_ite = clock();
    printf("Termino da marcação de tempo da função iterativa\n");

    printf("\n");

    printf("Tempo gasto na função recursiva:\n");
    printf("%f ms\n\n" , 1000 * (double)(tempo_final_rec - tempo_inicial_rec) / (double)(CLOCKS_PER_SEC));

    printf("Tempo gasto na função iterativa:\n");
    printf("%f ms\n\n" , 1000 * (double)(tempo_final_ite - tempo_inicial_ite) / (double)(CLOCKS_PER_SEC));

    printf("\n");
    printf("---------------------------------------------");
    printf("\n");
/*-------------------------------------------*/
    int p;

    printf("Questão 3\n");
    printf("item a)\n");
    printf("Digite um número: ");
    scanf("%d", &p);
    printf("\n");

    printf("A quantidade de digitos no número %d é %d\n", p, digitos(p));

    printf("\n");
    printf("---------------------------------------------");
    printf("\n");
/*-------------------------------------------*/
    int q, r;

    printf("item b)\n");
    printf("Digite um número: ");
    scanf("%d", &q);
    printf("\n");
    printf("Digite outro número entre 0 e 9: ");
    scanf("%d", &r);
    printf("\n");

    printf("A quantidade de digitos %d que o número %d possui é %d\n", r, q, digitos_que_possui(q, r));

    printf("\n");
    printf("---------------------------------------------");
    printf("\n");
/*-------------------------------------------*/
    int x, y;

    printf("item c)\n");
    printf("Digite um número: ");
    scanf("%d", &x);
    printf("\n");
    printf("Digite outro número: ");
    scanf("%d", &y);
    printf("\n");

    printf("O número %d é permutação de %d == %d (1-True e 2-False)\n", x, y, permutacao(x, y));

    printf("\n");
    printf("---------------------------------------------");
    printf("\n");
/*-------------------------------------------*/
    int x1, y1;

    printf("item d)\n");
    printf("Digite um número: ");
    scanf("%d", &x1);
    printf("\n");
    printf("Digite outro número: ");
    scanf("%d", &y1);
    printf("\n");

    printf("O número %d é sufixo de %d == %d (1-True e 2-False)\n", x1, y1, sufixo(x1, y1));

    printf("\n");
    printf("---------------------------------------------");
    printf("\n");
/*-------------------------------------------*/
    int x2, y2;

    printf("item e)\n");
    printf("Digite um número: ");
    scanf("%d", &x2);
    printf("\n");
    printf("Digite outro número: ");
    scanf("%d", &y2);
    printf("\n");

    printf("O número %d é segmento de %d == %d (1-True e 2-False)\n", x2, y2, segmento(x2, y2));

    printf("\n");
    printf("---------------------------------------------");
    printf("\n");
    return 0;
}

/*-------------------------------------------*/
int fibonacci_rec(int n) {
    int x;

    if(n == 1) {
        return 1;
    }

    if(n == 2) {
        return 1;
    }

    x = fibonacci_rec(n-1) + fibonacci_rec(n-2);
    return x;
}

int fibonacci_ite(int n) {
    int i, x, y = 1, z = 1;

    if(n == 1) {
        return y;
    } else {
        if(n == 2) {
            return z;
        } else {
            for(i = 2; i < n; i++) {
                x = y + z;
                y = z;
                z = x;
            }
            return x;
        }
    }
}

int digitos(int n) {
    int dig = 0;

    if(n >= 10) {
        while (n > 0) {
            dig += 1;
            n = n / 10;
        }
    } else {
        dig = 1;
    }
    return dig;
}

int digitos_que_possui(int n, int m) {
    int dig = 0;

    if(n == 0 && m == 0) {
        return 1;
    }
    while (n != 0) {
        if(m == n % 10) {
            dig++;
        }
        n = n / 10;
    }
    return dig;
}

int permutacao(int x, int y) {

    for(int i = 0; i <= 9; i++) {
        if(digitos_que_possui(x, i) != digitos_que_possui(y, i)) {
            return 0;
        }
    }
    return 1;
}

int sufixo(int x, int y) {

    if(x > y) {
        return 0;
    }
    while(x != 0) {
        if(x % 10 != y % 10) {
            return 0;
        }
        x = x / 10;
        y = y / 10;
    }
    return 1;
}

int segmento(int x, int y){
    int i;

    if(x > y) {
        i = x;
        x = y;
        y = i;
    }

    while(x <= y) {
        if (sufixo(x, y) == 1) {
            return 1;
        }
        y = y / 10;
    }
    return 0;
}