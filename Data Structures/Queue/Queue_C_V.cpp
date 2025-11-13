#include <iostream>
using namespace std;

#define SIZE 5

int items[SIZE];
int front = -1, rear = -1;

// Check if the queue is full
bool isFull() {
  if ((front == rear + 1) || (front == 0 && rear == SIZE - 1))
    return true;
  return false;
}

// Check if the queue is empty
bool isEmpty() {
  if (front == -1)
    return true;
  return false;
}

// Adding an element
void enQueue(int element) {
  if (isFull())
    cout << "\n Queue is full!!" << endl;
  else {
    if (front == -1)
      front = 0;
    rear = (rear + 1) % SIZE;
    items[rear] = element;
    cout << "\n Inserted -> " << element << endl;
  }
}

// Removing an element
int deQueue() {
  int element;
  if (isEmpty()) {
    cout << "\n Queue is empty!!" << endl;
    return -1;
  } else {
    element = items[front];
    if (front == rear) {
      front = -1;
      rear = -1;
    } else {
      front = (front + 1) % SIZE;
    }
    cout << "\n Deleted element -> " << element << endl;
    return element;
  }
}

// Display the queue
void display() {
  if (isEmpty())
    cout << "\n Empty Queue" << endl;
  else {
    cout << "\n Front -> " << front << endl;
    cout << " Items -> ";
    int i = front;
    while (true) {
      cout << items[i] << " ";
      if (i == rear)
        break;
      i = (i + 1) % SIZE;
    }
    cout << "\n Rear -> " << rear << endl;
  }
}

int main() {
  // Fails because front = -1
  deQueue();

  enQueue(1);
  enQueue(2);
  enQueue(3);
  enQueue(4);
  enQueue(5);

  // Fails to enqueue because front == 0 && rear == SIZE - 1
  enQueue(6);

  display();
  deQueue();

  display();

  enQueue(7);
  display();

  // Fails to enqueue because front == rear + 1
  enQueue(8);

  return 0;
}

