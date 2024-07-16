// https://leetcode.com/problems/remove-outermost-parentheses/
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string removeOuterParentheses(string s)
    {
        string ans = "";
        stack<char> st;
        int o = 0, c = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
                o++;
            else
                c++;
            st.push(s[i]);
            if (o == c)
            {
                string t = "";
                st.pop();
                while (st.size() > 1)
                {
                    t = st.top() + t;
                    st.pop();
                }
                st.pop();
                ans += t;
            }
        }
        return ans;
    }
};
int main(){

return 0;
}