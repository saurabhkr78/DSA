/*#three approaches  to solve DP
1.Recursive approach
2.Memoization
3.top-down approach

//identification of DP problem
1.coices are given whether to selct or not\
2.optimal is being asked like greatest,max,min,largest.

//Recursive approach
1.ip/op
2.choice diagram
3.base condition
4.max/min etc profit return */

#include <bits/stdc++.h>
using namespace std;

int knapsack(int wt[], int val[], int BagCapacity, int size)
{
    // base case
    if (size == 0 or BagCapacity == 0)
        return 0;
    if (wt[size - 1] <= BagCapacity)
        /*
        If the weight of the current item (wt[size-1]) is less than or equal to the remaining BagCapacity, you have two choices:
        1.Include the item and add its value (val[size-1]) to the result while reducing the BagCapacity by its weight.
        2.Exclude the item and move to the next item
        */
        return max(val[size - 1] + knapsack(wt, val, BagCapacity - wt[size - 1], size - 1), knapsack(wt, val, BagCapacity, size - 1));
    // Excluding the Item:
    else if (wt[size - 1] > BagCapacity)
        return knapsack(wt, val, BagCapacity, size - 1);
}
int main()
{
    int wt[] = {1, 3, 4, 5};
    int val[] = {1, 4, 5, 7};
    int BagCapacity = 7;
    int size = sizeof(wt) / sizeof(wt[0]);

    cout << "Maximum value in knapsack: " << knapsack(wt, val, BagCapacity, size);
}
// to optimize this solution we do memoization
