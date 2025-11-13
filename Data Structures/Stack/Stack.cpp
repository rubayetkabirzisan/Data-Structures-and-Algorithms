#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

class Stack
{
private:
    Node* top;

public:
    Stack()
    {
        top = nullptr;
    }

    ~Stack()
    {
        // Destructor to delete all nodes
        Node* current = top;
        while (current != nullptr)
        {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    bool isEmpty()
    {
        return top == nullptr;
    }

    void push(int value)
    {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return;
        }

        Node* nodeToDelete = top;
        top = top->next;
        delete nodeToDelete;
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return -1; // Or any suitable default value
        }

        return top->data;
    }

    void printStack()
    {
        Node* current = top;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main()
{
    Stack myStack;

    myStack.push(5);
    myStack.push(3);
    myStack.push(7);

    myStack.printStack(); // Output: 7 3 5

    myStack.pop();
    myStack.printStack(); // Output: 3 5

    cout << "Top element: " << myStack.peek() << endl; // Output: 3

    return 0;
}
