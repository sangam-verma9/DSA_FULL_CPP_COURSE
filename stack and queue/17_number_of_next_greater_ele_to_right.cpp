// https://www.geeksforgeeks.org/problems/number-of-nges-to-the-right/1
#include<bits/stdc++.h>
using namespace std;
vector<int> count_NGE(int n, vector<int> &arr, int q, vector<int> &indices)
{
    vector<int> ans;
    for (auto it : indices)
    {
        int cnt = 0;
        for (int i = it + 1; i < n; i++)
        {
            if (arr[i] > arr[it])
                cnt++;
        }
        ans.push_back(cnt);
    }
    return ans;
}
int main(){

return 0;
}