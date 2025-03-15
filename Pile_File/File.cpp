#include <iostream>
using namespace std;

// Define the structure for each element (Node) of the queue
struct Node {
    int val;         // Stored value
    Node* next;      // Pointer to the next element in the queue
};

// Type alias for simplifying
typedef Node* File;  // 'File' is the French word for Queue

// Function to create an empty queue (file)
File createEmptyFile() {
    return nullptr;  // An empty file points to nothing
}

// Check if the file is empty
bool isFileEmpty(File f) {
    return f == nullptr;
}

// Add an element (enqueue) at the end of the file
File enqueue(File f, int value) {
    Node* newNode = new Node; // Allocate memory for a new node
    newNode->val = value;     // Store the value
    newNode->next = nullptr;  // It will be the last element, so next is null
    
    if (isFileEmpty(f)) {
        return newNode; // If the file is empty, the new node is both the front and rear
    }

    // Traverse to the end of the file and add the new element
    Node* temp = f;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;  // Link the last element to the new node
    return f;               // Return the same file
}

// Remove the first element (dequeue) from the file
File dequeue(File f) {
    if (isFileEmpty(f)) {
        cout << "File is empty, cannot dequeue." << endl;
        return f; // Nothing to dequeue
    }
    Node* temp = f;      // Save the current front
    f = f->next;         // Update front to the next element
    delete temp;         // Free the memory of the old front
    return f;
}

// Get the first element (without removing it)
int front(File f) {
    if (isFileEmpty(f)) {
        cout << "File is empty, no front element." << endl;
        return -1; // Special value indicating nothing
    }
    return f->val;
}

// Display all elements in the file
void displayFile(File f) {
    if (isFileEmpty(f)) {
        cout << "File is empty." << endl;
        return;
    }
    cout << "File contents (from front to rear):" << endl;
    while (f != nullptr) {
        cout << f->val << " ";
        f = f->next; // Move to the next element
    }
    cout << endl;
}

// Clear the entire file (free all memory)
File clearFile(File f) {
    while (!isFileEmpty(f)) {
        f = dequeue(f); // Remove elements until the file is empty
    }
    return f;
}

// Main program to test the functions
int main() {
    File maFile = createEmptyFile(); // Create an empty file

    // Enqueue elements
    maFile = enqueue(maFile, 10);
    maFile = enqueue(maFile, 20);
    maFile = enqueue(maFile, 30);
    maFile = enqueue(maFile, 40);

    // Display the file
    displayFile(maFile);

    // Get the front element
    cout << "Front of the file: " << front(maFile) << endl;

    // Dequeue an element
    maFile = dequeue(maFile);
    cout << "After dequeue:" << endl;
    displayFile(maFile);

    // Clear the file completely
    maFile = clearFile(maFile);
    cout << "After clearing the file:" << endl;
    displayFile(maFile);

    return 0;
}
