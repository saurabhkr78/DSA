#include <iostream>
using namespace std;

// Node of a doubly linked list
struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

// Deque class
class Deque {
private:
    Node* front;
    Node* back;
    int size;

public:
    Deque() : front(nullptr), back(nullptr), size(0) {}

    // Insert element at the front
    void pushFront(int val) {
        Node* newNode = new Node(val);
        if (front == nullptr) {
            front = back = newNode;
        } else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
        size++;
    }

    // Insert element at the back
    void pushBack(int val) {
        Node* newNode = new Node(val);
        if (back == nullptr) {
            front = back = newNode;
        } else {
            newNode->prev = back;
            back->next = newNode;
            back = newNode;
        }
        size++;
    }

    // Delete element from the front
    void popFront() {
        if (front == nullptr) {
            cout << "Deque is empty" << endl;
            return;
        }
        Node* temp = front;
        if (front == back) {
            front = back = nullptr;
        } else {
            front = front->next;
            front->prev = nullptr;
        }
        delete temp;
        size--;
    }

    // Delete element from the back
    void popBack() {
        if (back == nullptr) {
            cout << "Deque is empty" << endl;
            return;
        }
        Node* temp = back;
        if (front == back) {
            front = back = nullptr;
        } else {
            back = back->prev;
            back->next = nullptr;
        }
        delete temp;
        size--;
    }

    // Get the front element
    int getFront() {
        if (front == nullptr) {
            cout << "Deque is empty" << endl;
            return -1;
        }
        return front->data;
    }

    // Get the back element
    int getBack() {
        if (back == nullptr) {
            cout << "Deque is empty" << endl;
            return -1;
        }
        return back->data;
    }

    // Check if the deque is empty
    bool isEmpty() {
        return size == 0;
    }

    // Get the size of the deque
    int getSize() {
        return size;
    }

    // Destructor to clean up memory
    ~Deque() {
        while (front != nullptr) {
            popFront();
        }
    }
};

int main() {
    Deque dq;

    dq.pushFront(10);
    dq.pushBack(20);
    dq.pushFront(5);
    dq.pushBack(25);

    cout << "Front element: " << dq.getFront() << endl; // Output: 5
    cout << "Back element: " << dq.getBack() << endl;   // Output: 25

    dq.popFront();
    cout << "Front element after popFront: " << dq.getFront() << endl; // Output: 10

    dq.popBack();
    cout << "Back element after popBack: " << dq.getBack() << endl;   // Output: 20

    cout << "Size of deque: " << dq.getSize() << endl; // Output: 2

    return 0;
}
