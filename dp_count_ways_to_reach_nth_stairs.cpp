#include <bits/stdc++.h>
using namespace std;

//******** recusive normal approach
int solve(int i, int nStairs)
{
    if (i == nStairs)
    {
        return 1;
    }
    if (i > nStairs)
        return 0;

    return solve(i + 1, nStairs) + solve(i + 2, nStairs);
}
int countDistinctWays(int nStairs)
{
    //  Write your code here.
    int ans = solve(0, nStairs);
    return ans;
}
//********
int main()
{

    return 0;
}