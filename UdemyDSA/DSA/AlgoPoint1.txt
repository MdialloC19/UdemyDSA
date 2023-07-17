Expressions régulière
Point 1 :
1) Ecrire les fonctions usuelles d’ajout (empiler(e, P)) et de retrait (depiler(P)) ainsi que
la fonction sommet(P) qui rend le sommet de la pile et la fonction estVide(P) qui teste
si la pile est vide.

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
    Si pile==NUL alors
        retourner 1
    Sinon
        retourner 0
    Fin Si
Fin Fonction

// En utilisant une pile, écrire une fonction qui à partir d’une
// expression arithmétique en notation postfixée, évalue cette expression et retourne le
// résultat.

Fonction evaluerPostfix(expression : chaine de caractères) : entier
    pile : ^Node
    operand1, operand2, result : entier
    i, num : entier
    long : entier
    long <- Longueur(expression)
    pile <- NUL
    Pour i de 0 à long-1 faire
        Si expression[i] est un chiffre alors
            num <- 0
            Tant que expression[i] est un chiffre faire
                num <- num * 10 + (expression[i] - '0')
                i <- i + 1
            Fin Tant que
            empiler(pile, num)
        Sinon
            operand2 <- depiler(pile)
            operand1 <- depiler(pile)
            Selon expression[i] faire
                Cas '+'
                    result <- operand1 + operand2
                Cas '-'
                    result <- operand1 - operand2
                Cas '*'
                    result <- operand1 * operand2
                Cas '/'
                    result <- operand1 / operand2
                Sinon
                    Afficher "Opérateur invalide"
                    retourner -1
            Fin Selon
            empiler(pile, result)
        Fin Si
    Fin Pour
    retourner depiler(pile)
Fin Fonction

Debut
    pile : ^Node 
    expression : chaine de caractères
    résultat : entier
    expression <- "2 4 5 + *" 
    
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
    résultat <- evaluatePostfix(expression)
    Afficher( "Résultat : " + résultat)
Fin
