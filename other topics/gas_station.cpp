// https://leetcode.com/problems/gas-station/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int n = gas.size();
        long long tgas = 0, tcost = 0;
        for (int i = 0; i < n; i++)
        {
            tgas += gas[i];
            tcost += cost[i];
        }
        if (tcost > tgas)
            return -1;
        for (int ind; ind < n; ind++)
        {
            int petrol = 0;
            bool f = true;
            int j;
            for (j = ind; j < n; j++)
            {
                petrol += gas[j];
                if (cost[j] > petrol)
                {
                    f = false;
                    ind = j;
                    break;
                }
                petrol -= cost[j];
            }
            if (j == n && f)
                return ind;
        }
        return -1;
    }
};
int main()
{

    return 0;
}