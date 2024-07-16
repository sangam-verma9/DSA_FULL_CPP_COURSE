// https://leetcode.com/problems/palindrome-partitioning
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<string>> ans;
    bool isPalindrome(int i, int j, string &s)
    {
        while (i <= j)
        {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    void solve(string &s, int n1, int n2, vector<string> temp)
    {
        if (n1 == 0)
        {
            if (isPalindrome(n1, n2, s))
            {
                temp.push_back(s.substr(n1, n2 - n1 + 1));
                reverse(temp.begin(), temp.end());
                ans.push_back(temp);
            }
            return;
        }
        if (n1 >= 0 && n2 >= 0 && isPalindrome(n1, n2, s))
        {
            temp.push_back(s.substr(n1, n2 - n1 + 1));
            solve(s, n1 - 1, n1 - 1, temp);
            temp.pop_back();
            solve(s, n1 - 1, n2, temp);
        }
        else
        {
            solve(s, n1 - 1, n2, temp);
        }
    }
    vector<vector<string>> partition(string s)
    {
        vector<string> temp;
        solve(s, s.length() - 1, s.length() - 1, temp);
        return ans;
    }
};
int main()
{

    return 0;
}