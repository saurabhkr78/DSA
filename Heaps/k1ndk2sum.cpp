class Solution
{
public:
    long long kthSmallest(long long a[], long long n, int k)
    {
        // code here
        priority_queue<long long> maxh;
        for (int i = 0; i < n; i++)
        {
            maxh.push(a[i]);
            if (maxh.size() > k)
                maxh.pop();
        }
        return maxh.top();
    }
    long long sumBetweenTwoKth(long long a[], long long n, long long k1, long long k2)
    {
        // Your code goes here
        long long ax = kthSmallest(a, n, k1);
        long long by = kthSmallest(a, n, k2);
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] > ax && a[i] < by)
                ans += a[i];
        }
        return ans;
    }
};