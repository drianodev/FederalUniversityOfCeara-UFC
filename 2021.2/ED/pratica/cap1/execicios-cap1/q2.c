#include<stdio.h>
#include<stdlib.h>

int main(){
    int x = 1;
    printf("x = %d \n", x);
    int *p = &x; // endereço do x
    printf("*p = %d \n", *p);

    *p = x; // recebe o valor do x
    printf("*p = %d \n", *p);

    int a = (*p); // recebe o valor de *p que é o de x
    printf("a = %d \n", a);
    int *k = &a; // endereço de a
    printf("*k = %d \n", *k);

    x = a; 
    p = k;
    a = x;

    printf("FIM: \n");
    printf("x = %d \n", x);
    printf("p = %d \n", p);
    printf("k = %d \n", k);
    printf("a = %d \n", a);

    return 0;
}