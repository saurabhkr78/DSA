#include <iostream>
#include <queue>
#include <vector>
// min elements is at the top and if you pop the top element then smallest element will automatically comes to top
using namespace std;

int main()
{
    // to create a min-heap
    priority_queue<int, vector<int>, greater<int>> pq;

    // Inserting elements into the priority queue
    pq.push(5);
    pq.push(4);
    pq.push(1);
    pq.push(9);
    pq.push(2);

    // Printing and removing elements from the priority queue
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;

    return 0;
}
// using preprocessor directive
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Define a macro for a min-heap priority queue
#define MIN_HEAP priority_queue<int, vector<int>, greater<int>>

int main()
{
    // Use the macro to create a min-heap priority queue
    MIN_HEAP pq;

    // Inserting elements into the priority queue
    pq.push(5);
    pq.push(4);
    pq.push(1);
    pq.push(9);
    pq.push(2);

    // Printing and removing elements from the priority queue
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;

    return 0;
}
