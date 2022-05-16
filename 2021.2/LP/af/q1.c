#include <stdio.h>

void PA(int x, int n);
int primo(int num);

int main(){

    PA(5, 4);

    return 0;
}

int primo(int num){
    int primo;
    
    // DETERMINAR SE É PRIMO
    for(int i = 1; i <= num; i++) {
        if (num % i == 0) {
            primo++;
        }
    }

    if (primo == 2) {
        primo = 0;
        return num;
    } else {
        primo = 0;
        return 0;
    }
}

void PA(int x, int n){
    int aux, contador = 0;

    for (int i = 0; i < x+n; i++) {

        aux = x + (n-1) * i;

        if(primo(aux) != 0) {
            printf("%d \n", aux);
            aux = 0;
            contador++;
            if(contador == n) {
                break;
            }
        }
    }
}