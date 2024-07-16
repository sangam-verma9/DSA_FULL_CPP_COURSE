// https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxDepth(string s)
    {
        int cnt = 0;
        int ans = 0;
        for (auto it : s)
        {
            if (it == '(')
            {
                cnt++;
                ans = max(ans, cnt);
            }
            else if (it == ')')
                cnt--;
        }
        return ans;
    }
};
int main(){

return 0;
}