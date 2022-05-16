#include <stdio.h>
// PONTEIROS

// void = não tem retorno pois é um procedimento 
void somaprod(int x, int y, int *s, int *p) {
    (*s) = x + y;
    (*p) = x * y;
    // printa o endereco da memoria
    printf("somaprod: s = %d, p = %d\n", s, p);
}

int main(){
    int x = 5, y = 10, s, p;
    
    somaprod(x, y, &s, &p);

    printf("main: s = %d, p = %d\n", s, p);
    return 0;
}
