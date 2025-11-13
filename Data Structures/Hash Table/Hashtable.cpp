#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class SymbolInfo {
public:
    string symbol;
    string type;
    SymbolInfo *next;

    SymbolInfo(string sym, string typ) : symbol(sym), type(typ), next(nullptr) {}
};

class SymbolTable {
private:
    vector<list<SymbolInfo*>> table;
    int size;

    int hashFunction(const string& key) {
        int asciiSum = 0;
        for (char c : key) {
            asciiSum += c;
        }
        int rollLastTwoDigits = 3;  // Example last two digits
        int index = (asciiSum * rollLastTwoDigits) % size;
        return index;
    }

public:
    SymbolTable(int rollLastTwo) : size(rollLastTwo + 5) {
        table.resize(size);
    }

    void insert(const string& symbol, const string& type) {
        int index = hashFunction(symbol);
        for (SymbolInfo* entry : table[index]) {
            if (entry->symbol == symbol) {
                cout << "Symbol already exists!" << endl;
                return;
            }
        }
        SymbolInfo* newSymbol = new SymbolInfo(symbol, type);
        table[index].push_back(newSymbol);
        cout << "Inserted at position " << index << "," << table[index].size() - 1 << endl;
    }

    void lookup(const string& symbol) {
        int index = hashFunction(symbol);
        int pos = 0;
        for (SymbolInfo* entry : table[index]) {
            if (entry->symbol == symbol) {
                cout << "Found at " << index << "," << pos << endl;
                return;
            }
            pos++;
        }
        cout << "Symbol not found." << endl;
    }

    void deleteSymbol(const string& symbol) {
        int index = hashFunction(symbol);
        auto& chain = table[index];
        for (auto it = chain.begin(); it != chain.end(); ++it) {
            if ((*it)->symbol == symbol) {
                chain.erase(it);
                cout << "Deleted from " << index << endl;
                return;
            }
        }
        cout << "Symbol to delete not found." << endl;
    }

    void print() {
        for (int i = 0; i < size; ++i) {
            if (!table[i].empty()) {
                cout << i << " -->";
                for (SymbolInfo* entry : table[i]) {
                    cout << " <" << entry->symbol << ", " << entry->type << ">";
                }
                cout << endl;
            }
        }
    }
};

int main() {
    SymbolTable symTable(3);  // Assuming last two digits are 03, adjust size accordingly
    symTable.insert("var1", "IDENTIFIER");
    symTable.insert("123", "NUMBER");
    symTable.lookup("var1");
    symTable.deleteSymbol("123");
    symTable.print();
    return 0;
}
