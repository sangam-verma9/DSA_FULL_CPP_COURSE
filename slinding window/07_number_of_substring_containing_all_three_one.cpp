// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        int n = s.length();
        int ans = 0;
        int i = 0, j = 0;
        unordered_map<char, int> mp;
        while (j < n)
        {
            mp[s[j]]++;
            if (mp.size() < 3)
            {
                j++;
                continue;
            }
            if (mp.size() == 3)
            {
                while (mp.size() > 2)
                {
                    mp[s[i]]--;
                    ans += (n - j);     // main logic
                    if (mp[s[i]] == 0)
                        mp.erase(s[i]);
                    i++;
                }
            }
            j++;
        }
        return ans;
    }
};


// second method
int countSubstring(string s)
{
    // Initialising 'ans' to 0.
    int ans = 0;
    int n = s.size();

    // Initialising index of last occurrence of each character to '-1'.
    int aIdx = -1, bIdx = -1, cIdx = -1;
    for (int i = 0; i < n; i++)
    {

        // Updating the index of last occurrence of each character.
        if (s[i] == 'a')
        {
            aIdx = i;
        }
        else if (s[i] == 'b')
        {
            bIdx = i;
        }
        else if (s[i] == 'c')
        {
            cIdx = i;
        }

        int minIdx = min(aIdx, min(bIdx, cIdx));

        // Adding count of all valid substrings.
        ans = ans + (minIdx + 1);
    }
    return ans;
}

int main(){

return 0;
}