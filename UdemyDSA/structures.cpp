#include <stdio.h>
#include<iostream>
using namespace std;

struct  Card
    {
       int face ;
       int shape;
       int color;
    };
struct Rectangle{
    int length;
    int breadth;
    char x;
};

int main(){

    struct Rectangle r1={10,5};
    printf("%d\n ",sizeof(r1));
    cout<<r1.length<<endl;
    cout<<r1.breadth<<endl;

    struct Card deck[52]={{1,0,0},{2,0,0},{1,1,0}};

    printf("%lu\n ",deck[1].face);
    
    

}