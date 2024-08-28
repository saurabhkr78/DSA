#include <iostream>
using namespace std;

// Node class to represent each element in the stack
class Node
{
public:
    int data;   // Data part of the node
    Node *next; // Pointer to the next node

    // Constructor to initialize the node with a value and set the next pointer to nullptr
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

// Stack class to represent the stack using a linked list
class Stack
{
private:
    Node *top; // Pointer to the top node in the stack

public:
    // Constructor to initialize the top pointer to nullptr, indicating an empty stack
    Stack()
    {
        top = nullptr;
    }

    // Function to check if the stack is empty
    bool isEmpty()
    {
        return top == nullptr;
    }

    // Function to push an element onto the stack
    void push(int val)
    {
        // Create a new node with the given value
        Node *newNode = new Node(val);
        // Set the next pointer of the new node to the current top node
        newNode->next = top;
        // Update the top pointer to the new node
        top = newNode;
        cout << "Pushed " << val << " onto the stack." << endl;
    }

    // Function to pop an element from the stack
    int pop()
    {
        // Check if the stack is empty
        if (isEmpty())
        {
            cout << "Stack underflow" << endl;
            return -1; // Return -1 to indicate underflow
        }
        else
        {
            // Store the value of the top node
            int popValue = top->data;
            // Create a temporary pointer to the current top node
            Node *temp = top;
            // Update the top pointer to the next node
            top = top->next;
            // Delete the old top node
            delete temp;
            // Return the popped value
            return popValue;
        }
    }

    // Function to count the number of elements in the stack
    int count()
    {
        int count = 0;    // Initialize the count to 0
        Node *temp = top; // Start from the top node
        // Traverse the stack and count the nodes
        while (temp != nullptr)
        {
            count++;
            temp = temp->next;
        }
        // Return the total count
        return count;
    }

    // Function to peek at an element in the stack based on its position
    int peek(int pos)
    {
        // Check if the stack is empty or if the position is invalid
        if (isEmpty() || pos <= 0)
        {
            cout << "Invalid position or stack underflow" << endl;
            return -1; // Return -1 to indicate error
        }
        else
        {
            Node *temp = top; // Start from the top node
            // Traverse to the node at the specified position
            for (int i = 1; i < pos; i++)
            {
                if (temp->next == nullptr)
                {
                    cout << "Invalid position" << endl;
                    return -1; // Return -1 if the position is out of bounds
                }
                temp = temp->next;
            }
            // Return the data at the specified position
            return temp->data;
        }
    }

    // Function to change the value at a specific position in the stack
    void changeValue(int pos, int val)
    {
        // Check if the stack is empty or if the position is invalid
        if (isEmpty() || pos <= 0)
        {
            cout << "Invalid position or stack underflow" << endl;
        }
        else
        {
            Node *temp = top; // Start from the top node
            // Traverse to the node at the specified position
            for (int i = 1; i < pos; i++)
            {
                if (temp->next == nullptr)
                {
                    cout << "Invalid position" << endl;
                    return; // Exit if the position is out of bounds
                }
                temp = temp->next;
            }
            // Change the data at the specified position
            temp->data = val;
            cout << "Value at position " << pos << " changed to " << val << endl;
        }
    }

    // Function to display the stack elements
    void display()
    {
        // Check if the stack is empty
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            Node *temp = top; // Start from the top node
            cout << "Stack elements:" << endl;
            // Traverse the stack and print each element
            while (temp != nullptr)
            {
                cout << temp->data << endl;
                temp = temp->next;
            }
        }
    }
};