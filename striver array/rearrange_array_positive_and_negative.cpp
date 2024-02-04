// https://www.codingninjas.com/studio/problems/alternate-numbers_6783445
#include<bits/stdc++.h>
using namespace std;
vector<int> alternateNumbers(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n);
    int posi = 0, negi = 1;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] > 0)
        {
            ans[posi] = nums[i];
            posi += 2;
        }
        else
        {
            ans[negi] = nums[i];
            negi += 2;
        }
    }
    return ans;
}
int main() {

return 0;
}