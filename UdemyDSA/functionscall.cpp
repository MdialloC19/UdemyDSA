#include<iostream>
#include<stdlib.h>

using namespace std;
void swap (int &x,int &y){// passe by reference, only valid on cpp
    int temp;
    temp=x;
    x=y;
    y=temp;
}
int main(){
    int x,y,z;
    x=5;
    y=7;
    swap(x,y);
    cout<<"First Number "<<x<<endl;
    cout<<"Second number Number "<<y<<endl;
return 0;
    
}