#include <iostream>

// Node structure for the linked list
struct Node {
    int value;
    Node* next;

    Node(int val) : value(val), next(nullptr) {}
};

// Linked list class
class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    // Function to add a new element to the linked list
    void addElement(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    // Function to remove an element from the linked list
    void removeElement(int val) {
        Node* current = head;
        Node* previous = nullptr;

        // Search for the element to be removed
        while (current != nullptr && current->value != val) {
            previous = current;
            current = current->next;
        }

        // If the element is found, adjust the links
        if (current != nullptr) {
            if (previous != nullptr) {
                previous->next = current->next;
            } else {
                head = current->next;
            }
            delete current;
        }
    }

    // Function to display the linked list
    void displayList() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->value << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

// Main function for testing
int main() {
    // Create a linked list with 1000 elements
    LinkedList myList;

    for (int i = 1; i <= 1; ++i) {
        myList.addElement(i);
    }

    // Display the linked list
    std::cout << "Linked List with 1 Elements: ";
    myList.displayList();
    while (1) { };

    return 0;
}
