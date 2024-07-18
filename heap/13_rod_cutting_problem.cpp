// https://www.geeksforgeeks.org/problems/rod-cutting0840/1
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int cutRod(int price[], int n)
    {
        vector<int> prev(n + 1, 0);
        vector<int> curr(n + 1, 0);
        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int len = 0; len <= n; len++)
            {
                int op1 = prev[len];
                int op2 = 0;
                if (len >= ind + 1)
                {
                    op2 = price[ind] + curr[len - ind - 1];
                }
                curr[len] = max(op1, op2);
            }
            prev = curr;
        }
        return curr[n];
    }
};
int main()
{

    return 0;
}