// https://www.codingninjas.com/studio/problems/prefix-to-infix_1215000
#include <bits/stdc++.h>
using namespace std;
string prefixToInfixConversion(string &s)
{
    stack<string> st;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            st.push(string(1, s[i]));
        }
        else
        {
            string s1 = st.top();
            st.pop();
            string s2 = st.top();
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