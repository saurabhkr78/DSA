// if clsoe >open then we get a choice of closing bracket but why? because extra open is being used mean opne count<close count so we will have closing choice
class Solution
{
public:
    void solve(int open, int close, string output, vector<string> &v)
    {
        if (open == 0 && close == 0)
        {
            v.push_back(output);
            return;
        }

        // Add open parenthesis if available
        if (open > 0)
        {
            solve(open - 1, close, output + "(", v);
        }

        // Add close parenthesis only if there are more close ones left than open ones
        if (close > open)
        {
            solve(open, close - 1, output + ")", v);
        }
    }

    vector<string> generateParenthesis(int n)
    {
        vector<string> v;
        string output = "";
        solve(n, n, output, v);
        return v;
    }
};
