Structure Node
    donne : entier
    suiv : ^Node
Fin Structure

Fonction empiler(pile : ^Node, x : entier)
    t : ^Node
    Allouer(t)
    
    Si t == NULL alors
        Afficher "La pile est pleine"
    Sinon
        t.donne <- x
        t.suiv <- pile
        pile <- t
    Fin Si
Fin Fonction

Fonction depiler(pile : ^Node) : entier
    t : ^Node
    x : entier
    
    Si pile == NULL alors
        Afficher "La pile est vide"
        retourner -1 // Valeur d'erreur pour indiquer une pile vide
    Sinon
        t <- pile
        pile <- pile.suiv
        x <- t.donne
        
        retourner x
    Fin Si
Fin Fonction

Fonction evaluatePostfix(expression : chaine de caractères) : entier
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

Début
    expression : chaine de caractères
    résultat : entier
    
    expression <- "2 4 5 + *"
    résultat <- evaluatePostfix(expression)
    
    Afficher "Résultat : " + résultat
Fin
