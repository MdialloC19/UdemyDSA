#include<iostream>
#include<stdlib.h>

using namespace std;
int add(int a,int b){
    int c=a+b;
    return c;
}
int main(){
    int x,y,z;
    x=5;
    y=7;
    z=add(x,y);

    cout<<z<<endl;
    
}