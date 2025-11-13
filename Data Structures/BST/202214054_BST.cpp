#include<bits/stdc++.h>
using namespace std;

class Book
{
private:
    string isbn;
    string title;
    string author;
    double price;
    int quantity;

public:

    Book(string isbn, string title, string author, double price, int quantity)
        : isbn(isbn), title(title), author(author), price(price), quantity(quantity) {}


    string getISBN() const
    {
        return isbn;
    }

    string getTitle() const
    {
        return title;
    }

    string getAuthor() const
    {
        return author;
    }

    double getPrice() const
    {
        return price;
    }

    int getQuantity() const
    {
        return quantity;
    }


    void setPrice(double price)
    {
        this->price = price;
    }

    void setQuantity(int quantity)
    {
        this->quantity = quantity;
    }
};


class BST
{
private:
    struct Node
    {
        Book* book;
        Node* left;
        Node* right;

        Node(Book* book) : book(book), left(nullptr), right(nullptr) {}
    };

    Node* root;

public:

    BST() : root(nullptr) {}


    ~BST()
    {
        clear(root);
    }


    void clear(Node* node)
    {
        if (node)
        {
            clear(node->left);
            clear(node->right);
            delete node->book;
            delete node;
        }
    }


    void addBook(string isbn, string title, string author, double price, int quantity)
    {
        Book* book = new Book(isbn, title, author, price, quantity);
        Node* newNode = new Node(book);

        if (root == nullptr)
        {
            root = newNode;
        }
        else
        {
            Node* current = root;
            Node* parent = nullptr;

            while (true)
            {
                parent = current;

                if (isbn < current->book->getISBN())
                {
                    current = current->left;
                    if (current == nullptr)
                    {
                        parent->left = newNode;
                        break;
                    }
                }
                else
                {
                    current = current->right;
                    if (current == nullptr)
                    {
                        parent->right = newNode;
                        break;
                    }
                }
            }
        }

        cout << "Book added to the inventory successfully." << endl;
    }


    void removeBook(string isbn)
    {
        Node* parent = nullptr;
        Node* current = root;
        bool isLeftChild = false;

        while (current != nullptr)
        {
            if (current->book->getISBN() == isbn)
            {
                break;
            }

            parent = current;

            if (isbn < current->book->getISBN())
            {
                current = current->left;
                isLeftChild = true;
            }
            else
            {
                current = current->right;
                isLeftChild = false;
            }
        }

        if (current == nullptr)
        {
            cout << "Book not found in the inventory." << endl;
            return;
        }

        if (current->left == nullptr && current->right == nullptr)
        {
            if (current == root)
            {
                root = nullptr;
            }
            else if (isLeftChild)
            {
                parent->left = nullptr;
            }
            else
            {
                parent->right = nullptr;
            }
        }
        else if (current->right == nullptr)
        {
            if (current == root)
            {
                root = current->left;
            }
            else if (isLeftChild)
            {
                parent->left = current->left;
            }
            else
            {
                parent->right = current->left;
            }
        }
        else if (current->left == nullptr)
        {
            if (current == root)
            {
                root = current->right;
            }
            else if (isLeftChild)
            {
                parent->left = current->right;
            }
            else
            {
                parent->right = current->right;
            }
        }
        else
        {
            Node* successor = getSuccessor(current);
            if (current == root)
            {
                root = successor;
            }
            else if (isLeftChild)
            {
                parent->left = successor;
            }
            else
            {
                parent->right = successor;
            }
            successor->left = current->left;
        }

        delete current;
        cout << "Book removed from the inventory successfully." << endl;
    }


    Node* getSuccessor(Node* node)
    {
        Node* parent = node;
        Node* successor = node;
        Node* current = node->right;

        while (current != nullptr)
        {
            parent = successor;
            successor = current;
            current = current->left;
        }

        if (successor != node->right)
        {
            parent->left = successor->right;
            successor->right = node->right;
        }

        return successor;
    }


    void updateQuantity(string isbn, int quantity)
    {
        Node* current = root;

        while (current != nullptr)
        {
            if (current->book->getISBN() == isbn)
            {
                current->book->setQuantity(quantity);
                cout << "Quantity updated successfully." << endl;
                return;
            }
            else if (isbn < current->book->getISBN())
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }

        cout << "Book not found in the inventory." << endl;
    }


    void searchBook(string isbn)
    {
        Node* current = root;

        while (current != nullptr)
        {
            if (current->book->getISBN() == isbn)
            {
                cout << "ISBN: " << current->book->getISBN() << endl;
                cout << "Title: " << current->book->getTitle() << endl;
                cout << "Author: " << current->book->getAuthor() << endl;
                cout << "Price: $" << current->book->getPrice() << endl;
                cout << "Quantity: " << current->book->getQuantity() << endl;
                return;
            }
            else if (isbn < current->book->getISBN())
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }

        cout << "Book not found in the inventory." << endl;
    }


    void displayAllBooks(Node* node)
    {
        if (node)
        {
            displayAllBooks(node->left);
            cout << "ISBN: " << node->book->getISBN() << endl;
            cout << "Title: " << node->book->getTitle() << endl;
            cout << "Author: " << node->book->getAuthor() << endl;
            cout << "Price: $" << node->book->getPrice() << endl;
            cout << "Quantity: " << node->book->getQuantity() << endl;
            cout << endl;
            displayAllBooks(node->right);
        }
    }


    void startInventoryManagementSystem()
    {
        cout << "Welcome to the Bookstore Inventory Management System!" << endl;

        while (true)
        {
            cout << "1. Add a book to the inventory" << endl;
            cout << "2. Remove a book from the inventory" << endl;
            cout << "3. Update the quantity of a book" << endl;
            cout << "4. Search for a book by ISBN" << endl;
            cout << "5. Display all books in the inventory" << endl;
            cout << "6. Exit" << endl;

            int choice;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
            {
                string isbn, title, author;
                double price;
                int quantity;

                cout << "Enter the book's ISBN: ";
                cin.ignore();
                getline(cin, isbn);

                cout << "Enter the book's title: ";
                getline(cin, title);

                cout << "Enter the book's author: ";
                getline(cin, author);

                cout << "Enter the book's price: ";
                cin >> price;

                cout << "Enter the book's quantity: ";
                cin >> quantity;

                addBook(isbn, title, author, price, quantity);
                break;
            }
            case 2:
            {
                string isbn;

                cout << "Enter the ISBN of the book to remove: ";
                cin.ignore();
                getline(cin, isbn);

                removeBook(isbn);
                break;
            }
            case 3:
            {
                string isbn;
                int quantity;

                cout << "Enter the ISBN of the book to update quantity: ";
                cin.ignore();
                getline(cin, isbn);

                cout << "Enter the new quantity: ";
                cin >> quantity;

                updateQuantity(isbn, quantity);
                break;
            }
            case 4:
            {
                string isbn;

                cout << "Enter the ISBN of the book to search: ";
                cin.ignore();
                getline(cin, isbn);

                searchBook(isbn);
                break;
            }
            case 5:
            {
                cout << "Inventory:" << endl;
                displayAllBooks(root);
                break;
            }
            case 6:
            {
                return;
            }
            default:
                cout << "Invalid choice. Please try again." << endl;
            }
        }
    }
};

int main()
{
    BST inventory;
    inventory.startInventoryManagementSystem();
    return 0;
}
