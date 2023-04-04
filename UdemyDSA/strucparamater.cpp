#include<iostream>
#include<stdlib.h>

using namespace std;

struct Rectangle {
    int length;
    int breadth;
};

void func(struct Rectangle *p){
    p->length=20;
    cout<<"length "<<p->length<<endl<<"Breadth "<<p->breadth<<endl;
}

int main (){
    struct  Rectangle r={10,5};
    func(&r);
    cout<<"length "<<r.length<<endl<<"Breadth "<<r.breadth<<endl;
    return 0;
}