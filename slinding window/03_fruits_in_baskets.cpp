// https://www.codingninjas.com/studio/problems/fruits-and-baskets_985356
#include <bits/stdc++.h>
using namespace std;
int findMaxFruits(vector<int> &arr, int n)
{
    int ans = 0;
    unordered_map<int, int> mp;
    int i = 0, j = 0;
    while (j < n)
    {
        mp[arr[j]]++;
        j++;
        if (mp.size() <= 2)
        {
            ans = max(ans, j - i);
            continue;
        }
        while (mp.size() > 2)
        {
            mp[arr[i]]--;
            if (mp[arr[i]] == 0)
            {
                mp.erase(arr[i]);
            }
            i++;
        }
    }
    return ans;
}
int main()
{

    return 0;
}