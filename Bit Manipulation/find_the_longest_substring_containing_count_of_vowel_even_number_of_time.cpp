// https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts

#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findTheLongestSubstring(string s)
    {
        unordered_map<char, int> mp;
        mp['a'] = 1, mp['e'] = 2, mp['i'] = 4, mp['o'] = 8, mp['u'] = 16;
        int mask = 0, maxlen = 0;
        vector<int> seen(32, -1);
        for (int i = 0; i < s.length(); i++)
        {
            int t = mp[s[i]];
            // cout<<t<<endl;
            mask = (mask ^ t);
            if (mask != 0 && seen[mask] == -1)
            {
                seen[mask] = i;
            }
            maxlen = max(maxlen, i - seen[mask]);
        }
        return maxlen;
    }
};
int main(){

return 0;
}