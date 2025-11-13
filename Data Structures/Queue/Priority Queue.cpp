#include<bits/stdc++.h>
using namespace std;

class MaxPriorityQueue
{
private:
    int* heap;
    int capacity;
    int size;

    int parent(int i)
    {
        return (i - 1) / 2;
    }

    int leftChild(int i)
    {
        return 2 * i + 1;
    }

    int rightChild(int i)
    {
        return 2 * i + 2;
    }

    void maxHeapify(int i)
    {
        int left = leftChild(i);
        int right = rightChild(i);
        int largest = i;

        if (left < size && heap[left] > heap[largest])
        {
            largest = left;
        }

        if (right < size && heap[right] > heap[largest])
        {
            largest = right;
        }

        if (largest != i)
        {
            swap(heap[i], heap[largest]);
            maxHeapify(largest);
        }
    }

public:
    MaxPriorityQueue(int capacity)
    {
        this->capacity = capacity;
        heap = new int[capacity];
        size = 0;
    }

    ~MaxPriorityQueue()
    {
        delete[] heap;
    }

    void insert(int key)
    {
        if (size == capacity)
        {
            cout << "Queue is full. Cannot insert." << endl;
            return;
        }

        size++;
        int i = size - 1;
        heap[i] = key;

        while (i > 0 && heap[parent(i)] < heap[i])
        {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    int maximum()
    {
        if (size > 0)
        {
            return heap[0];
        }
        // You can return an error code or handle this case as needed.
        return numeric_limits<int>::min(); // Assuming minimum integer value as an error indicator.
    }

    int extractMax()
    {
        if (size == 0)
        {
            // You can return an error code or handle this case as needed.
            return numeric_limits<int>::min(); // Assuming minimum integer value as an error indicator.
        }

        int max = heap[0];
        heap[0] = heap[size - 1];
        size--;
        maxHeapify(0);
        return max;
    }

    void increaseKey(int i, int newKey)
    {
        if (i < 0 || i >= size || newKey <= heap[i])
        {
            // Handle invalid index or newKey not greater than or equal to current key.
            return;
        }

        heap[i] = newKey;
        while (i > 0 && heap[parent(i)] < heap[i])
        {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }
};

int main()
{
    MaxPriorityQueue pq(100); // Specify the capacity when creating the queue.

    pq.insert(4);
    pq.insert(7);
    pq.insert(2);

    cout << "Maximum: " << pq.maximum() << endl;
    cout << "Extracted Max: " << pq.extractMax() << endl;

    pq.increaseKey(1, 10);

    cout << "Maximum after increasing key: " << pq.maximum() << endl;

    return 0;
}
