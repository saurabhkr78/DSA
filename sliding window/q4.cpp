// Maximum of all subarrays of size k/Sliding Window Maximum

/*
Gist of the logic:-

1.	We have to create such a data structure which is open from both the sides, so that we can push and pop elements from any corner, and list is one such data structure. The first element of the list will contain maximum value of current window, the subsequent elements in the list are the candidate or possible maximum values for subsequent or future windows.

2.	For jth value calculation- if the list is empty at first, then whatever comes first in the array will be pushed as maximum value in the list. In the list we need to store only those values which can become candidate maximum values for next sliding windows. So comparing jth value with the back of the list, if it comes out to be greater than the back of the list, then the back of the list becomes unused, as they can never become maximum value for future windows, so all these values which are less than the jth value needs to be deleted. If the jth value is less than the back of the list, it might not serve as the maximum value for the current window, but it can serve as the maximum value for future windows, so we need to preserve this, pushing them into the list for future use.

3.	For retrieving the answer- the max value for the current window is always available at the front of the list, because all the values which are less than this value are deleted from the list, so the maximum value always occupies the first place in the list.

4.	For sliding the window-   before moving i and j iterators, we need to check whether the ith value belongs to the list or not. And it happens to belong to the list only if it has served as the maximum value for current window. If it hasn’t served as the max value, then there’s no chance that it can be found in the list. So deleting the front element of the list if it equals to ith value. Then i++ and j++.
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {1, 3, -1, -3, 5, 3, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int i = 0, j = 0;
    int k = 3;
    vector<int> v;
    while (j < n)
    {
        list<int> l;
        l.push_back(arr[j]);

        while (l.size() > 0 and l.back() < arr[j])
        {

            l.pop_back();
        }
        l.push_back(arr[j]);

        // calculation
        if (j - i + 1 < k)
            j++;

        else if (j - i + 1 == k)
        {
            // result from above calculation
            v.push_back(l.front());

            // remove arr[i];

            if (arr[i] == l.front())
                l.pop_front();

            i++;
            j++;
        }
    }
    for(auto it:v)
    cout<<it<<" ";

    return 0;
}