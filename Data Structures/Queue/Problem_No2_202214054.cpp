#include<bits/stdc++.h>
using namespace std;

class Vertex
{
public:
    int key;
    int value;

    Vertex(int k, int v) : key(k), value(v) {}
};

class PriorityQueue
{
private:
    vector<Vertex> heap;
    int size;

public:
    PriorityQueue()
    {
        size = 0;
    }

private:
    void bottomTopAdjust(int i)
    {
        while (i != 0)
        {
            int parent = (i - 1) / 2;
            if (heap[i].key > heap[parent].key)
            {
                swap(heap[i], heap[parent]);
                i = parent;
            }
            else
            {
                break;
            }
        }
    }

    void topBottomAdjust(int i)
    {
        int maxIdx = i;
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;

        if (leftChild < size && heap[leftChild].key > heap[maxIdx].key)
        {
            maxIdx = leftChild;
        }
        if (rightChild < size && heap[rightChild].key > heap[maxIdx].key)
        {
            maxIdx = rightChild;
        }

        if (maxIdx != i)
        {
            swap(heap[i], heap[maxIdx]);
            topBottomAdjust(maxIdx);
        }
    }

public:
    void insert(int key, int value)
    {
        heap.push_back(Vertex(key, value));
        size++;
        bottomTopAdjust(size - 1);
    }

    bool increaseKey(int index, int newKey)
    {
        if (index < 0 || index >= size || newKey <= heap[index].key)
        {
            return false;
        }
        heap[index].key = newKey;
        bottomTopAdjust(index);
        return true;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    Vertex extractMax()
    {
        if (isEmpty())
        {
            return Vertex(-1, -1);
        }
        Vertex maxVertex = heap[0];
        heap[0] = heap[size - 1];
        size--;
        topBottomAdjust(0);
        return maxVertex;
    }
};

int main()
{
    PriorityQueue pq;

    while (1)
    {
        cout << "1. Insert    2. Increase Key    3. Extract Max    4. End" << endl << endl;
        int choice;
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter Key and Value: ";
            int key, value;
            cin >> key >> value;
            pq.insert(key, value);
            cout << "Vertex (" << key << ", " << value << ") inserted into the priority queue." << endl;
        }
        else if (choice == 2)
        {
            cout << "Enter Index and New Key: ";
            int index, newKey;
            cin >> index >> newKey;
            bool success = pq.increaseKey(index, newKey);
            if (success)
            {
                cout << "Key increased successfully!" << endl;
            }
            else
            {
                cout << "Invalid operation." << endl;
            }
        }
        else if (choice == 3)
        {
            if (!pq.isEmpty())
            {
                Vertex maxVertex = pq.extractMax();
                cout << "Max Vertex: (" << maxVertex.key << ", " << maxVertex.value << ")" << endl;
            }
            else
            {
                cout << "Priority queue is empty." << endl;
            }
        }
        else if (choice == 4)
        {
            break;
        }
        else
        {
            cout << "Invalid Choice" << endl;
        }
        cout << endl;
    }
}
