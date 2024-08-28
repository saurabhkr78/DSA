#include <iostream>
using namespace std;

#define MAX 5 // Define the maximum size of the stack

int stack[MAX]; // Array to hold the stack elements
int top = -1;   // Initialize the top of the stack to -1 (indicating an empty stack)

// Function to check if the stack is empty
bool isEmpty()
{
    return top == -1;
}

// Function to check if the stack is full
bool isFull()
{
    return top == MAX - 1;
}

// Function to push an element onto the stack
void push(int val)
{
    if (isFull())
    {
        cout << "Stack overflow" << endl;
    }
    else
    {
        top++;
        stack[top] = val;
    }
}

// Function to pop an element from the stack
int pop()
{
    if (isEmpty())
    {
        cout << "Stack underflow" << endl;
        return 0;
    }
    else
    {
        int popval = stack[top];
        stack[top] = 0;
        top--;
        return popval;
    }
}

// Function to get the number of elements in the stack
int count()
{
    return top + 1;
}

// Function to peek at an element in the stack
int peek(int pos)
{
    if (pos < 0 || pos > top)
    {
        cout << "Invalid position" << endl;
        return 0;
    }
    else
    {
        return stack[pos];
    }
}

// Function to change the value at a specific position in the stack
void changeValue(int pos, int val)
{
    if (pos < 0 || pos > top)
    {
        cout << "Invalid position" << endl;
    }
    else
    {
        stack[pos] = val;
        cout << "Value changed at position " << pos << endl;
    }
}

// Function to display the stack elements
void display()
{
    cout << "Stack elements:" << endl;
    for (int i = top; i >= 0; i--)
    {
        cout << stack[i] << endl;
    }
}
