#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
}* first=NULL;

void create(int A[], int n){
    int i;
    struct Node *t, *last;
    first =(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;

    for ( i = 1; i < n; i++)
    {
        t =(struct Node *) malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

int Count (struct Node *p){

    int c=0;
    while(p){
        c++;
        p=p->next;
    }
    return c;
}
int RCount (struct Node *p){

    if(p)
        return RCount(p->next)+1;
    else
        return 0;

}

int Add(struct Node *p){
    int sum=0;
    while(p){
        sum=sum+p->data;
        p=p->next;
    }
    return sum;
}


int RAdd(struct Node *p){
    int sum=0;
    if(p)
        return RAdd(p->next)+p->data;
    return 0;
}

void display(struct Node *p)
    {
        while(p!=NULL){
            printf("%d ",p->data);
            p=p->next;
        }

    }

void Rdisplay(struct Node *p)
    {
        if(p!=NULL){
            printf("%d ",p->data);
            Rdisplay(p->next);
        }

    }

void Rdisplay1(struct Node *p)
    {
        if(p!=NULL){
            Rdisplay1(p->next);
            printf("%d ",p->data);
        }

    }
    

int main(int argc, char const *argv[])
{
    int A[]={1,4,5,2,6,1,10,9};
    create(A,8);
    //Rdisplay1(first);
    printf("%d\n ",Add(first));
    return 1;
}
