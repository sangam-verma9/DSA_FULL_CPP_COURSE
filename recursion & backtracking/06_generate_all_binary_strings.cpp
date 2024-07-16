// https://www.geeksforgeeks.org/problems/generate-all-binary-strings/0
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void solve(int ind, int &num, string s, vector<string> &ans)
    {
        if (ind >= num)
        {
            ans.push_back(s);
            return;
        }
        solve(ind + 1, num, s, ans);
        s[ind] = '1';
        solve(ind + 2, num, s, ans);
        s[ind] = '0';
    }
    vector<string> generateBinaryStrings(int num)
    {
        // Write your code
        vector<string> ans;
        string s(num, '0');
        solve(0, num, s, ans);
        return ans;
    }
};
int main(){

return 0;
}