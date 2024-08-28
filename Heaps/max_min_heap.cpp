#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    priority_queue<int> maxHeap; // Max-heap priority queue
    maxHeap.push(10);
    maxHeap.push(30);
    maxHeap.push(20);

    cout << "Max-heap priority queue: ";
    while (!maxHeap.empty()) {
        cout << maxHeap.top() << " ";
        maxHeap.pop();
    }
    cout << endl;

    priority_queue<int, vector<int>, greater<int>> minHeap; // Min-heap priority queue
    minHeap.push(10);
    minHeap.push(30);
    minHeap.push(20);

    cout << "Min-heap priority queue: ";
    while (!minHeap.empty()) {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
    cout << endl;

    return 0;
}
