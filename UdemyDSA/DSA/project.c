
#include <stdio.h>
#include <stdlib.h>


struct Noeud{
    int donne;
    struct Noeud *suiv;
    }*top=NULL;

void empiler(int x){
    struct Noeud *t;
    t=(struct Noeud*)malloc(sizeof(struct Noeud));

    if(t==NULL)
        printf("stack is full\n");
    else{
        t->donne=x;
        t->suiv=top;
        top=t;
    }
}

int depiler() {
    struct Noeud *t;
    int x=-1;
    if(top==NULL)
        printf("Stack is Empty\n");
    else{
        t=top;
        top=top->suiv;
        x=t->donne;
        free(t);
    }
    return x;
}

void afficher(){
    struct Noeud *p;
    p=top;
    while(p!=NULL){
        printf("%d ",p->donne);
        p=p->suiv;
    }
    printf("\n");
}

int main(){

    empiler(10);
    empiler(20);
    empiler(30);
    afficher();
    printf("%d\n ",depiler());
    return 0;
}
