#include <iostream>
using namespace std;

#define MAX 100

class JobHeap {
public:
    int maxHeap[MAX];
    int minHeap[MAX];
    int size;

    JobHeap() { size = 0; }

    void insert(int priority);
    void maxHeapUp(int index);
    void minHeapUp(int index);
    void display();
    void deleteMax();
    void findMinMax();
};

void JobHeap::insert(int priority) {
    if (size == MAX) {
        cout << "Heap is full!" << endl;
        return;
    }
    size++;
    maxHeap[size] = priority;
    minHeap[size] = priority;
    maxHeapUp(size);
    minHeapUp(size);
    cout << "Job with priority " << priority << " inserted.\n";
}

void JobHeap::maxHeapUp(int index) {
    while (index > 1) {
        int parent = index / 2;
        if (maxHeap[parent] < maxHeap[index]) {
            swap(maxHeap[parent], maxHeap[index]);
            index = parent;
        } else break;
    }
}

void JobHeap::minHeapUp(int index) {
    while (index > 1) {
        int parent = index / 2;
        if (minHeap[parent] > minHeap[index]) {
            swap(minHeap[parent], minHeap[index]);
            index = parent;
        } else break;
    }
}

void JobHeap::findMinMax() {
    if (size == 0) {
        cout << "No jobs available.\n";
        return;
    }
    cout << "Highest Priority Job: " << maxHeap[1] << endl;
    cout << "Lowest Priority Job: " << minHeap[1] << endl;
}

void JobHeap::deleteMax() {
    if (size == 0) {
        cout << "No jobs to delete.\n";
        return;
    }

    cout << "Deleting job with highest priority: " << maxHeap[1] << endl;
    maxHeap[1] = maxHeap[size];
    size--;

    int i = 1;
    while (true) {
        int left = 2 * i;
        int right = 2 * i + 1;
        int largest = i;

        if (left <= size && maxHeap[left] > maxHeap[largest])
            largest = left;
        if (right <= size && maxHeap[right] > maxHeap[largest])
            largest = right;

        if (largest != i) {
            swap(maxHeap[i], maxHeap[largest]);
            i = largest;
        } else break;
    }
}

void JobHeap::display() {
    if (size == 0) {
        cout << "No jobs available.\n";
        return;
    }
    cout << "Jobs in Max Heap (Priority Order): ";
    for (int i = 1; i <= size; i++)
        cout << maxHeap[i] << " ";
    cout << endl;
}

int main() {
    JobHeap company;
    int ch, priority;

    while (true) {
        cout << "\n---- JOB PRIORITY MANAGEMENT ----\n";
        cout << "1. Insert a new job\n";
        cout << "2. Find Highest & Lowest Priority Job\n";
        cout << "3. Delete Highest Priority Job\n";
        cout << "4. Display All Jobs\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Enter job priority: ";
                cin >> priority;
                company.insert(priority);
                break;
            case 2:
                company.findMinMax();
                break;
            case 3:
                company.deleteMax();
                break;
            case 4:
                company.display();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}
