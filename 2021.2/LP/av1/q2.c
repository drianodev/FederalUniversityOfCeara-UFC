#include <stdio.h>
#include <stdlib.h>

int func ( int m , int n);

int main(){
    int m, n;

    printf("Digite m: \n");
    scanf("%d", &m);
    printf("Digite n: \n");
    scanf("%d", &n);

    func(m, n);

    printf("\n");
    return 0;
}

int func ( int m , int n) {
    int max =0;
    for ( int x =0; x < m ; x ++) {
        for ( int y =0 ; y < n ; y ++) {
            if(x*y - x*x +y > max )
                max = x*y - x*x +y ;
        }
    }
 
    for ( int x =0; x < m ; x ++) {
        for( int y =0 ; y < n ; y ++) {
            if(x*y - x*x +y == max )
                printf ("%d %d\n",x ,y );
        }
    }

    return max ;
}