#include <iostream>
#include <queue>
using namespace std;
// greater elements is at the top and if you pop the top element then greater element will automatically comes to top
int main()
{
    priority_queue<int> pq; // max heap

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
