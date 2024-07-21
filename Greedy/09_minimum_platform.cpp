// https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findPlatform(int arr[], int dep[], int n)
    {
        vector<pair<int, char>> v;
        for (int i = 0; i < n; i++)
        {
            v.push_back({arr[i], 'A'});
        }
        for (int i = 0; i < n; i++)
        {
            v.push_back({dep[i], 'D'});
        }
        sort(v.begin(), v.end());
        int cnt = 0;
        int ans = 0;
        for (auto it : v)
        {
            if (it.second == 'A')
                cnt++;
            else
                cnt--;
            ans = max(ans, cnt);
        }
        return ans;
    }
};
//***** you can also do this ques by sorting arrays individually
// and take two pointers on each array and move according to time and take maximum count
int main()
{

    return 0;
}