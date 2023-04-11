#include <stdio.h>

int fun(int n){
    if(n>100)
        return n-10;
    else
        return fun(fun(n+11));
}

int main(){
    int a;
    a=fun(95);
    printf("%d\n ",a);

    return 0;
}