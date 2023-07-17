#include <stdio.h>
#include <stdlib.h>

struct Node {
    char donne;
    struct Node* suiv;
};

struct Node* PileVide() {
    return NULL;
}

void empiler(struct Node** pile, char x) {
    struct Node* t;
    t = (struct Node*)malloc(sizeof(struct Node));

    if (t == NULL) {
        printf("La pile est pleine\n");
        return;
    }

    t->donne = x;
    t->suiv = *pile;
    *pile = t;
}

char depiler(struct Node** pile) {
    struct Node* t;
    char x = -1;

    if (*pile == NULL) {
        printf("La pile est vide\n");
        return x;
    }

    t = *pile;
    *pile = (*pile)->suiv;
    x = t->donne;
    free(t);

    return x;
}

int pileVide(struct Node* pile) {
    return (pile == NULL);
}

int VerifierParenthesesCrochets(char* expression) {
    struct Node* pile = PileVide();
    char c;

    for (int i = 0; expression[i] != '\0'; i++) {
        c = expression[i];

        if (c == '(' || c == '[') {
            empiler(&pile, c);
        } else if (c == ')') {
            if (pileVide(pile) || depiler(&pile) != '(')
                return 0;
        } else if (c == ']') {
            if (pileVide(pile) || depiler(&pile) != '[')
                return 0;
        }
    }

    if (pileVide(pile))
        return 1;
    else
        return 0;
}

int main() {
    char* expression = "((a+b)*[c-d]))";
    int result = VerifierParenthesesCrochets(expression);

    if (result)
        printf("Les parentheses et les crochets sont bien equilibres.\n");
    else
        printf("Les parentheses et les crochets ne sont pas bien equilibres.\n");

    return 0;
}
