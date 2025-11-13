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

    void insertAtEnd(int value) {
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

    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    static LinkedList calculateAverageList(const LinkedList& list1, const LinkedList& list2) {
        LinkedList averageList;
        Node* current1 = list1.head;
        Node* current2 = list2.head;
        while (current1 != nullptr || current2 != nullptr) {
            int value1 = (current1 != nullptr) ? current1->data : 0;
            int value2 = (current2 != nullptr) ? current2->data : 0;
            int average = (value1 + value2) / 2;
            averageList.insertAtEnd(average);
            if (current1 != nullptr) {
                current1 = current1->next;
            }
            if (current2 != nullptr) {
                current2 = current2->next;
            }
        }
        return averageList;
    }
};

int main() {
    LinkedList list1;
    LinkedList list2;

    int size1, size2;
    cout << "Size of list 1: ";
    cin >> size1;
    cout << "Items in list 1: ";
    for (int i = 0; i < size1; i++) {
        int value;
        cin >> value;
        list1.insertAtEnd(value);
    }

    cout << "Size of list 2: ";
    cin >> size2;
    cout << "Items in list 2: ";
    for (int i = 0; i < size2; i++) {
        int value;
        cin >> value;
        list2.insertAtEnd(value);
    }

    LinkedList averageList = LinkedList::calculateAverageList(list1, list2);
    averageList.display();

    return 0;
}
