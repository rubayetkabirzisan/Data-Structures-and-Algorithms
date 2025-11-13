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

class Queue
{
private:
    Node* front;
    Node* rear;

public:
    Queue()
    {
        front = nullptr;
        rear = nullptr;
    }

    ~Queue()
    {
        // Destructor to delete all nodes
        Node* current = front;
        while (current != nullptr)
        {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    bool isEmpty()
    {
        return front == nullptr;
    }

    void enqueue(int value)
    {
        Node* newNode = new Node(value);
        if (isEmpty())
        {
            front = newNode;
            rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }

        Node* nodeToDelete = front;
        front = front->next;
        if (front == nullptr)
        {
            rear = nullptr;
        }
        delete nodeToDelete;
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1; // Or any suitable default value
        }

        return front->data;
    }

    void printQueue()
    {
        Node* current = front;
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
    Queue myQueue;

    myQueue.enqueue(5);
    myQueue.enqueue(3);
    myQueue.enqueue(7);

    myQueue.printQueue(); // Output: 5 3 7

    myQueue.dequeue();
    myQueue.printQueue(); // Output: 3 7

    cout << "Front element: " << myQueue.peek() << endl; // Output: 3

    return 0;
}

