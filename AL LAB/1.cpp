//283. Move Zeroes

#include <bits/stdc++.h>
using namespace std;

void solve(int arr[], int n)
{
 int index = 0; // This will keep track of where the non-zero element should go

    // Traverse the array and push all non-zero elements to the front
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            arr[index++] = arr[i];
        }
    }

    // Fill the rest of the array with zeros
    while (index < n)
    {
        arr[index++] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

// {
//     for(int i=0;i<n;i++){
//     int nzidx=0;
//     if(arr[i]!=0){
//         swap(arr[i],nzidx);
//         nzidx++;
//     }
// }
// }
int main()
{
    int arr[] = {0, 1, 0, 2, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    solve(arr, n);

    return 0;
}