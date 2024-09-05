#include <iostream>
using namespace std;

// Class representing a node in the linked list
class node {
public:
    int data;      // Data stored in the node
    node* next;    // Pointer to the next node

    // Constructor to initialize a new node with a given value
    node(int val) {
        data = val;
        next = nullptr;
    }
};

// Class representing a linked list
class ll {
public:
    node* head;    // Pointer to the head of the list

    // Constructor to initialize an empty list
    ll() {
        head = nullptr;
    }

    // Method to insert a node with a given value at the head of the list
    void insertAtHead(int val) {
        node* newnode = new node(val); // Create a new node
        newnode->next = head;          // Point new node to the current head
        head = newnode;                // Update head to the new node
    }

    // Method to insert a node with a given value at the end of the list
    void insertAtEnd(int val) {
        node* newnode = new node(val); // Create a new node
        if (head == nullptr) {         // If list is empty, insert at head
            head = newnode;
            return;
        }
        node* temp = head;
        while (temp->next != nullptr) { // Traverse to the last node
            temp = temp->next;
        }
        temp->next = newnode; // Insert the new node at the end
    }

    // Method to insert a node with a given value at a specific index
    void AtIdx(int val, int idx) {
        node* newnode = new node(val); // Create a new node
        node* temp = head;

        if (idx == 0) {  // If index is 0, insert at head
            insertAtHead(val);
            return;
        }

        if (temp == nullptr) {  // If list is empty and index is not 0, out of bounds
            cout << "Index Outta Bound";
            return;
        }

        for (int i = 0; i < idx - 1; i++) { // Traverse to the node just before the index
            if (temp == nullptr) { // Check if index is out of bounds
                cout << "Index Outta Bound";
                return;
            }
            temp = temp->next;
        }

        newnode->next = temp->next; // Adjust pointers to insert the new node
        temp->next = newnode;
    }

    // Method to display the contents of the list
    void display() {
        node* temp = head;
        while (temp != nullptr) {  // Traverse and print each node
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl; // End of list marker
    }
};

int main() {
    ll l;

    l.insertAtHead(3);
    l.insertAtEnd(5);
    l.insertAtEnd(7);
    l.insertAtHead(1);
    l.AtIdx(4, 2);

    l.display();

    return 0;
}
