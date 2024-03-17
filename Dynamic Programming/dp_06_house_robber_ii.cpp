// https://www.codingninjas.com/studio/problems/house-robber-ii_839733?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
#include <bits/stdc++.h>
using namespace std;
long long int solve(vector<int> &nums)
{
    int n = nums.size();
    long long int prev1 = nums[0];
    long long int prev2 = 0;

    for (int i = 1; i < n; i++)
    {
        long long int include = nums[i] + prev2;
        long long int exclude = prev1 + 0;
        long long int curr = max(include, exclude);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
long long int houseRobber(vector<int> &valueInHouse)
{
    // Write your code here.
    int n = valueInHouse.size();
    if (n == 1)
    {
        return valueInHouse[0];
    }
    vector<int> first, second;
    for (int i = 0; i < n; i++)
    {
        if (i != n - 1)
        {
            first.push_back(valueInHouse[i]);
        }
        if (i != 0)
        {
            second.push_back(valueInHouse[i]);
        }
    }
    return max(solve(first), solve(second));
}
int main()
{

    return 0;
}