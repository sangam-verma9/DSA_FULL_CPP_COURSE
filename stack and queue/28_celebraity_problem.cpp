// https://www.codingninjas.com/studio/problems/the-celebrity-problem_982769
#include<bits/stdc++.h>
using namespace std;
/*
    This is signature of helper function 'knows'.
    You should not implement it, or speculate about its implementation.

    bool knows(int A, int B);
    Function 'knows(A, B)' will returns "true" if the person having
    id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n)
{
    stack<int> st;
    for (int i = 0; i < n; i++)
        st.push(i);
    while (st.size() > 1)
    {
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();
        if (knows(a, b) && knows(b, a))
        {
            continue;
        }
        else if (knows(a, b))
        {
            st.push(b);
        }
        else
            st.push(a);
    }
    if (st.empty())
        return -1;
    int ans = st.top();
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (knows(i, ans))
            cnt++;
    }
    if (cnt == n - 1)
        return ans;
    return -1;
}
int main(){

return 0;
}