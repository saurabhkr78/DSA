class Solution
{
public:
    char nextGreatestLetter(vector<char> &arr, char x)
    {
        int n = arr.size();
        int i = 0, j = n - 1;
        char res = arr[0]; // Initialize to the first element (in case x is larger than the largest element)

        while (i <= j)
        {
            int mid = i + (j - i) / 2;

            if (arr[mid] > x)
            { // Candidate for the next greater element
                res = arr[mid];
                j = mid - 1; // Move left to find a smaller candidate
            }
            else
            {
                i = mid + 1; // Move right to find a larger element
            }
        }

        return res;
    }
};
