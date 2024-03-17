#include <bits/stdc++.h>
using namespace std;
// here we use rewrite on temp array and take to ele its right poistion
// if ele is greter then nothing to do simply push in last if less then
// find lower bound and replace it
int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
    vector<int> temp;
    temp.push_back(arr[0]);
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > temp.back())
        {
            temp.push_back(arr[i]);
        }
        else
        {
            int ind = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
            temp[ind] = arr[i];
        }
    }
    return temp.size();
}
int main()
{

    return 0;
}