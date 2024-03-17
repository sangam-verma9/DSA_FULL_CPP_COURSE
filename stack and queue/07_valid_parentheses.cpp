// https://leetcode.com/problems/valid-parentheses
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        for (int i = 0; i < s.length(); i++)
        {
            char ch = s[i];
            if (ch == '(' || ch == '{' || ch == '[')
            {
                st.push(ch);
            }
            else
            {
                if (!st.empty())
                {
                    char c = st.top();
                    st.pop();
                    if ((ch == ')' && c == '(') || (ch == '}' && c == '{') || (ch == ']' && c == '['))
                    {
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
        }
        if (!st.empty())
        {
            return false;
        }
        return true;
    }
};
int main()
{

    return 0;
}