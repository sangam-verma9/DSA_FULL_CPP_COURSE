// https://www.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int search(string pat, string txt)
    {
        unordered_map<char, int> mp;
        for (int i = 0; i < pat.length(); i++)
        {
            mp[pat[i]]++;
        }
        int ans = 0;
        int i = 0, j = 0;
        while (j <= txt.length())
        {
            while (j - i + 1 <= pat.length())
            {
                mp[txt[j]]--;
                if (mp[txt[j]] == 0)
                    mp.erase(txt[j]);
                j++;
            }
            if (mp.size() == 0)
                ans++;
            mp[txt[i]]++;
            if (mp[txt[i]] == 0)
                mp.erase(txt[i]);
            if (j < txt.length())
            {
                mp[txt[j]]--;
                if (mp[txt[j]] == 0)
                    mp.erase(txt[j]);
            }
            i++, j++;
        }
        return ans;
    }
};
int main() {

return 0;
}