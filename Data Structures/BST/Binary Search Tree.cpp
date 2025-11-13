#include <iostream>
using namespace std;

class Node
{
public:
    int key;
    Node* left;
    Node* right;

    Node(int k)
    {
        key = k;
        left = nullptr;
        right = nullptr;
    }
};

class BST
{
private:
    Node* root;

    Node* insertRec(Node* root, int key)
    {
        if (root == nullptr)
        {
            return new Node(key);
        }
        if (key < root->key)
        {
            root->left = insertRec(root->left, key);
        }
        else if (key > root->key)
        {
            root->right = insertRec(root->right, key);
        }
        return root;
    }

    Node* deleteRec(Node* root, int key)
    {
        if (root == nullptr)
        {
            return nullptr;
        }
        if (key < root->key)
        {
            root->left = deleteRec(root->left, key);
        }
        else if (key > root->key)
        {
            root->right = deleteRec(root->right, key);
        }
        else
        {
            if (root->left == nullptr)
            {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == nullptr)
            {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            Node* successor = findMin(root->right);
            root->key = successor->key;
            root->right = deleteRec(root->right, successor->key);
        }
        return root;
    }

    Node* searchRec(Node* root, int key)
    {
        if (root == nullptr || root->key == key)
        {
            return root;
        }
        if (key < root->key)
        {
            return searchRec(root->left, key);
        }
        return searchRec(root->right, key);
    }

    void inorderRec(Node* root)
    {
        if (root != nullptr)
        {
            inorderRec(root->left);
            cout << root->key << " ";
            inorderRec(root->right);
        }
    }

    void preorderRec(Node* root)
    {
        if (root != nullptr)
        {
            cout << root->key << " ";
            preorderRec(root->left);
            preorderRec(root->right);
        }
    }

    void postorderRec(Node* root)
    {
        if (root != nullptr)
        {
            postorderRec(root->left);
            postorderRec(root->right);
            cout << root->key << " ";
        }
    }

public:
    BST()
    {
        root = nullptr;
    }

    void insert(int key)
    {
        root = insertRec(root, key);
    }

    void remove(int key)
    {
        root = deleteRec(root, key);
    }

    Node* search(int key)
    {
        return searchRec(root, key);
    }

    void inorder()
    {
        inorderRec(root);
    }

    void preorder()
    {
        preorderRec(root);
    }

    void postorder()
    {
        postorderRec(root);
    }

    Node* findMin(Node* root)
    {
        if (root == nullptr)
        {
            return nullptr;
        }
        while (root->left != nullptr)
        {
            root = root->left;
        }
        return root;
    }
};

int main()
{
    BST bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    cout << "Inorder Traversal: ";
    bst.inorder();
    cout << endl;

    cout << "Preorder Traversal: ";
    bst.preorder();
    cout << endl;

    cout << "Postorder Traversal: ";
    bst.postorder();
    cout << endl;

    int key = 40;
    Node* searchResult = bst.search(key);
    if (searchResult != nullptr)
    {
        cout << key << " found in the BST." << endl;
    }
    else
    {
        cout << key << " not found in the BST." << endl;
    }

    key = 55;
    searchResult = bst.search(key);
    if (searchResult != nullptr)
    {
        cout << key << " found in the BST." << endl;
    }
    else
    {
        cout << key << " not found in the BST." << endl;
    }

    bst.remove(30);
    cout << "Inorder Traversal after deleting 30: ";
    bst.inorder();
    cout << endl;

    return 0;
}

