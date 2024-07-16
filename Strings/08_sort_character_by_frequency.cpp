// https://leetcode.com/problems/sort-characters-by-frequency/
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string frequencySort(string s)
    {
        unordered_map<char, int> mp;
        for (auto i : s)
            mp[i]++;
        priority_queue<pair<int, char>> pq;
        for (auto it : mp)
        {
            pq.push({it.second, it.first});
        }
        string ans = "";
        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            for (int i = 0; i < it.first; i++)
            {
                ans += it.second;
            }
        }
        return ans;
    }
};
int main(){

return 0;
}