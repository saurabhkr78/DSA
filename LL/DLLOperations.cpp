#include <iostream>
using namespace std;

// Class representing a node in a doubly linked list
class Node
{
public:
    int data;   // Data stored in the node
    Node *next; // Pointer to the next node
    Node *prev; // Pointer to the previous node

    // Constructor to initialize a new node with a given value
    Node(int val)
    {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

// Class representing a doubly linked list
class DoublyLinkedList
{
public:
    Node *head; // Pointer to the head of the list
    Node *tail; // Pointer to the tail of the list

    // Constructor to initialize an empty list
    DoublyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    // Method to insert a node with a given value at the head of the list
    void insertAtHead(int val)
    {
        Node *newNode = new Node(val); // Create a new node

        if (head == nullptr)
        { // If the list is empty
            head = newNode;
            tail = newNode;
            return;
        }

        newNode->next = head; // Point new node to the current head
        head->prev = newNode; // Point current head back to new node
        head = newNode;       // Update head to the new node
    }

    // Method to insert a node with a given value at the end of the list
    void insertAtEnd(int val)
    {
        Node *newNode = new Node(val); // Create a new node

        if (tail == nullptr)
        { // If the list is empty
            head = newNode;
            tail = newNode;
            return;
        }

        newNode->prev = tail; // Point new node back to the current tail
        tail->next = newNode; // Point current tail to new node
        tail = newNode;       // Update tail to the new node
    }

    // Method to insert a node with a given value at a specific index
    void insertAtIndex(int val, int idx)
    {
        if (idx == 0)
        { // If index is 0, insert at head
            insertAtHead(val);
            return;
        }

        Node *newNode = new Node(val); // Create a new node
        Node *temp = head;

        for (int i = 0; i < idx - 1; i++)
        { // Traverse to the node before the index
            if (temp == nullptr)
            { // Check if index is out of bounds
                cout << "Index Out of Bounds" << endl;
                delete newNode;
                return;
            }
            temp = temp->next;
        }

        if (temp == nullptr || temp->next == nullptr)
        { // If index is beyond the end
            cout << "Index Out of Bounds" << endl;
            delete newNode;
            return;
        }

        newNode->next = temp->next; // Point new node to the next node
        newNode->prev = temp;       // Point new node back to the current node
        temp->next->prev = newNode; // Point the next node back to the new node
        temp->next = newNode;       // Point current node to the new node
    }

    // Method to display the linked list from head to tail
    void displayForward()
    {
        Node *temp = head;
        while (temp != nullptr)
        { // Traverse and print each node
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl; // End of list marker
    }

    // Method to display the linked list from tail to head
    void displayBackward()
    {
        Node *temp = tail;
        while (temp != nullptr)
        { // Traverse and print each node
            cout << temp->data << " <-> ";
            temp = temp->prev;
        }
        cout << "NULL" << endl; // End of list marker
    }
};

int main()
{
    DoublyLinkedList dll;

    dll.insertAtHead(3);
    dll.insertAtEnd(5);
    dll.insertAtEnd(7);
    dll.insertAtHead(1);
    dll.insertAtIndex(4, 2);
    cout << "Forward: ";
    dll.displayForward();

    cout << "Backward: ";
    dll.displayBackward();

    return 0;
}
