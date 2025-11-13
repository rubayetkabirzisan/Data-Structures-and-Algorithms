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

    void deleteDuplicates() {
        if (head == nullptr)
            return;

        Node* current = head;
        Node* runner;
        Node* duplicate;

        while (current != nullptr) {
            runner = current;
            while (runner->next != nullptr) {
                if (runner->next->data == current->data) {
                    duplicate = runner->next;
                    runner->next = runner->next->next;
                    delete duplicate;
                } else {
                    runner = runner->next;
                }
            }
            current = current->next;
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

    int countRemainingItems() {
        Node* current = head;
        int count = 0;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
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

    list.deleteDuplicates();

    int remainingSize = list.countRemainingItems();

    cout << "Number of remaining items: " << remainingSize << endl;
    if (remainingSize == 0) {
        cout << "Items: NONE" << endl;
    } else {
        cout << "Items: ";
        list.display();
    }

    return 0;
}

