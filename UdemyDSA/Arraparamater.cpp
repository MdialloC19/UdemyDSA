#include<iostream>
#include<stdlib.h>

using namespace std;
/*void fun(int A[]) {
    int n=sizeof(A)/sizeof(int);
    int i;
    for (i=0;i<n;i++){
        cout<<"Valeur A["<<i<<"]="<<A[i]<<endl;
    }
}*/
int * fun(int n){
    int *p;
    p=(int *)(malloc(n*sizeof(int)));
     for (int i=0;i<n;i++){
        p[i]=i+1;
     }
    return p;
}
int main(){
   int  *ptr,sz=5;
    ptr=fun(sz);
    for (int i=0;i<sz;i++){
        cout<<"Valeur A["<<i<<"]="<<ptr[i]<<endl;
    }
return 0;
    
}