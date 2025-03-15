#include <iostream>

// Structure d'un nœud
struct Node {
    int data;
    Node* next;
    
    Node(int val) : data(val), next(nullptr) {}
};

// Classe LinkedList
class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    // 1. Insertion au début
    void insertAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    // 2. Insertion à la fin
    void insertAtTail(int val) {
        Node* newNode = new Node(val);
        
        if (!head) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // 3. Suppression d'une valeur
    void deleteNode(int val) {
        if (!head) return;

        // Cas spécial : suppression de la tête
        if (head->data == val) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
            return;
        }

        Node* temp = head;
        while (temp->next && temp->next->data != val) {
            temp = temp->next;
        }

        if (temp->next) {
            Node* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        }
    }

    // 4. Recherche d'une valeur
    bool search(int val) {
        Node* temp = head;
        while (temp) {
            if (temp->data == val) return true;
            temp = temp->next;
        }
        return false;
    }

    // 5. Longueur de la liste
    int getLength() {
        int count = 0;
        Node* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    // 6. Inverser la liste
    void reverse() {
        Node *prev = nullptr, *current = head, *next = nullptr;
        while (current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    // 7. Affichage de la liste
    void display() {
        Node* temp = head;
        while (temp) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "NULL\n";
    }

    // 8. Vider la mémoire
    ~LinkedList() {
        Node* temp;
        while (head) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Exemple d'utilisation
int main() {
    LinkedList list;
    
    list.insertAtHead(3);
    list.insertAtHead(2);
    list.insertAtTail(4);
    list.insertAtTail(5);
    
    std::cout << "Liste initiale: ";
    list.display(); // 2 -> 3 -> 4 -> 5 -> NULL
    
    list.deleteNode(3);
    std::cout << "Apres suppression de 3: ";
    list.display(); // 2 -> 4 -> 5 -> NULL
    
    list.reverse();
    std::cout << "Apres inversion: ";
    list.display(); // 5 -> 4 -> 2 -> NULL
    
    std::cout << "Longueur: " << list.getLength() << "\n"; // 3
    std::cout << "Recherche de 4: " << std::boolalpha << list.search(4) << "\n"; // true
    
    return 0;
}