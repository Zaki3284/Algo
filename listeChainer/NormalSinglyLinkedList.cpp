#include <iostream>
using namespace std;

struct ListNode{

    int value;
    ListNode* next;

    ListNode(int value){
        this->value =value;
        this->next = nullptr;
    }


};

// ajouter un noeud a la fin de la liste

void AjouterAuFin(ListNode*& head, int value){
    
    ListNode* newNode = new ListNode(value);
   

    if (head == nullptr)
    {
       head = newNode;
       return ;
      

    }

    ListNode* temp = head;

    while(temp->next != nullptr){

        temp = temp->next;
    }

    temp->next = newNode;
}
;

// ajouter une noeud au début de la liste
void AjouterAuDebut(ListNode*& head, int value) {
    ListNode* newNode = new ListNode(value); 
    newNode->next = head;                    
    head = newNode;                         }


   ;
   // Supprimer la première node de la liste
void SupprimerAuDebut(ListNode*& head) {
    if (head == nullptr) {
        return; // Si la liste est vide, ne rien faire.
    }
    ListNode* temp = head;  // Stocker le pointeur vers le premier node.
    head = head->next;      // Mettre à jour le head pour pointer sur le deuxième node.
    delete temp;            // Libérer la mémoire de l'ancien head.
}
; 

// Supprimer la dernière node de la liste
void SupprimerAuFin(ListNode*& head) {
    if (head == nullptr) {
        return; // Si la liste est vide, ne rien faire.
    }
    if (head->next == nullptr) {
        // Si la liste a une seule node, la supprimer et mettre head à nullptr.
        delete head;
        head = nullptr;
        return;
    }
    ListNode* temp = head;
    // Parcourir la liste pour trouver l'avant-dernière node.
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    // Supprimer la dernière node et mettre le pointeur next de l'avant-dernière à nullptr.
    delete temp->next;
    temp->next = nullptr;
}
;

// Rechercher une node par sa valeur dans la liste
bool RechercherBool(ListNode* head, int value) {
    ListNode* current = head;             // Commencer au début de la liste
    while (current != nullptr) {          // Parcourir la liste jusqu'à la fin
        if (current->value == value) {    // Si la valeur correspond
            return true;                  // La valeur est trouvée, retourner true
        }
        current = current->next;          // Passer à la node suivante
    }
    return false;                         // Si non trouvée, retourner false
}


// Afficher les valeurs des nodes de la liste
void AfficherListe(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->value << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;                       
}

// fonction principale
int main(){
   ListNode* head = nullptr; 
    

    AjouterAuDebut(head,0);
    AjouterAuFin(head, 10);
    AjouterAuFin(head, 20);
    AjouterAuFin(head, 30);
    AjouterAuFin(head, 40);
    SupprimerAuDebut(head);
    SupprimerAuFin(head);
    int valueToSearch = 90;
    bool found = RechercherBool(head, valueToSearch);
    
    if (found) {
        cout << "Value " << valueToSearch << " found in the list." << endl;
    } else {
        cout << "Value " << valueToSearch << " not found in the list." << endl;
    }

    AfficherListe(head);
   

    return 0;
}