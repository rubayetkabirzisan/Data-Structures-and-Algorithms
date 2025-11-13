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

class LinkedList
{
private:
    Node* head;

public:
    LinkedList()
    {
        head = nullptr;
    }

    void insertAtFirst(int value)
    {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void insertAtLast(int value)
    {
        Node* newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node* current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void insertAfterNode(int nodeValue, int value)
    {
        Node* newNode = new Node(value);
        Node* current = head;
        while (current != nullptr)
        {
            if (current->data == nodeValue)
            {
                newNode->next = current->next;
                current->next = newNode;
                break;
            }
            current = current->next;
        }
    }

    void deleteFirst()
    {
        if (head == nullptr)
        {
            cout << "List is empty. Cannot delete first node." << endl;
        }
        else
        {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void deleteLast()
    {
        if (head == nullptr)
        {
            cout << "List is empty. Cannot delete last node." << endl;
        }
        else if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
        }
        else
        {
            Node* current = head;
            while (current->next->next != nullptr)
            {
                current = current->next;
            }
            delete current->next;
            current->next = nullptr;
        }
    }

    void deleteNode(int value)
    {
        if (head == nullptr)
        {
            cout << "List is empty. Cannot delete node." << endl;
        }
        else if (head->data == value)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        else
        {
            Node* current = head;
            while (current->next != nullptr)
            {
                if (current->next->data == value)
                {
                    Node* temp = current->next;
                    current->next = current->next->next;
                    delete temp;
                    break;
                }
                current = current->next;
            }
        }
    }

    void display()
    {
        Node* current = head;
        while (current != nullptr)
        {
            cout << current->data;
            if (current->next != nullptr)
            {
                cout << " -> ";
            }
            current = current->next;
        }
        cout << endl;
    }

};

int main()
{
    LinkedList list;

    // Insert at first
    list.insertAtFirst(1);
    list.insertAtFirst(2);
    list.insertAtFirst(3);
    list.display(); // Output: 3 -> 2 ->

    // Insert at last
    list.insertAtLast(4);
    list.insertAtLast(5);
    list.display(); // Output: 3 -> 2 -> 1 -> 4 -> 5

    // Insert after node
    list.insertAfterNode(1, 6);
    list.display(); // Output: 3 -> 2 -> 1 -> 6 -> 4 -> 5

    // Delete first
    list.deleteFirst();
    list.display(); // Output: 2 -> 1 -> 6 -> 4 -> 5

    // Delete last
    list.deleteLast();
    list.display(); // Output: 2 -> 1 -> 6 -> 4

    // Delete node
    list.deleteNode(6);
    list.display(); // Output: 2 -> 1 -> 4

    return 0;
}

