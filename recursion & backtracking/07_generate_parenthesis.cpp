// https://leetcode.com/problems/generate-parentheses
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void solve(int open, int close, string s, vector<string> &ans)
    {
        if (open == 0 && close == 0)
        {
            ans.push_back(s);
            return;
        }
        if (open > 0)
        {
            s.push_back('(');
            solve(open - 1, close, s, ans);
            s.pop_back();
        }
        if (close > 0)
        {
            if (open < close)
            {
                s.push_back(')');
                solve(open, close - 1, s, ans);
                s.pop_back();
            }
        }
    }
    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        string s = "";
        int open = n, close = n;
        solve(open, close, s, ans);
        return ans;
    }
};
int main()
{

    return 0;
}