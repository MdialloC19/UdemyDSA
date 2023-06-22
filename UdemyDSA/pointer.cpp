#include<iostream>
#include<stdlib.h>

using namespace std;
struct Rectangle{
    int length;
    int breadth;
    char x;
};
int main(){
    //create variable of type strcutures dynamically in the heap
    struct Rectangle *p;
    p=(struct Rectangle *)malloc(sizeof(struct Rectangle));
    p->length=10;
    p->breadth=5;
    cout<<(*p).length<<endl;
    /*int a=10;
    int *p;
    char * p1;
    int *p2;
    float *p3;
    short *p4;
    struct Rectangle *p5;
    struct Rectangle r={10,5};
    struct Rectangle *p6=&r;
    cout<<sizeof(p1)<<endl;
    cout<<sizeof(p2)<<endl;
    cout<<sizeof(p3)<<endl;
    cout<<sizeof(p4)<<endl;
    cout<<sizeof(p5)<<endl;
    //Pointer sur structures

    (*p6).length=20;//it' s same of p6->length
    cout<<r.length<<endl;

    p=(int *)malloc(5*sizeof(int));
    p[0]=20; p[1]=12;p[2]=11;p[3]=01;p[4]=23;

    for(int i=0;i<5;i++){
        cout<<p[i]<<endl;
    }*/
}