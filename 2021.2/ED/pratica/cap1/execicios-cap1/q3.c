#include<stdio.h>
#include<stdlib.h>

typedef struct Aviso_Covid{
    
    int coronaASolta;
    
    struct Aviso_Covid *fiqueEmCasa;
    
}Corona;

int main(){
    Corona *laveAsMaos, *useAlcool;

    laveAsMaos = malloc(sizeof(Corona));
    useAlcool = malloc(sizeof(Corona));

    laveAsMaos->coronaASolta = 19;
    laveAsMaos->fiqueEmCasa = useAlcool;

    useAlcool->coronaASolta = 100;
    useAlcool->fiqueEmCasa = NULL;
    
    printf("Cuidado com o COVID-%d! Fique %d porcento dentro de casa lendo o livro de ED!\n",
            laveAsMaos->coronaASolta, useAlcool->coronaASolta);
    
    return 0;
}
