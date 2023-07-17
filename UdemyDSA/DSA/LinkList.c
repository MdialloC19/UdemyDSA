#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
}* first=NULL;


// Creating a link list
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

//Counting element of link list
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
// Adding element of the list
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
// finding maximum value of list element;


int Max(struct Node *p){
    int max=-3276;
    while(p){
        if(p->data>max)
            max=p->data;
        p=p->next;
   
    }
    return max;
}
int RMax(struct Node *p){
    int max=-3276,x=0;

    if(p==NULL)
        return max;
    else
        x=Max(p->next);
        if(x>p->data)
            return x;
        else
            return p->data;
}

//Linear Searsh

struct Node * LSearsh(struct Node *p, int key){
    struct Node *q;
    while(p!=NULL){
        if(key==p->data){
            q->next=p->next;
            p->next=first;
            first=p;
            return p;
        }
        q=p;
        p=p->next;
    }
    return NULL;      
}

struct Node * RSearsh(struct Node *p, int key){

    if(p==NULL)
        return NULL;
    if(key==p->data)
        return p;
    return RSearsh(p->next,key);
}

// displaying element of the list

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
    int A[]={1,4,5,29,2,6,1,10,9};
    struct Node *temp;
    create(A,8);
    //Rdisplay1(first);
    // printf("%d\n ",Max(first));
    
    temp=LSearsh(first,29);

    if(temp)
        printf("Key is found %d\n", temp->data);
    else
        printf("Key isn't found\n ");

    display(first);
    return 1;
}



