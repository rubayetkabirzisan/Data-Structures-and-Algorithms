#include <iostream>
#include <cstring>
#include <ctime>

struct SkipListNode {
    int value;
    SkipListNode** forward;

    SkipListNode(int level, int value) {
        forward = new SkipListNode*[level + 1];
        memset(forward, 0, sizeof(SkipListNode*) * (level + 1));
        this->value = value;
    }

    ~SkipListNode() {
        delete[] forward;
    }
};

class SkipList {
    int maxLevel;
    float probability;
    int level;
    SkipListNode* header;

public:
    SkipList(int maxLevel, float probability) : maxLevel(maxLevel), probability(probability), level(1) {
        header = new SkipListNode(maxLevel, INT_MIN);
    }

    ~SkipList() {
        SkipListNode* current = header->forward[0];
        while (current != nullptr) {
            SkipListNode* temp = current;
            current = current->forward[0];
            delete temp;
        }
        delete header;
    }

    int randomLevel() {
        int level = 0;
        while (static_cast<float>(rand()) / RAND_MAX < probability && level < maxLevel)
            level++;
        return level;
    }

    void insert(int value) {
        SkipListNode* current = header;
        SkipListNode* update[maxLevel + 1];
        memset(update, 0, sizeof(SkipListNode*) * (maxLevel + 1));

        for (int i = level; i >= 0; i--) {
            while (current->forward[i] != nullptr && current->forward[i]->value < value)
                current = current->forward[i];
            update[i] = current;
        }

        current = current->forward[0];
        if (current == nullptr || current->value != value) {
            int newLevel = randomLevel();
            if (newLevel > level) {
                for (int i = level + 1; i <= newLevel; i++)
                    update[i] = header;
                level = newLevel;
            }
            SkipListNode* newNode = new SkipListNode(newLevel, value);
            for (int i = 0; i <= newLevel; i++) {
                newNode->forward[i] = update[i]->forward[i];
                update[i]->forward[i] = newNode;
            }
        }
    }

    bool search(int value) {
        SkipListNode* current = header;
        for (int i = level; i >= 0; i--) {
            while (current->forward[i] != nullptr && current->forward[i]->value < value)
                current = current->forward[i];
        }
        current = current->forward[0];
        return current != nullptr && current->value == value;
    }

    void remove(int value) {
        SkipListNode* current = header;
        SkipListNode* update[maxLevel + 1];
        memset(update, 0, sizeof(SkipListNode*) * (maxLevel + 1));

        for (int i = level; i >= 0; i--) {
            while (current->forward[i] != nullptr && current->forward[i]->value < value)
                current = current->forward[i];
            update[i] = current;
        }

        current = current->forward[0];
        if (current != nullptr && current->value == value) {
            for (int i = 0; i <= level; i++) {
                if (update[i]->forward[i] != current)
                    break;
                update[i]->forward[i] = current->forward[i];
            }
            delete current;
            while (level > 0 && header->forward[level] == nullptr)
                level--;
        }
    }

    void display() {
        std::cout << "Skip List: " << std::endl;
        SkipListNode* current = header->forward[0];
        while (current != nullptr) {
            std::cout << current->value << " ";
            current = current->forward[0];
        }
        std::cout << std::endl;
    }
};

int main() {
    srand(static_cast<unsigned int>(std::time(nullptr)));

    SkipList skipList(4, 0.5);

    skipList.insert(10);
    skipList.insert(5);
    skipList.insert(7);
    skipList.insert(12);
    skipList.insert(3);

    skipList.display();

    int searchValue = 7;
    bool found = skipList.search(searchValue);
    if (found)
        std::cout << "Element " << searchValue << " found in the Skip List." << std::endl;
    else
        std::cout << "Element " << searchValue << " not found in the Skip List." << std::endl;

    int removeValue = 5;
    skipList.remove(removeValue);
    std::cout << "Element " << removeValue << " removed from the Skip List." << std::endl;

    skipList.display();

    return 0;
}
