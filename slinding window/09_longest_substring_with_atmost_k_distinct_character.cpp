// https://www.codingninjas.com/studio/problems/longest-substring-with-at-most-k-distinct-characters_2221410
#include<bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
int kDistinctChars(int k, string &str)
{
    int i = 0, j = 0;
    int ans = 0;
    unordered_map<char, int> mp;
    while (j < str.length())
    {
        mp[str[j]]++;
        if (mp.size() <= k)
        {
            ans = max(ans, j - i + 1);
        }
        else
        {
            while (mp.size() > k)
            {
                mp[str[i]]--;
                if (mp[str[i]] == 0)
                    mp.erase(str[i]);
                i++;
            }
        }
        j++;
    }
    return ans;
}

int main(){

return 0;
}