#include <stdio.h>

void somaprod(int x, int y, int s, int p) {
    s = x + y;
    p = x * y;
    printf("somaprod: s = %d, p = %d\n", s, p);
}

int main(){
    int x = 5, y = 10, s, p;
    
    somaprod(x, y, s, p);

    printf("main: s = %d, p = %d\n", s, p);
    return 0;
}
