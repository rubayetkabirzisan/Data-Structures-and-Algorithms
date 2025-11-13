#include<bits/stdc++.h>
using namespace std ;

class Node
{
private:
    int val;
    Node* next;

public:
    Node()
    {
        next = NULL;
    }

    int getValue()
    {
        return val;
    }

    Node* getNext()
    {
        return next;
    }

    void setVal(int x)
    {
        val = x;
    }

    void setNext(Node* node)
    {
        next = node;
    }
};

class Stack
{
private:
    Node* head;
    Node* tail;
    int size;

public:
    Stack()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void push(int n)
    {
        Node* newitem = new Node;
        newitem->setNext(NULL);
        newitem->setVal(n);

        if (head == NULL && tail == NULL)
        {
            head = newitem;
            tail = newitem;
        }
        else
        {
            newitem->setNext(head);
            head = newitem;
        }

        size++;
    }

    bool isEmpty()
    {
        return (size == 0);
    }

    int top()
    {
        if (isEmpty())
        {
            cout << "the stack is empty" << endl;
            return -1;
        }

        return head->getValue();
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "the stack is empty" << endl;
            return;
        }

        Node* temp = head;
        head = head->getNext();
        delete temp;

        size--;
    }

    int Size()
    {
        return size;
    }

    void displaystack()
    {
        if (isEmpty())
        {
            cout << "the stack is empty" << endl;
            return;
        }

        Node* temp = head;
        while (temp != NULL)
        {
            cout << temp->getValue() << " ";
            temp = temp->getNext();
        }
        cout << endl;
    }

    void replace_(int rep,int val)
    {
        Node *temp = tail;
        while(temp!=NULL)
        {
            if(temp->getValue()==rep)
            {
                temp->setVal(val);
            }
            temp=temp->getNext();
        }
    }

    ~Stack()
    {
        while (head != NULL)
        {
            Node* temp = head;
            head = head->getNext();
            delete temp;
        }
    }
};

int main()
{
    Stack s;
    int choice = -1;

    while (choice != 0)
    {
        cout << "0 - Exit." << endl;
        cout << "1 - Push Item." << endl;
        cout << "2 - Pop Item." << endl;
        cout << "3 - View Top Item." << endl;
        cout << "4 - Size of Stack." << endl;
        cout << "5 - Display Items (Print STACK)." << endl;
        cout << "6 - Replace an element." << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 0:
            break;

        case 1:
        {
            int n;
            cout << "enter the value: ";
            cin >> n;
            s.push(n);
            break;
        }

        case 2:
        {
            if (s.isEmpty() == true)
            {
                cout << "the stack is empty ";
                cout << endl;
            }
            else
            {
                s.pop();
            }
            break;
        }

        case 3:
        {
            if (s.isEmpty() == true)
            {
                cout << "the stack is empty ";
                cout << endl;
            }
            else
            {
                cout << "the top item is: " << s.top();
                cout << endl;
            }
            break;
        }

        case 4:
        {
            cout << "the current size of stack is: " << s.Size();
            cout << endl;
            break;
        }

        case 5:
        {
            cout << "the stack is: ";
            s.displaystack();
            cout << endl;
            break;
        }

        case 6:
        {
            int rep,val;

            cout<<"Item to replace : ";
            cout<<endl;
            cin>>rep;
            cout<<"Value : ";
            cin>>val;
            cout<<endl;

            s.replace_(rep,val);
            s.displaystack();

            break;
        }

        default:
            cout << "An Invalid choice." << endl;
        }

        cout << endl << endl;
    }

    return 0;
}
