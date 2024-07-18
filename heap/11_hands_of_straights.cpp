// https://leetcode.com/problems/hand-of-straights/
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isNStraightHand(vector<int> &hand, int gs)
    {
        int n = hand.size();
        if (n % gs != 0)
            return false;
        map<int, int> mp;
        for (auto i : hand)
            mp[i]++;
        // int curr=mp.begin()->first;
        while (mp.size() > 0)
        {
            int curr = mp.begin()->first;
            mp[curr]--;
            if (mp[curr] == 0)
                mp.erase(curr);
            for (int i = 1; i < gs; i++)
            {
                if (mp[curr + i] >= 1)
                {
                    mp[curr + i]--;
                    if (mp[curr + i] == 0)
                        mp.erase(curr + i);
                    continue;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};
int main(){

return 0;
}