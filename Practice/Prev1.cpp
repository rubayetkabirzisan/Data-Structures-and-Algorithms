#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int key;
    Node* left;
    Node* right;

    Node(int k) {
        key = k;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
private:
    Node* root;

    Node* insertRec(Node* root, int key) {
        if (root == nullptr) {
            return new Node(key);
        }
        if (key < root->key) {
            root->left = insertRec(root->left, key);
        }
        else if (key > root->key) {
            root->right = insertRec(root->right, key);
        }
        return root;
    }

    void printByLevelRec(Node* root) {
        if (root == nullptr)
            return;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();
            cout << current->key << " ";

            if (current->left != nullptr)
                q.push(current->left);
            if (current->right != nullptr)
                q.push(current->right);
        }
    }

    void printInorderRec(Node* root) {
        if (root == nullptr)
            return;

        printInorderRec(root->left);
        cout << root->key << " ";
        printInorderRec(root->right);
    }

    int maxOfLevelRec(Node* root, int level, int currentLevel = 0) {
        if (root == nullptr)
            return -1;

        if (currentLevel == level)
            return root->key;

        int leftMax = maxOfLevelRec(root->left, level, currentLevel + 1);
        int rightMax = maxOfLevelRec(root->right, level, currentLevel + 1);

        return max(leftMax, rightMax);
    }

    Node* deleteMinRec(Node* root) {
        if (root == nullptr)
            return nullptr;
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        root->left = deleteMinRec(root->left);
        return root;
    }

public:
    BST() {
        root = nullptr;
    }

    void insert(int key) {
        if (key <= 0)
            return;
        root = insertRec(root, key);
    }

    void printByLevel() {
        printByLevelRec(root);
        cout << endl;
    }

    void printInorder() {
        printInorderRec(root);
        cout << endl;
    }

    int maxOfLevel(int level) {
        return maxOfLevelRec(root, level);
    }

    void deleteMin() {
        root = deleteMinRec(root);
        cout << "Minimum node deleted." << endl;
    }
};

int main() {
    BST bst;
    int choice;

    do {
        cout << "Menu:\n";
        cout << "1. Insert a positive integer\n";
        cout << "2. Print keys by level\n";
        cout << "3. Print keys in inorder\n";
        cout << "4. Get maximum key of a level\n";
        cout << "5. Delete the minimum node\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                int key;
                cout << "Enter a positive integer to insert: ";
                cin >> key;
                bst.insert(key);
                break;
            case 2:
                cout << "Keys by level: ";
                bst.printByLevel();
                break;
            case 3:
                cout << "Keys in inorder: ";
                bst.printInorder();
                break;
            case 4:
                int level;
                cout << "Enter the level: ";
                cin >> level;
                cout << "Maximum key of level " << level << ": " << bst.maxOfLevel(level) << endl;
                break;
            case 5:
                bst.deleteMin();
                break;
            case 6:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }

        cout << endl;
    } while (choice != 6);

    return 0;
}

