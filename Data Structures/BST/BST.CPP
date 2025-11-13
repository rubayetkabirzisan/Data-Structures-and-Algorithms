#include <iostream>
#include <queue>
#define SPACE 10

using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node()
    {
        data = 0;
        left = NULL;
        right = NULL;
    }
};

class tree
{
public:
    node *root;
    tree()
    {
        root = NULL;
    }
    void insert(int val)
    {
        node *newnode = new node;
        newnode->data = val;
        if (root == NULL)
        {
            root = newnode;
        }
        else
        {
            node *temp = root;
            while (temp != NULL)
            {
                if (temp->data == newnode->data)
                {
                    return;
                }
                else if (newnode->data < temp->data && temp->left == NULL)
                {
                    temp->left = newnode;
                }
                else if (newnode->data < temp->data)
                {
                    temp = temp->left;
                }
                else if (newnode->data > temp->data && temp->right == NULL)
                {
                    temp->right = newnode;
                }
                else
                {
                    temp = temp->right;
                }
            }
        }
    }

    void print(node *start)
    {
        if (start == NULL)
        {
            return;
        }
        print(start->left);
        cout << start->data << " ";
        print(start->right);
    }

    void print2D(node *start, int space)
    {
        if (start == NULL)
        {
            return;
        }
        space = space + SPACE;
        print2D(start->right, space);
        cout << endl;
        for (int i = SPACE; i < space; i++)
        {
            cout << " ";
        }
        cout << start->data << "\n";
        print2D(start->left, space);
    }

    int height(node *start)
    {
        if (start == NULL)
        {
            return 0;
        }
        else
        {
            int lheight = height(start->left);
            int rheight = height(start->right);
            if (lheight > rheight)
            {
                return lheight + 1;
            }
            else
            {
                return rheight + 1;
            }
        }
    }

    void level_order_traversal()
    {
        if (root == NULL)
        {
            cout << "The BST is empty!!!" << endl;
            return;
        }

        queue<node *> q;
        q.push(root);
        while (!q.empty())
        {
            node *current = q.front();
            q.pop();
            cout << current->data << " ";
            if (current->left != NULL)
            {
                q.push(current->left);
            }
            if (current->right != NULL)
            {
                q.push(current->right);
            }
        }
    }

    node *minValueNode(node *start)
    {
        while (start->left != NULL)
        {
            start = start->left;
        }
        return start;
    }

    void search(int val)
    {
        if (root == NULL)
        {
            cout << "The BST is empty!!!" << endl;
            return;
        }

        node *temp = root;
        while (temp != NULL)
        {
            if (temp->data == val)
            {
                cout << "Item is found at node: " << temp << endl;
                return;
            }
            else if (temp->data < val)
            {
                temp = temp->right;
            }
            else
            {
                temp = temp->left;
            }
        }
        cout << "Item is not found!" << endl;
    }

    node *delete_node(node *start, int val)
    {
        if (start == nullptr)
        {
            return start;
        }

        if (val < start->data)
        {
            start->left = delete_node(start->left, val);
        }
        else if (val > start->data)
        {
            start->right = delete_node(start->right, val);
        }
        else
        {
            if (start->left == nullptr)
            {
                node *temp = start->right;
                delete start;
                return temp;
            }
            else if (start->right == nullptr)
            {
                node *temp = start->left;
                delete start;
                return temp;
            }

            node *temp = minValueNode(start->right);
            start->data = temp->data;
            start->right = delete_node(start->right, temp->data);
        }

        return start;
    }
};

int main()
{
    tree l1;
    l1.insert(50);
    l1.insert(20);
    l1.insert(40);
    l1.insert(60);
    l1.insert(10);
    l1.insert(30);
    l1.insert(5);
    l1.print2D(l1.root, 1);
    l1.search(30);
    cout << "The max height is " << l1.height(l1.root) << endl;
    l1.delete_node(l1.root, 10);
    l1.level_order_traversal();

    return 0;
}
