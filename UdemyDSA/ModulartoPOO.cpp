#include <iostream>
#include <stdio.h>
using namespace std;

class Rectangle {
    public :
        int length;
        int breadth;

void initialize(int l, int b){
    length=l;
    breadth=b;
}

int area (){
    return length*breadth;
}
int perimeter(){
    return 2*(length+breadth);
}
};

int main(){
    Rectangle r={0,0};
    int c=0,b=0;
    printf("Enter Length and Breadth ");
    cin>>c>>b;
    r.initialize(c,b);
    int a=r.area();
    int p=r.perimeter();
    cout<<"Area= "<<a<<" perimeter= "<<p<<endl;
    return 0;
}
