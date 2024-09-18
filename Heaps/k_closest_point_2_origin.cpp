class Solution
{
public:
    typedef pair<int, pair<int, int>> pp;
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        int n = points.size();
        priority_queue<pp> pq;
        for (int i = 0; i < n; i++)
        {
            int d = (points[i][0] * points[i][0] + points[i][1] * points[i][1]);
            pq.push({d, {points[i][0], points[i][1]}});
            if (pq.size() > k)
            {
                pq.pop();
            }
        }
        vector<vector<int>> res;
        while (!pq.empty())
        {
            res.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();
        }
        return res;
    }
};