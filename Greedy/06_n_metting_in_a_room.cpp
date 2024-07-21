// https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    static bool comp(pair<int, int> &a, pair<int, int> &b)
    {
        return a.second < b.second;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
        {
            v.push_back({start[i], end[i]});
        }
        sort(v.begin(), v.end(), comp);
        int curr = -1;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (v[i].first > curr)
            {
                curr = v[i].second;
                cnt++;
            }
        }
        return cnt;
    }
};
int main()
{

    return 0;
}