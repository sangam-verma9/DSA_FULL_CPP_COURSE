// https://www.geeksforgeeks.org/problems/shortest-job-first/1
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long solve(vector<int> &bt)
    {
        sort(bt.begin(), bt.end());
        long long sum = 0;
        long long prev = 0;
        for (auto i : bt)
        {
            sum += prev;
            prev += i;
        }
        return sum / bt.size();
    }
};
int main()
{

    return 0;
}