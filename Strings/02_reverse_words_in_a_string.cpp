// https://leetcode.com/problems/reverse-words-in-a-string/
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string reverseWords(string s)
    {
        vector<string> v;
        string temp = "";
        bool flag = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ' ' && flag)
            {
                v.push_back(temp);
                flag = 0;
                temp.clear();
            }
            else if (s[i] != ' ')
            {
                temp += (s[i]);
                flag = 1;
            }
        }
        if (temp != "")
        {
            v.push_back(temp);
        }

        reverse(v.begin(), v.end());
        string ans = v[0];
        for (int i = 1; i < v.size(); i++)
        {
            ans += " ";
            ans += v[i];
        }
        return ans;
    }
};
int main(){

return 0;
}