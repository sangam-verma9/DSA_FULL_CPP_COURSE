// https://leetcode.com/problems/minimum-window-substring
#include <bits/stdc++.h>
using namespace std;
// first solution
class Solution
{
public:
    string minWindow(string s, string t)
    {
        int i = 0, j = 0;
        unordered_map<char, int> mp;
        int cnt = 0;
        for (int i = 0; i < t.length(); i++)
            mp[t[i]]++;
        cnt = mp.size();
        int len = INT_MAX;
        string ans = "";
        while (j < s.length())
        {
            mp[s[j]]--;
            if (mp[s[j]] == 0)
                cnt--;
            if (cnt > 0)
            {
                j++;
            }
            else
            {
                while (cnt == 0)
                {
                    int l = j - i + 1;
                    if (l < len)
                    {
                        len = l;
                        ans = s.substr(i, l);
                    }
                    mp[s[i]]++;
                    if (mp[s[i]] == 1)
                        cnt++;
                    i++;
                }
                j++;
            }
        }
        return ans;
    }
};

// second solution
int main()
{

    return 0;
}