Expressions régulière
Point 1 :
1)

structure Node
    donne : entier
    suiv : ^Node
Fin Declaration

//Declaration de la variable pile : pointeur vers Node initialise à NULL à implémenter dans le code 

Fonction empiler(e : entier, pile : ^Node)
    newNoeud :^Node
    Allouer(newNoeud)
    //Allouer newNoeud avec la taille d'un Node
    
    Si newNoeud== NUL alors
        Afficher "La pile est pleine"
    Sinon
        newNoeud.donne <- e
        newNoeud.suiv <- pile
        pile <- newNoeud
    Fin Si
Fin Fonction

Fonction depiler(pile : ^Node) : entier
    Si pile ==NUL alors
        Afficher("La pile est vide")
        retourner -1 // Valeur d'erreur pour indiquer une pile vide
    Sinon
        sommet :^Node
        sommet <- pile
        pile <- pile.suiv
        vSommet : entier
        vSommet <- sommet.donne
        
        //Liberer sommet à faire en le programmant
        retourner vSommet
    Fin Si
Fin Fonction

Fonction sommet(pile : ^Node) : entier
    Si pile== NUL alors
        Afficher("La pile est vide")
        retourner -1 // Valeur d'erreur pour indiquer une pile vide
    Sinon
        retourner pile.donne
    Fin Si
Fin Fonction

Fonction estVide(pile : ^Node) : entier
    Si pile==NULL alors
        retourner 1
    Sinon
        retourner 0
    Fin Si
Fin Fonction

Debut
    pile : ^Node  NULL
    
    // Test des fonctions
    empiler(10, pile)
    empiler(20, pile)
    empiler(30, pile)
    Afficher ("Sommet de la pile: " + sommet(pile))
    Afficher ("Depilage: " + depiler(pile))
    Afficher ("Depilage: " + depiler(pile))
    Afficher ("Depilage: " + depiler(pile))
    Afficher ( "Depilage: " + depiler(pile) )// Tentative de depilage lorsque la pile est vide
    
    Afficher( "Est vide? " + estVide(pile))
Fin
