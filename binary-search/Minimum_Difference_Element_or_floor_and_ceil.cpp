#include<iostream>
#include<cmath>
using namespace std;
//Minimum difference element in a sorted array
int BinarySearch(int arr[],int n,int k)
{
	int start=0;
	int end=n-1;
	int mid;
	while(start<=end)
	{
		mid = start + (end-start)/2;
		if(arr[mid]==k)
		return 0;
		else if(arr[mid]>k)
		end = mid-1;
		else
		start = mid+1;
    }

    int min1=abs(arr[start]-k);
    int min2=abs(arr[end]-k);
    if(min1>min2)
    return min2;
    else
    return min1;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int i,n;
		cin>>n;
		int arr[n];
		for(i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		int key;
		cin>>key;
		int res=BinarySearch(arr,n,key);
		cout<<res<<endl;
	}
}