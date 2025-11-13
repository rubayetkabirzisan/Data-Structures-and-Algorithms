#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void insert(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void deleteOddValues() {
        Node* current = head;
        Node* previous = nullptr;

        while (current != nullptr) {
            if (current->data % 2 != 0) {
                // Odd value, delete the node
                Node* temp = current;
                if (previous == nullptr) {
                    // If the first node is odd, update head
                    head = current->next;
                    current = head;
                } else {
                    previous->next = current->next;
                    current = previous->next;
                }
                delete temp;
            } else {
                previous = current;
                current = current->next;
            }
        }
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    Node* getHead() const {
        return head;
    }
};

int main() {
    LinkedList list;

    int size;
    cout << "Size of the list: ";
    cin >> size;
    cout << "Items: ";
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;
        list.insert(value);
    }

    cout << "Number of remaining items: ";
    list.deleteOddValues();
    int remainingSize = 0;
    Node* current = list.getHead();
    while (current != nullptr) {
        remainingSize++;
        current = current->next;
    }
    cout << remainingSize << endl;

    cout << "Items: ";
    if (remainingSize > 0) {
        list.display();
    } else {
        cout << "NONE" << endl;
    }

    return 0;
}
