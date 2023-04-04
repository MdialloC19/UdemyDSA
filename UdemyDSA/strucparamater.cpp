#include<iostream>
#include<stdlib.h>

using namespace std;

struct Rectangle {
    int length;
    int breadth;
};

struct Rectangle *func(){
    struct Rectangle *p;
    p=(struct Rectangle *)malloc(sizeof(struct Rectangle ));
    p->length=15;
    p->breadth=7;
    return p;
}
int main(){
    struct Rectangle *ptr=func();
    cout<<"length "<<ptr->length<<endl<<"Breadth "<<ptr->breadth<<endl;
}
