// https://leetcode.com/problems/valid-parenthesis-string
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int n;
    int dp[101][100];
    int f(int i, int balance, string &s)
    {
        if (i == n)
            return balance == 0;
        if (dp[i][balance] != -1)
            return dp[i][balance];
        int ans = 0;
        switch (s[i])
        {
        case '(':
            ans = f(i + 1, balance + 1, s);
            break;
        case ')':
            if (balance > 0)
                ans = f(i + 1, balance - 1, s);
            break;
        case '*':
            ans |= f(i + 1, balance + 1, s) || f(i + 1, balance, s);
            if (balance > 0)
                ans |= f(i + 1, balance - 1, s);
        }
        return dp[i][balance] = ans;
    }
    bool checkValidString(string &s)
    {
        n = s.size();
        memset(dp, -1, sizeof(dp));
        return f(0, 0, s) == 1;
    }
};

// optimized approach (striver's approach) make a range of possibilities
// and at the end check minrange 0 or not
class Solution
{
public:
    bool checkValidString(string s)
    {
        int mini = 0, maxi = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                mini += 1;
                maxi += 1;
            }
            else if (s[i] == ')')
            {
                mini -= 1;
                maxi -= 1;
            }
            else
            {
                mini -= 1;
                maxi += 1;
            }
            if (mini < 0)
                mini = 0;
            if (maxi < 0)
                return false;
        }
        return mini == 0;
    }
};
int main(){

return 0;
}