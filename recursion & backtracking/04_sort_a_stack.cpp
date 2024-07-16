// https://www.geeksforgeeks.org/problems/sort-a-stack/1
#include<bits/stdc++.h>
using namespace std;
void pushInBottom(stack<int> &st, int elem)
{

    if (st.empty())
    {
        st.push(elem);
        return;
    }

    if (st.top() < elem)
    {
        st.push(elem);
        return;
    }

    int temp = st.top();
    st.pop();
    pushInBottom(st, elem);
    st.push(temp);
}
void solve(stack<int> &st)
{
    if (st.empty())
        return;
    int top = st.top();
    st.pop();
    solve(st);
    pushInBottom(st, top);
}
int main(){

return 0;
}