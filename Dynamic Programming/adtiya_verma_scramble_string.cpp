// https://leetcode.com/problems/scramble-string/
#include <bits/stdc++.h>
using namespace std;
//**** recursive ***
class Solution
{
public:
    bool isScramble(string s1, string s2)
    {
        int n = s1.size();
        if (n != s2.size())
        {
            return false;
        }
        if (s1.compare(s2) == 0)
            return true;
        for (int i = 1; i < n; i++)
        {
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i, n - i), s2.substr(i, n - i)))
                return true;
            if (isScramble(s1.substr(0, i), s2.substr(n - i, i)) && isScramble(s1.substr(i, n - i), s2.substr(0, n - i)))
                return true;
        }
        return false;
    }
};
//**** memoization ****
class Solution
{
public:
    unordered_map<string, bool> mp;
    bool isScramble(string s1, string s2)
    {
        int n = s1.size();
        if (n != s2.size())
        {
            return false;
        }
        if (s1.compare(s2) == 0)
            return true;
        if (mp.find(s1 + " " + s2) != mp.end())
            return mp[s1 + " " + s2];
        for (int i = 1; i < n; i++)
        {
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i, n - i), s2.substr(i, n - i)))
                return mp[s1 + " " + s2] = true;
            if (isScramble(s1.substr(0, i), s2.substr(n - i, i)) && isScramble(s1.substr(i, n - i), s2.substr(0, n - i)))
                return mp[s1 + " " + s2] = true;
        }
        return mp[s1 + " " + s2] = false;
    }
};
//*****
int main()
{

    return 0;
}