// https://www.codingninjas.com/studio/problems/day-23-:-infix-to-postfix-_1382146
#include <bits/stdc++.h>
using namespace std;
int presendece(char ch)
{
    if (ch == '^')
        return 3;
    if (ch == '*' || ch == '/')
        return 2;
    if (ch == '+' || ch == '-')
        return 1;
    return -1;
}
string infixToPostfix(string exp)
{
    stack<char> st;
    string ans = "";
    for (int i = 0; i < exp.size(); i++)
    {
        char ch = exp[i];
        if ((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z'))
        {
            ans += ch;
        }
        else
        {
            if (ch == '(')
                st.push('(');
            else if (ch == ')')
            {
                while (st.top() != '(')
                {
                    ans += st.top();
                    st.pop();
                }
                st.pop();
            }
            else
            {
                while (!st.empty() && presendece(st.top()) >= presendece(ch))
                {
                    ans += st.top();
                    st.pop();
                }
                st.push(ch);
            }
        }
    }
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    return ans;
}
int main()
{

    return 0;
}