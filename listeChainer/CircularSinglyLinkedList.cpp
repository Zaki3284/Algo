#include <iostream>
using namespace std;

struct ListNode {
    int value;
    ListNode* next;

    ListNode(int value) {
        this->value = value;
        this->next = nullptr;
    }
};

// Ajouter un nœud à la fin de la liste
void AjouterAuFin(ListNode*& head, int value) {
    ListNode* newNode = new ListNode(value);
    if (head == nullptr) {
        head = newNode;
        head->next = head; // Pointer vers lui-même pour former un cycle
    } else {
        ListNode* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}

// Ajouter un nœud au début de la liste
void AjouterAuDebut(ListNode*& head, int value) {
    ListNode* newNode = new ListNode(value);
    if (head == nullptr) {
        head = newNode;
        head->next = head;
    } else {
        ListNode* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }
}

// Supprimer le premier nœud de la liste
void SupprimerAuDebut(ListNode*& head) {
    if (head == nullptr) {
        return;
    }
    if (head->next == head) {
        delete head;
        head = nullptr;
    } else {
        ListNode* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        ListNode* toDelete = head;
        head = head->next;
        temp->next = head;
        delete toDelete;
    }
}

// Supprimer le dernier nœud de la liste
void SupprimerAuFin(ListNode*& head) {
    if (head == nullptr) {
        return;
    }
    if (head->next == head) {
        delete head;
        head = nullptr;
    } else {
        ListNode* temp = head;
        while (temp->next->next != head) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = head;
    }
}

// Rechercher une valeur dans la liste
bool RechercherBool(ListNode* head, int value) {
    if (head == nullptr) {
        return false;
    }
    ListNode* temp = head;
    do {
        if (temp->value == value) {
            return true;
        }
        temp = temp->next;
    } while (temp != head);
    return false;
}

// Afficher les valeurs des nœuds de la liste
void AfficherListe(ListNode* head) {
    if (head == nullptr) {
        cout << "La liste est vide." << endl;
        return;
    }
    ListNode* temp = head;
    do {
        cout << temp->value << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << "(retour au début)" << endl;
}

int main() {
    ListNode* head = nullptr;

    AjouterAuDebut(head, 0);
    AjouterAuFin(head, 10);
    AjouterAuFin(head, 20);
    AjouterAuFin(head, 30);
    AjouterAuFin(head, 40);
    SupprimerAuDebut(head);
    SupprimerAuFin(head);

    int valueToSearch = 20;
    bool found = RechercherBool(head, valueToSearch);

    if (found) {
        cout << "La valeur " << valueToSearch << " a été trouvée dans la liste." << endl;
    } else {
        cout << "La valeur " << valueToSearch << " n'a pas été trouvée dans la liste." << endl;
    }

    AfficherListe(head);

    return 0;
}
