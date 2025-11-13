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
        // Check if the value already exists in the list
        if (exists(value)) {
            return;
        }

        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            if (value < head->data) {
                newNode->next = head;
                head = newNode;
            } else {
                Node* current = head;
                while (current->next != nullptr && current->next->data < value) {
                    current = current->next;
                }
                newNode->next = current->next;
                current->next = newNode;
            }
        }
    }

    bool exists(int value) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    static LinkedList mergeSortedLists(const LinkedList& list1, const LinkedList& list2) {
        LinkedList mergedList;
        Node* current1 = list1.head;
        Node* current2 = list2.head;

        while (current1 != nullptr && current2 != nullptr) {
            if (current1->data < current2->data) {
                mergedList.insert(current1->data);
                current1 = current1->next;
            } else if (current2->data < current1->data) {
                mergedList.insert(current2->data);
                current2 = current2->next;
            } else {
                // If both values are equal, insert only once
                mergedList.insert(current1->data);
                current1 = current1->next;
                current2 = current2->next;
            }
        }

        // Append remaining nodes from list1, if any
        while (current1 != nullptr) {
            mergedList.insert(current1->data);
            current1 = current1->next;
        }

        // Append remaining nodes from list2, if any
        while (current2 != nullptr) {
            mergedList.insert(current2->data);
            current2 = current2->next;
        }

        return mergedList;
    }
};

int main() {
    LinkedList list1;
    LinkedList list2;

    int size1, size2;
    cout << "Size of the list 1: ";
    cin >> size1;
    cout << "Items in List 1: ";
    for (int i = 0; i < size1; i++) {
        int value;
        cin >> value;
        list1.insert(value);
    }

    cout << "Size of List 2: ";
    cin >> size2;
    cout << "Items in List 2: ";
    for (int i = 0; i < size2; i++) {
        int value;
        cin >> value;
        list2.insert(value);
    }

    LinkedList mergedList = LinkedList::mergeSortedLists(list1, list2);
    cout << "Merged List: ";
    mergedList.display();

    return 0;
}
