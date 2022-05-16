#include <stdio.h>

int main(){
    int x;
    
    do {
        printf("Digite um num >= 10\n", x);
        scanf("%d", &x);
    } while(x < 10);
    
    return 0;
}