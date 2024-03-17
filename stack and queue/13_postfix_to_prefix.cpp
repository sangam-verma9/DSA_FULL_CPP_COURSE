// https://www.codingninjas.com/studio/problems/postfix-to-prefix_1788455
#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
string postfixToPrefix(string &s)
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
            string temp = s[i] + s1 + s2;
            st.push(temp);
        }
    }
    return st.top();
}
int main()
{

    return 0;
}