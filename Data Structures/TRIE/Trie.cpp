#include <bits/stdc++.h>
using namespace std;

const int ALPHABET_SIZE = 26;

class TrieNode
{
public:
    char data;
    TrieNode* children[ALPHABET_SIZE];
    bool isTerminal;
    bool isJunction;

    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < ALPHABET_SIZE; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
        isJunction = false;
    }
};

class Trie
{
public:
    TrieNode* root;

    Trie()
    {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root, string word)
    {
        // Base case
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        // Assumption: words will be in CAPS
        int index = word[0] - 'A';
        TrieNode* child;

        // Present
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            // Absent
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursion
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word)
    {
        insertUtil(root, word);
    }

    bool searchUtil(TrieNode* root, string word)
    {
        // Base case
        if (word.length() == 0)
        {
            return root->isTerminal; // Return whether the current node is a terminal node.
        }

        // Assumption: words will be in CAPS
        int index = word[0] - 'A';
        TrieNode* child;

        // Present
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            // Absent
            return false;
        }

        // Recursion
        return searchUtil(child, word.substr(1));
    }

    bool searchWord(string word)
    {
        return searchUtil(root, word);
    }

    bool isEmpty(TrieNode* root)
    {
        for (int i = 0; i < 26; i++)
        {
            if (root->children[i])
            {
                return false;
            }
        }
        return true;
    }

    TrieNode* deleteUtil(TrieNode* root, string word)
    {
        if (root == NULL)
        {
            return NULL;
        }

        // Last character being processed
        if (word.length() == 0)
        {
            // This will not be a word after removal
            if (root->isTerminal)
                root->isTerminal = false;

            // If this is not a prefix of any other word. [not helping to make any other word]
            if (isEmpty(root))
            {
                delete root;
                root = NULL;
            }

            return root;
        }

        // Recursion call
        int index = word[0] - 'A';
        root->children[index] = deleteUtil(root->children[index], word.substr(1));

        // Backtracking
        // If root has no child (as its only child got deleted) and it is also not the end of any other word
        if (isEmpty(root) && root->isTerminal == false)
        {
            delete root;
            root = NULL;
        }

        return root;
    }

    TrieNode* deleteWord(string word)
    {
        return deleteUtil(root, word);
    }

    void dfsLexicographical(TrieNode* node, string currentWord)
    {
        if (!node)
        {
            return;
        }

        if (node->isTerminal)
        {
            cout << currentWord << endl; // Print the word directly
        }

        for (int i = 0; i < ALPHABET_SIZE; i++)
        {
            if (node->children[i])
            {
                char ch = 'A' + i;
                dfsLexicographical(node->children[i], currentWord + ch);
            }
        }
    }

    void printWordsInLexicographicalOrder()
    {
        dfsLexicographical(root, "");
    }

    void printJunctionPoints(TrieNode* node, string currentWord)
    {
        if (!node)
        {
            return;
        }

        if (node->isJunction)
        {
            cout << "Junction Point: " << currentWord << endl;
        }

        for (int i = 0; i < ALPHABET_SIZE; i++)
        {
            if (node->children[i])
            {
                char ch = 'A' + i;
                printJunctionPoints(node->children[i], currentWord + ch);
            }
        }
    }

    void printAllJunctionPoints()
    {
        printJunctionPoints(root, "");
    }
};

int main()
{
    Trie* t = new Trie();

    t->insertWord("MIST");
    t->insertWord("MIT");
    t->insertWord("CSE");
    t->insertWord("CSE");
    t->insertWord("CE");
    t->insertWord("MISTCSE");
    t->insertWord("ME");
    t->insertWord("EECE");
    t->insertWord("ABC");
    t->insertWord("ABC");
    t->insertWord("AB");

    cout << "Present or Not: " << t->searchWord("TIME") << endl;

    // Delete a word from the Trie
    t->deleteWord("CSE");
    t->deleteWord("ABC");

    // Check if the deleted word is still present
    cout << "After deletion - Present or Not: " << t->searchWord("CSE") << endl;
    cout << "After deletion - Present or Not: " << t->searchWord("ABC") << endl;

    // Print words in lexicographical order
    cout << "Words in lexicographical order:" << endl;
    t->printWordsInLexicographicalOrder();

    cout << "Junction Points:" << endl;
    t->printAllJunctionPoints();

}
