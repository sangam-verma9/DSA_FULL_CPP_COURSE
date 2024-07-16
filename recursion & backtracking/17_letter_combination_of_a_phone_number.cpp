// https://leetcode.com/problems/letter-combinations-of-a-phone-number/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void solve(int ind, int n, string &digits, map<char, string> &m, string s, vector<string> &ans)
    {
        if (ind == n)
        {
            ans.push_back(s);
            return;
        }
        for (auto it : m[digits[ind]])
        {
            s.push_back(it);
            solve(ind + 1, n, digits, m, s, ans);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits)
    {
        int n = digits.length();
        map<char, string> m = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
        vector<string> ans;
        if (digits.length() == 0)
            return ans;
        string s;
        solve(0, n, digits, m, s, ans);
        return ans;
    }
};
int main()
{

    return 0;
}