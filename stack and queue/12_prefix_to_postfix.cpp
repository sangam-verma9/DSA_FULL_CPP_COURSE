// https://www.codingninjas.com/studio/problems/convert-prefix-to-postfix_8391014
#include <bits/stdc++.h>
using namespace std;
string preToPost(string s)
{
    stack<string> st;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (isalpha(s[i]))
        {
            st.push(string(1, s[i]));
        }
        else
        {
            string s1 = st.top();
            st.pop();
            string s2 = st.top();
            st.pop();
            string temp = s1 + s2 + s[i];
            st.push(temp);
        }
    }
    return st.top();
}
int main()
{

    return 0;
}