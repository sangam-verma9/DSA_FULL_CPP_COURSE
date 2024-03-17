// https://leetcode.com/problems/longest-repeating-character-replacement
#include <bits/stdc++.h>
using namespace std;
//***** method - 1
class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int n = s.size();
        int i = 0, j = 0;
        int cnt = 0;
        int sum = 0, maxi = 0, temp = 0;
        vector<int> freq(26, 0);
        while (j < n)
        {
            freq[s[j] - 'A']++;
            sum++;
            maxi = *max_element(freq.begin(), freq.end());
            temp = sum - maxi;
            if (temp <= k)
            {
                cnt = max(cnt, j - i + 1);
            }
            else
            {
                while (temp > k)
                {
                    freq[s[i] - 'A']--;
                    i++;
                    sum--;
                    maxi = *max_element(freq.begin(), freq.end());
                    temp = sum - maxi;
                }
            }
            j++;
        }
        return cnt;
    }
};
//*****
int main()
{

    return 0;
}