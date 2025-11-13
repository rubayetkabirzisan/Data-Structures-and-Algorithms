#include <iostream>
#define SIZE 5

using namespace std;

void enQueue(int);
void deQueue();
void display();

int items[SIZE], front = -1, rear = -1;

int main()
{
    // deQueue is not possible on empty queue
    deQueue();

    // enQueue 5 elements
    enQueue(1);
    enQueue(2);
    enQueue(3);
    enQueue(4);
    enQueue(5);

    // 6th element can't be added because the queue is full
    enQueue(6);

    display();

    // deQueue removes the element entered first i.e., 1
    deQueue();

    // Now we have just 4 elements
    display();

    return 0;
}

void enQueue(int value)
{
    if (rear == SIZE - 1)
        cout << "\nQueue is Full!!" << endl;
    else
    {
        if (front == -1)
            front = 0;
        rear++;
        items[rear] = value;
        cout << "\nInserted -> " << value << endl;
    }
}

void deQueue()
{
    if (front == -1)
        cout << "\nQueue is Empty!!" << endl;
    else
    {
        cout << "\nDeleted : " << items[front] << endl;
        front++;
        if (front > rear)
            front = rear = -1;
    }
}

// Function to print the queue
void display()
{
    if (rear == -1)
        cout << "\nQueue is Empty!!!" << endl;
    else
    {
        cout << "\nQueue elements are:" << endl;
        for (int i = front; i <= rear; i++)
            cout << items[i] << " ";
    }
    cout << endl;
}
