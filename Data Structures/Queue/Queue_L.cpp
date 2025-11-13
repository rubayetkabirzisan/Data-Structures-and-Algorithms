#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* front = NULL;
Node* rear = NULL;

void enqueue(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    if (front == NULL && rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    cout << "Node is Inserted" << endl << endl;
}

int dequeue() {
    if (front == NULL) {
        cout << "Underflow" << endl;
        return -1;
    } else {
        Node* temp = front;
        int temp_data = front->data;
        front = front->next;
        delete temp;
        return temp_data;
    }
}

void display() {
    Node* temp;
    if (front == NULL && rear == NULL) {
        cout << "Queue is Empty" << endl;
    } else {
        cout << "The queue is: " << endl;
        temp = front;
        while (temp != NULL) {
            cout << temp->data;
            if (temp->next != NULL) {
                cout << "--->";
            }
            temp = temp->next;
        }
        cout << endl << endl;
    }
}

int main() {
    int choice, value;
    cout << "Implementation of Queue using Linked List" << endl;
    while (choice != 4) {
        cout << "1.Enqueue" << endl;
        cout << "2.Dequeue" << endl;
        cout << "3.Display" << endl;
        cout << "4.Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to insert: ";
                cin >> value;
                enqueue(value);
                break;
            case 2:
                cout << "Popped element is: " << dequeue() << endl;
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
                break;
            default:
                cout << "Wrong Choice" << endl;
        }
    }

    return 0;
}
