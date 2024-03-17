// https://www.codingninjas.com/studio/guided-paths/competitive-programming/content/148629
#include<bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
vector<vector<int>> pwset(vector<int> v)
{
    // Write your code here
    vector<vector<int>> ans;
    int n = v.size();
    for (int i = 0; i < (1 << n); i++)
    {
        vector<int> temp;
        int t = 0;
        int num = i;
        while (num)
        {
            if (num & 1)
            {
                temp.push_back(v[t]);
            }
            t++;
            num >>= 1;
        }
        ans.push_back(temp);
    }
    return ans;
}
int main(){

return 0;
}