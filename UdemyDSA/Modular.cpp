#include <iostream>
#include <stdio.h>
using namespace std;

struct Rectangle {
    int length;
    int breadth;
};
void initialize(struct Rectangle *r, int l, int b){
    r->length=l;
    r->breadth=b;
}

int area (struct Rectangle r){
    return r.length*r.breadth;
}
int perimeter(struct Rectangle r){
    return 2*(r.length+r.breadth);
}

int main(){
    Rectangle r={0,0};
    int c=0,b=0;
    printf("Enter Length and Breadth ");
    cin>>c>>b;
    initialize(&r,c,b);
    int a=area(r);
    int p=perimeter(r);
    cout<<"Area= "<<a<<" perimeter= "<<p<<endl;
}
