// https://leetcode.com/problems/sum-of-beauty-of-all-substrings/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int beautySum(string s)
    {
        int ans = 0;
        for (int i = 0; i < s.length(); i++)
        {
            vector<int> freq(26, 0);
            for (int j = i; j < s.length(); j++)
            {
                freq[s[j] - 'a']++;
                int maxi = INT_MIN, mini = INT_MAX;
                for (int k = 0; k < 26; k++)
                {
                    if (freq[k] != 0)
                    {
                        maxi = max(maxi, freq[k]);
                        mini = min(mini, freq[k]);
                    }
                }
                ans += maxi - mini;
            }
        }
        return ans;
    }
};
int main()
{

    return 0;
}