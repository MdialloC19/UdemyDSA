
    
 EXERCICE 2:
 
1)
Type
    Structure date
        jour, moi, annee : entier
    finStructure

    Structure Etudiant
        nom, prenom : chaine
        numero : entier
    finStructure

    Structure listeEtudiant
        e : Etudiant,
        suiv : ↑listeEtudiant
    finStructure

2) 
affiche(liste : ↑listeEtudiant){
    liste2 : ↑listeEtudiant
    liste2 <-- liste

    // gérer le cas où c'est vide une seule fois
    si(liste2 = nil) alors
        retourner
    sinon
        afficherEtudiant(liste2-->e)
        liste2<-- liste2-->suiv
    finsi

    
    tant que(liste2 != liste)
        afficherEtudiant(liste2-->e)
        liste2<-- liste2-->suiv
    
    finTanque



}
afficherEtudiant(e : Etudiant){
    afficher("nom : "+ e.nom)
    afficher("prenom : "+e.prenom)
    afficher("numero : "+e.numero)
}


3)Ecrire une fonction occur(Liste*, Etudiant) qui renvoie le nombre de fois que
l’étudiant est présent dans la liste.

entier : occur(liste : ↑listeEtudiant, e : etudiant){
    nbre : entier
    liste2 : ↑listeEtudiant

    liste2 <-- liste
    nbre <-- 0

    
    si(liste2 = nil) alors
        retourner nbre
    sinon
        si(liste2-->e = e) alors
            nbre <-- nbre + 1
        finsi
        liste2<-- liste2-->suiv
    finsi

    
    tant que(liste2 != liste)
        si(liste2-->e = e) alors
            nbre <-- nbre + 1
        finsi
        liste2<-- liste2-->suiv
    
    finTanque
    
    retourner nbre

}   	
