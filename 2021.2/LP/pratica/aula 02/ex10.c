#include <stdio.h>

/* FORMULA GERAL DE UMA FUNÇAO:
tipo_retornado nome_da_funcao(parametros){
    corpo da funcao
}*/
int fat(int n) {
    int i, p = 1;

    if(n == 0 || n == 1) {
        return 1;
    } else {
        for(i = 1; i <= n; i++) {
            p *= i;
        }
    }
    return p;
}

int main(){
    printf("%d\n", fat(5));
    return 0;
}