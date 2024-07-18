// https://leetcode.com/problems/task-scheduler
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        unordered_map<char, int> mp;
        for (auto i : tasks)
        {
            mp[i]++;
        }
        priority_queue<pair<int, char>> pq;
        for (auto i : mp)
        {
            pq.push({i.second, i.first});
        }
        int time = 0;
        for (auto i : mp)
            mp[i.first] = 0;
        vector<pair<int, char>> temp;
        while (!pq.empty())
        {
            time++;
            if (mp[pq.top().second] == 0)
            {
                int f = pq.top().first;
                char ch = pq.top().second;
                pq.pop();
                if (f > 1)
                {
                    auto p = make_pair(f - 1, ch);
                    pq.push(p);
                    mp[ch] = time;
                }
            }
            else
            {
                while (!pq.empty() && time - mp[pq.top().second] <= n && mp[pq.top().second] != 0)
                {
                    temp.push_back(pq.top());
                    pq.pop();
                }
                if (!pq.empty())
                {
                    int f = pq.top().first;
                    char ch = pq.top().second;
                    pq.pop();
                    if (f > 1)
                    {
                        auto p = make_pair(f - 1, ch);
                        pq.push(p);
                        mp[ch] = time;
                    }
                }
                for (auto it : temp)
                {
                    pq.push(it);
                }
                temp.clear();
            }
        }
        return time;
    }
};
// optimized approach
class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        int freq[26] = {0};
        for (char task : tasks)
        {
            freq[task - 'A']++;
        }
        sort(begin(freq), end(freq));
        int chunk = freq[25] - 1;
        int idel = chunk * n;

        for (int i = 24; i >= 0; i--)
        {
            idel -= min(chunk, freq[i]);
        }

        return idel < 0 ? tasks.size() : tasks.size() + idel;
    }
};
int main(){

return 0;
}