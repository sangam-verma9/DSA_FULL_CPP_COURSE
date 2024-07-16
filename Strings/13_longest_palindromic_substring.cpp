// https://leetcode.com/problems/longest-palindromic-substring
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string expand_from_center(int left, int right, string &s)
    {
        while (left >= 0 && right < s.length() && s[left] == s[right])
        {
            left--, right++;
        }
        return s.substr(left + 1, right - left - 1);
    }
    string longestPalindrome(string s)
    {
        if (s.length() <= 1)
            return s;
        string ans = s.substr(0, 1);
        for (int i = 0; i < s.length() - 1; i++)
        {
            string odd = expand_from_center(i, i, s);
            string even = expand_from_center(i, i + 1, s);
            if (odd.length() > ans.length())
            {
                ans = odd;
            }
            if (even.length() > ans.length())
            {
                ans = even;
            }
        }
        return ans;
    }
};
int main(){

return 0;
}