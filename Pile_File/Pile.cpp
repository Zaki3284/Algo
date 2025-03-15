#include <iostream>
using namespace std;

// Définir la structure de chaque élément (Noeud) de la pile
struct Noeud {
    int val;         // Valeur stockée
    Noeud* prec;     // Pointeur vers l'élément précédent (en-dessous)
};

// Type alias pour simplifier
typedef Noeud* Pile;

// Fonction pour créer une pile vide
Pile pileVide() {
    return nullptr;  // Une pile vide pointe sur rien
}

// Vérifier si la pile est vide
bool estPileVide(Pile p) {
    return p == nullptr;
}

// Empiler un élément (ajouter au sommet de la pile)
Pile empiler(Pile p, int valeur) {
    Noeud* nouveau = new Noeud; // Allouer un nouveau noeud
    nouveau->val = valeur;     // Stocker la valeur
    nouveau->prec = p;         // Lier au précédent (ancien sommet)
    return nouveau;           // Nouveau sommet
}

// Dépiler un élément (supprimer le sommet de la pile)
Pile depiler(Pile p) {
    if (estPileVide(p)) {
        cout << "Pile vide, impossible de dépiler." << endl;
        return p; // Rien à dépiler
    }
    Noeud* temp = p;     // Sauvegarder le sommet actuel
    p = p->prec;        // Mettre à jour le sommet vers le précédent
    delete temp;       // Libérer la mémoire de l'ancien sommet
    return p;
}

// Lire la valeur au sommet (sans la retirer)
int sommet(Pile p) {
    if (estPileVide(p)) {
        cout << "Pile vide, pas de sommet." << endl;
        return -1; // Valeur spéciale pour indiquer qu'il n'y a rien
    }
    return p->val;
}

// Afficher tous les éléments de la pile
void afficherPile(Pile p) {
    if (estPileVide(p)) {
        cout << "Pile vide." << endl;
        return;
    }
    cout << "Contenu de la pile (du sommet vers la base):" << endl;
    while (p != nullptr) {
        cout << p->val << " ";
        p = p->prec; // Avancer vers l'élément suivant
    }
    cout << endl;
}

// Vider complètement la pile (libérer toute la mémoire)
Pile viderPile(Pile p) {
    while (!estPileVide(p)) {
        p = depiler(p); // Dépiler jusqu'à ce qu'elle soit vide
    }
    return p;
}

// Programme principal pour tester les fonctions
int main() {
    Pile maPile = pileVide(); // Créer une pile vide

    // Empiler des éléments
    maPile = empiler(maPile, 10);
    maPile = empiler(maPile, 20);
    maPile = empiler(maPile, 30);
    maPile = empiler(maPile, 40);

    // Affichage de la pile
    afficherPile(maPile);

    // Lire le sommet
    cout << "Sommet de la pile : " << sommet(maPile) << endl;

    // Dépiler un élément
    maPile = depiler(maPile);
    cout << "Après dépilage :" << endl;
    afficherPile(maPile);

    // Vider complètement la pile
    maPile = viderPile(maPile);
    cout << "Après vidage :" << endl;
    afficherPile(maPile);

    return 0;
}
