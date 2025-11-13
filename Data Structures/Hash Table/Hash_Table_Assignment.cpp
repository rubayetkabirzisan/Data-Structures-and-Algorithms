#include <iostream>
#include <list>
#include <vector>
#include <string>

using namespace std;

class SymbolInfo {
public:
    string symbol;
    string type;

    SymbolInfo(string sym, string typ) : symbol(sym), type(typ) {}
};

class SymbolTable {
private:
    vector<list<SymbolInfo>> table;
    int rollLastTwoDigits = 54;  // Adjust to your roll number's last two digits.
    int tableSize;

    int hashFunction(const string& key) {
        int asciiSum = 0;
        for (char c : key) {
            asciiSum += c;
        }
        return (asciiSum * rollLastTwoDigits) % tableSize;
    }

public:
    SymbolTable(int rollDigits) : rollLastTwoDigits(rollDigits), tableSize(rollLastTwoDigits + 5) {
        table.resize(tableSize);
    }

    void insert(const string& symbol, const string& type) {
        int index = hashFunction(symbol);
        for (auto& item : table[index]) {
            if (item.symbol == symbol) {
                cout << "Failed: Symbol already exists at " << index << endl;
                return;
            }
        }
        table[index].emplace_back(symbol, type);
        cout << "Inserted at position " << index << "," << table[index].size() - 1 << endl;
    }

    void lookup(const string& symbol) {
        int index = hashFunction(symbol);
        int position = 0;
        for (auto& item : table[index]) {
            if (item.symbol == symbol) {
                cout << "Found at " << index << "," << position << endl;
                return;
            }
            position++;
        }
        cout << "Symbol not found." << endl;
    }

    void deleteSymbol(const string& symbol) {
        int index = hashFunction(symbol);
        auto& chain = table[index];
        for (auto it = chain.begin(); it != chain.end(); ++it) {
            if (it->symbol == symbol) {
                chain.erase(it);
                cout << "Deleted from " << index << endl;
                return;
            }
        }
        cout << "Symbol to delete not found." << endl;
    }

    void print() {
        for (int i = 0; i < tableSize; i++) {
            if (!table[i].empty()) {
                cout << i << " -->";
                for (auto& item : table[i]) {
                    cout << " <" << item.symbol << ", " << item.type << ">";
                }
                cout << endl;
            }
        }
    }
};

int main() {
    SymbolTable symTable(3);  // Adjust this to your roll number's last two digits.

    symTable.insert("KEYWORD", "IDENTIFIER");
    symTable.insert("main", "FUNCTION");
    symTable.insert("(", "LPAREN");
    symTable.insert(")", "RPAREN");
    symTable.insert("{", "LCURL");
    symTable.insert("}", "RCURL");
    symTable.print();
    symTable.lookup("main");
    symTable.deleteSymbol("KEYWORD");
    symTable.print();

    return 0;
}
