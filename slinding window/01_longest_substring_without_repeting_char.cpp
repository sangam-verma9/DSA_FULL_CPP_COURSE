// https://leetcode.com/problems/longest-substring-without-repeating-characters
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int ans = 0;
        int i = 0, j = 0;
        unordered_map<char, int> mp;
        int cnt = 0;
        while (j < s.length())
        {
            mp[s[j]]++;
            cnt++;
            if (cnt == mp.size())
            {
                ans = max(cnt, ans);
                j++;
            }
            else
            {
                while (cnt > mp.size())
                {
                    mp[s[i]]--;
                    cnt--;
                    if (mp[s[i]] == 0)
                        mp.erase(s[i]);
                    i++;
                }
                if (cnt == mp.size())
                    ans = max(cnt, ans);
                j++;
            }
        }
        return ans;
    }
};

//**** second solution ***
int lengthOfLongestSubstring(string s)
{
    unordered_map<char, int> mp;
    int len = s.length();
    int i = 0, j = 0;
    int cnt = 0;
    while (j < len)
    {
        if (mp[s[j]] == 0)
        {
            mp[s[j]]++;
            cnt = max(cnt, j - i + 1);
            j++;
        }
        else
        {
            while (mp[s[j]] > 0)
            {
                mp[s[i]]--;
                i++;
            }
        }
    }
    return cnt;
}
int main()
{

    return 0;
}