
/*
Gist of the logic used for first -ve in every window size of k

1. We're creating a list to store all the negative elements of a current window. At a particular point of time, the list holds negative numbers which are there in the current running window and not all the negative elements in the array. So, that we can retrieve first negative number from the current window.
2. When we reached the window size, we need to perform two operations:-
-> First, we have to retrieve the answer that is the first negative number from the current window. We're checking if the list is empty or not. If it is empty, then there is no negative number in the current window. In that case we'll push 0 in the vector.
If it's not empty, then the first element in the list is the first negative number of the current window., pushing that into the vector.
-> Second, we need to slide the window. For that we need to remove the first element of the current window, and add the next element from the array to the window. But before removing the first element, we need to check whether it belongs to the list or not. If it belongs to the list, we need to remove it from the list, as it will not be a part of our next window. So, if the first element is found to be a negative number, then we have to remove it from the list, and this number is happened to be the front element of the list. Then, incrementing the values of i and j to slide the window.
*/

#include <bits/stdc++.h>

using namespace std;

vector<int> printFirstNegativeInteger(int arr[], int size, int windowSize)
{
    int i = 0, j = 0;
    deque<int> deq;
    vector<int> vec;

    while (j < size)
    {
        if (arr[j] < 0)
        {
            deq.push_back(arr[j]);
        }
        if (j - i + 1 < windowSize)
        {
            j++;
        }
        else if (j - i + 1 == windowSize)
        {
            if (deq.empty())
            {
                vec.push_back(0);
            }
            else
            {
                vec.push_back(deq.front());
                if (arr[i] == deq.front())
                {
                    deq.pop_front();
                }
            }
            i++;
            j++;
        }
    }

    return vec;
}

int main()
{
    int arr[] = {12, -1, -7, 8, -15, 30, 16, 28};
    int size = sizeof(arr) / sizeof(arr[0]);
    int windowSize = 3;

    vector<int> result = printFirstNegativeInteger(arr, size, windowSize);

    for (int num : result)
    {
        cout << num << " ";
    }

    return 0;
}
