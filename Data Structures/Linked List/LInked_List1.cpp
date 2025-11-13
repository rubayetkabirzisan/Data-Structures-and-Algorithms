#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value)
    {
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList
{
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    void insertAtFirst(int value)
    {
        Node* newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        cout << "Inserted " << value << " at the beginning." << endl;
    }

    void insertAtLast(int value)
    {
        Node* newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        cout << "Inserted " << value << " at the end." << endl;
    }

    void insertAfterNode(int value, int afterValue)
    {
        if (head == nullptr)
        {
            cout << "List is empty. Cannot perform insertion." << endl;
            return;
        }

        Node* newNode = new Node(value);
        Node* current = head;
        while (current != nullptr)
        {
            if (current->data == afterValue)
            {
                newNode->next = current->next;
                newNode->prev = current;
                if (current->next != nullptr)
                {
                    current->next->prev = newNode;
                }
                else
                {
                    tail = newNode;
                }
                current->next = newNode;
                cout << "Inserted " << value << " after " << afterValue << "." << endl;
                return;
            }
            current = current->next;
        }

        cout << "Node with value " << afterValue << " not found. Cannot perform insertion." << endl;
    }

    void deleteFirst()
    {
        if (head == nullptr)
        {
            cout << "List is empty. Cannot delete." << endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        if (head != nullptr)
        {
            head->prev = nullptr;
        }
        else
        {
            tail = nullptr;
        }
        delete temp;
        cout << "Deleted the first item." << endl;
    }

    void deleteLast()
    {
        if (head == nullptr)
        {
            cout << "List is empty. Cannot delete." << endl;
            return;
        }

        Node* temp = tail;
        tail = tail->prev;
        if (tail != nullptr)
        {
            tail->next = nullptr;
        }
        else
        {
            head = nullptr;
        }
        delete temp;
        cout << "Deleted the last item." << endl;
    }

    void deleteNode(int value)
    {
        if (head == nullptr)
        {
            cout << "List is empty. Cannot delete." << endl;
            return;
        }

        Node* current = head;
        while (current != nullptr)
        {
            if (current->data == value)
            {
                if (current == head)
                {
                    deleteFirst();
                }
                else if (current == tail)
                {
                    deleteLast();
                }
                else
                {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                    delete current;
                    cout << "Deleted node with value " << value<< "." << endl;
                    return;
                }
            }
            current = current->next;
        }
        cout << "Node with value " << value << " not found. Cannot delete." << endl;
    }

    void displayList()
    {
        if (head == nullptr)
        {
            cout << "List is empty." << endl;
            return;
        }

        Node* current = head;
        cout << "Doubly Linked List: ";
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
    DoublyLinkedList list;
    int choice = -1;
    while (choice != 0)
    {
        cout << "0 - Exit." << endl;
        cout << "1 - Insert at the beginning." << endl;
        cout << "2 - Insert at the end." << endl;
        cout << "3 - Insert after a node." << endl;
        cout << "4 - Delete the first item." << endl;
        cout << "5 - Delete the last item." << endl;
        cout << "6 - Delete a node." << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 0:
            break;

        case 1:
        {
            int value;
            cout << "Enter the value to insert: ";
            cin >> value;
            list.insertAtFirst(value);
            list.displayList();
            break;
        }

        case 2:
        {
            int value;
            cout << "Enter the value to insert: ";
            cin >> value;
            list.insertAtLast(value);
            list.displayList();
            break;
        }

        case 3:
        {
            int value, afterValue;
            cout << "Enter the value to insert: ";
            cin >> value;
            cout << "Enter the value after which to insert: ";
            cin >> afterValue;
            list.insertAfterNode(value, afterValue);
            list.displayList();
            break;
        }

        case 4:
            list.deleteFirst();
            list.displayList();
            break;

        case 5:
            list.deleteLast();
            list.displayList();
            break;

        case 6:
        {
            int value;
            cout << "Enter the value to delete: ";
            cin >> value;
            list.deleteNode(value);
            list.displayList();
            break;
        }

        default:
            cout << "Invalid choice." << endl;
        }

        cout << endl;
    }

    return 0;
}
