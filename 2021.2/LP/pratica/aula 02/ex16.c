#include <stdio.h>

int main(){
    int a, b, *p, *q;

    a = 5;
    printf("%d\n", a);
    printf("%d\n", &a);

    p = &a;
    printf("%d\n", p);

    *p = 6;
    printf("%d\n", *p);

    printf("%d\n", a);
    //***************************
    a = 2;
    printf("%d\n", a);
    printf("%d\n", &a);

    *q = 3; // aqui tem lixo de memori, apontando pra um aleatorio
    printf("%d\n", *q);

    b = a + (*q);
    printf("%d\n", b); //error de segmentação

    return 0;
}
