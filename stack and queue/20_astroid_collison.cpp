// https://leetcode.com/problems/asteroid-collision/description/
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &astro)
    {
        int n = astro.size();
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            bool f = true;
            while (!st.empty() && astro[i] < 0 && st.top() > 0)
            {
                int remaining = astro[i] + st.top();
                if (remaining > 0)
                {
                    f = false;
                    break;
                }
                else if (remaining < 0)
                {
                    st.pop();
                }
                else
                {
                    f = false;
                    st.pop();
                    break;
                }
            }
            if (f)
                st.push(astro[i]);
        }
        vector<int> ans;
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
int main(){

return 0;
}