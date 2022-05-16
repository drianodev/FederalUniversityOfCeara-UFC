#include <stdio.h>

int main(){
    int x, y;
    char op;

    printf("DIgite um num:\n");
    scanf("%d %c %d", &x, &op, &y);
    
    switch(op) {
        case '+':
            printf("= %d\n", x+y);
        break;
        case '-':
            printf("= %d\n", x-y);
        break;
        default:
            printf("op invalido\n");
        break;
    }
    
    return 0;
}