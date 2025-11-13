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

    ~LinkedList()
    {
        while (head != nullptr)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insertAtBeginning(int value)
    {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int value)
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

    void insertAtPosition(int value, int position)
    {
        if (position < 0)
        {
            cout << "Invalid position" << endl;
            return;
        }

        if (position == 0)
        {
            insertAtBeginning(value);
            return;
        }

        Node* newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node* current = head;
            int currentPosition = 0;

            while (current->next != nullptr && currentPosition < position - 1)
            {
                current = current->next;
                currentPosition++;
            }

            newNode->next = current->next;
            current->next = newNode;
        }
    }

    void deleteAtBeginning()
    {
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }

        Node* nodeToDelete = head;
        head = head->next;
        delete nodeToDelete;
    }

    void deleteAtEnd()
    {
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }

        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            return;
        }

        Node* current = head;
        while (current->next->next != nullptr)
        {
            current = current->next;
        }

        delete current->next;
        current->next = nullptr;
    }

    void deleteAtPosition(int position)
    {
        if (position < 0 || head == nullptr)
        {
            cout << "Invalid position" << endl;
            return;
        }

        if (position == 0)
        {
            deleteAtBeginning();
            return;
        }

        Node* current = head;
        int currentPosition = 0;

        while (current->next != nullptr && currentPosition < position - 1)
        {
            current = current->next;
            currentPosition++;
        }

        if (current->next == nullptr)
        {
            cout << "Invalid position" << endl;
            return;
        }

        Node* nodeToDelete = current->next;
        current->next = current->next->next;
        delete nodeToDelete;
    }

    void printList()
    {
        Node* current = head;
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
    LinkedList list;

    list.insertAtBeginning(5);
    list.insertAtBeginning(3);
    list.insertAtEnd(7);
    list.insertAtPosition(4, 1);
    list.printList(); // Output: 3 4 5 7

    list.deleteAtBeginning();
    list.deleteAtEnd();
    list.deleteAtPosition(1);
    list.printList(); // Output: 4

    return 0;
}
