#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int woc;
    Node *children[26];
    Node()
    {
        woc = 0;
        for(int i = 0; i < 26; i++)
        {
            this->children[i] = NULL;
        }
    }
};

void trie_insert(Node *root, string s)
{
    Node* cur = root;
    for (int i = 0; i < s.length(); i++)
    {
        int index = s[i] - 'A';
        if (!cur->children[index])
            cur->children[index] = new Node();
        cur = cur->children[index];
    }
    cur->woc++;
}

int trie_search(Node *root, string s, int k = 0)
{
    Node* cur = root;
    for (int i = 0; i < s.length(); i++)
    {
        int index = s[i] - 'A';
        if (!cur->children[index])
            return 0;
        cur = cur->children[index];
    }
    return cur->woc;
}

void printTRIE(Node *root, string s = "")
{
    if (root->woc > 0)
    {
        cout << s << " (" << root->woc << ")" << endl;
    }
    for (int i = 25; i >= 0; i--)
    {
        if (root->children[i])
        {
            printTRIE(root->children[i], s + char('A' + i));
        }
    }
}

void printPrefixStrings(Node *root, string prefix, string current = "")
{
    Node *currentNode = root;
    for (char c : prefix)
    {
        int index = c - 'A';
        if (!currentNode->children[index])
        {
            cout << "No strings found with prefix " << prefix << endl;
            return;
        }
        currentNode = currentNode->children[index];
        current += c;
    }

    if (currentNode->woc > 0)
    {
        cout << current << " (" << currentNode->woc << ")" << endl;
    }
    for (int i = 0; i < 26; i++)
    {
        if (currentNode->children[i])
        {
            printPrefixStrings(currentNode->children[i], prefix, current + char('A' + i));
        }
    }
}


bool isLeaf(Node *u)
{
    for (int i = 0; i < 26; i++)
    {
        if (u->children[i])
            return false;
    }
    return true;
}

void deleteEdge(Node *u, char c, int d)
{
    int index = c - 'A';
    if (u->children[index])
    {
        Node* child = u->children[index];
        if (child->woc <= d)
        {
            u->children[index] = nullptr;
            delete child;
        }
        else
        {
            deleteEdge(child, c, d);
        }
    }
}

bool isJunction(Node *u)
{
    int count = 0;
    for (int i = 0; i < 26; i++)
    {
        if (u->children[i])
        {
            count++;
            if (count > 1)
                return true;
        }
    }
    return false;
}

int deletee(string x, Node *root, int k = 0)
{
    if (k == x.length())
    {
        if (root->woc > 0)
        {
            root->woc--;
            return 1;
        }
        return 0;
    }

    int index = x[k] - 'A';
    if (!root->children[index])
    {
        return 0;
    }

    int result = deletee(x, root->children[index], k + 1);
    if (result)
    {
        if (isLeaf(root->children[index]) && root->children[index]->woc == 0 && !isJunction(root))
        {
            delete root->children[index];
            root->children[index] = nullptr;
        }
        return 1;
    }
    return 0;
}

void printDuplicates(Node *root, string current = "")
{
    if (root->woc > 1)
    {
        cout << current << " (" << root->woc << ")" << endl;
    }
    for (int i = 0; i < 26; i++)
    {
        if (root->children[i])
        {
            printDuplicates(root->children[i], current + char('A' + i));
        }
    }
}


int main()
{
    Node *root = new Node();

    while (1)
    {
        cout << "1. Insert    2. Search    3. Delete   4. Lexicographical Sorting  5. Display Strings  6. Print Prefix 7.Print Duplicate " << endl
             << endl;
        int choice;
        string x;
        cin >> choice;
        if (choice == 1)
        {
            cout << "Insert String: ";
            cin >> x;
            trie_insert(root, x);
            cout << x << " is inserted in the trie" << endl;
        }
        else if (choice == 2)
        {
            cout << "Enter string to search: ";
            cin >> x;
            if (trie_search(root, x) > 0)
                cout << x << " FOUND " << endl;
            else
                cout << x << " NOT FOUND " << endl;
        }
        else if (choice == 3)
        {
            cout << "Enter string to delete:" << endl;
            cin >> x;
            int result = deletee(x, root);
            if (result)
                cout << x << " is deleted from the trie" << endl;
            else
                cout << x << " is NOT FOUND in the trie" << endl;
        }
        else if (choice == 4)
        {
            printTRIE(root);
        }
        else if (choice == 5)
        {
            printTRIE(root);
        }
        else if (choice == 6)
        {
            cout << "Enter prefix to search for: ";
            cin >> x;
            cout << "Strings with prefix '" << x << "':" << endl;
            printPrefixStrings(root, x);
        }

        else if (choice == 7)
        {
            cout << "Duplicate Strings:" << endl;
            printDuplicates(root);
        }

        else
        {
            cout << "Invalid Choice" << endl;
            break;
        }
        cout << endl;
    }

}
