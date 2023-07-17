#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Noeud {
    int donne;
    struct Noeud *suiv;
};


void empiler(int x, struct Noeud **pile) {
    struct Noeud *t;
    t = (struct Noeud*)malloc(sizeof(struct Noeud));

    if (t == NULL)
        printf("La pile est pleine\n");
    else {
        t->donne = x;
        t->suiv = *pile;
        *pile = t;
    }
}

int depiler(struct Noeud **pile) {
    struct Noeud *t;
    int x = -1;
    if (*pile == NULL)
        printf("La pile est vide\n");
    else {
        t = *pile;
        *pile = (*pile)->suiv;
        x = t->donne;
        free(t);
    }
    return x;
}

int sommet(struct Noeud *pile) {
    if (pile == NULL) {
        printf("La pile est vide\n");
        return -1; // Valeur d'erreur pour indiquer une pile vide
    }

    return pile->donne;
}

int estVide(struct Noeud *pile) {
    if (pile == NULL) {
        return 1;
    }

    return 0;
}

int evaluerPostfix(char *expression) {
    struct Noeud *pile = NULL;
    int i, operand1, operand2, result;
    int longueur = strlen(expression);

    for(i = 0; i < longueur; i++) {
        if(expression[i] >= '0' && expression[i] <= '9') {
            int num = 0;
            while(expression[i] >= '0' && expression[i] <= '9') {
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            empiler(num, &pile);
        } else {
            operand2 = depiler(&pile);
            operand1 = depiler(&pile);
            switch(expression[i]) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                default:
                    printf("Opérateur invalide\n");
                    return -1;
            }
            empiler(result, &pile);
        }
    }

    return depiler(&pile);
}

void afficher(struct Noeud *pile) {
    struct Noeud *p;
    p = pile;
    while (p != NULL) {
        printf("%d ", p->donne);
        p = p->suiv;
    }
    printf("\n");
}

int main() {
    struct Noeud *p = NULL;

    empiler(10, &p);
    empiler(20, &p);
    empiler(30, &p);
    afficher(p);
    printf("\n%d est le sommet\n", sommet(p));
    printf("%d a été dépilé\n", depiler(&p));
    afficher(p);

    char *expression = "5 2 +";
    int result = evaluerPostfix(expression);
    printf("Résultat : %d\n", result);

    return 0;
}
