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

    void insert(int value)
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

    bool contains(int value)
    {
        Node* current = head;
        while (current != nullptr)
        {
            if (current->data == value)
                return true;
            current = current->next;
        }
        return false;
    }

    void removeElements(LinkedList& secondList)
    {
        if (head == nullptr || secondList.head == nullptr)
            return;

        Node* current = head;
        Node* prev = nullptr;

        while (current != nullptr)
        {
            if (secondList.contains(current->data))
            {
                if (prev == nullptr)
                {
                    head = current->next;
                    delete current;
                    current = head;
                }
                else
                {
                    prev->next = current->next;
                    delete current;
                    current = prev->next;
                }
            }
            else
            {
                prev = current;
                current = current->next;
            }
        }
    }

    bool isEmpty()
    {
        return head == nullptr;
    }

    void display()
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
    LinkedList list1;
    LinkedList list2;

    int size1;
    cout << "Size of list 1: ";
    cin >> size1;
    cout << "Items in list 1: ";
    for (int i = 0; i < size1; i++)
    {
        int value;
        cin >> value;
        list1.insert(value);
    }

    int size2;
    cout << "Size of list 2: ";
    cin >> size2;
    cout << "Items in list 2: ";
    for (int i = 0; i < size2; i++)
    {
        int value;
        cin >> value;
        list2.insert(value);
    }

    list1.removeElements(list2);

    if (list1.isEmpty())
        cout << "No elements of the first linked list are contained in the second linked list" << endl;
    else
    {
        cout << "After Deletion:" << endl;
        cout << "List 1: ";
        list1.display();
        cout << "List 2: ";
        list2.display();
    }

    return 0;
}
