// https://leetcode.com/problems/remove-k-digits/
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        string st = "";
        for (int i = 0; i < num.size(); i++)
        {
            while (st.length() > 0 && k > 0 && st.back() > num[i])
            {
                st.pop_back();
                k--;
            }
            st.push_back(num[i]);
        }
        while (k)
        {
            st.pop_back();
            k--;
        }
        while (!st.empty() && st[0] == '0')
        {
            st = st.substr(1, st.length() - 1);
        }
        if (st == "")
            return "0";
        return st;
    }
};
int main(){

return 0;
}