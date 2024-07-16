// https://leetcode.com/problems/create-sorted-array-through-instructions
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int bit[100001];
    void update(int x)
    {
        while (x < 100001)
        {
            bit[x]++;
            x += (x & (-x));
        }
    }
    int get(int x)
    {
        int res = 0;
        while (x > 0)
        {
            res += bit[x];
            x -= (x & (-x));
        }
        return res;
    }
    int createSortedArray(vector<int> &instructions)
    {
        memset(bit, 0, sizeof(bit));
        int res = 0, n = instructions.size(), mod = 1e9 + 7;
        for (int i = 0; i < n; i++)
        {
            res = (res + min(get(instructions[i] - 1), i - get(instructions[i]))) % mod;
            update(instructions[i]);
        }
        return res;
    }
};
int main(){

return 0;
}