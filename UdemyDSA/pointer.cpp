#include<iostream>
#include<stdlib.h>

using namespace std;
struct Rectangle{
    int length;
    int breadth;
    char x;
};
int main(){
    int a=10;
    int *p;
    
    char * p1;
    int *p2;
    float *p3;
    short *p4;
    struct Rectangle *p5;
    cout<<sizeof(p1)<<endl;
    cout<<sizeof(p2)<<endl;
    cout<<sizeof(p3)<<endl;
    cout<<sizeof(p4)<<endl;
    cout<<sizeof(p5)<<endl;
    

    

    p=(int *)malloc(5*sizeof(int));
    p[0]=20; p[1]=12;p[2]=11;p[3]=01;p[4]=23;

    for(int i=0;i<5;i++){
        cout<<p[i]<<endl;
    }
}