// https://www.codingninjas.com/studio/problems/postfix-to-infix_8382386
#include <bits/stdc++.h>
using namespace std;
string postToInfix(string s)
{
    stack<string> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (isalpha(s[i]))
        {
            st.push(string(1, s[i]));
        }
        else
        {
            string s2 = st.top();
            st.pop();
            string s1 = st.top();
            st.pop();
            string temp = "(" + s1 + s[i] + s2 + ")";
            st.push(temp);
        }
    }
    return st.top();
}
int main()
{

    return 0;
}