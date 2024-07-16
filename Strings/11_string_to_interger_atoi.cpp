// https://leetcode.com/problems/string-to-integer-atoi/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int myAtoi(string s)
    {
        bool flag = 1; // positive
        int i = 0, n = s.length();
        for (i; i < n; i++)
        {
            if (s[i] == ' ')
                continue;
            else if (s[i] == '+')
            {
                i++;
                break;
            }
            else if (s[i] == '-')
            {
                flag = 0;
                i++;
                break;
            }
            else
                break;
        }
        // if(i>0)i--;
        // cout<<i<<" "<<s[i]<<endl;

        string t = "";
        for (i; i < n; i++)
        {
            if (s[i] >= '0' && s[i] <= '9')
                t += s[i];
            else
                break;
        }
        // cout<<t<<" flag:"<<flag <<endl;
        // remove leading 0
        string f = "";
        int j = 0;
        while (j < t.length() && t[j] == '0')
            j++;
        f = t.substr(j, t.length() - j);
        if (f.length() == 0)
            return 0;
        // cout<<f<<" "<<flag <<endl;
        if (f.length() <= 9)
        {
            return flag ? stoi(f) : -stoi(f);
        }
        else if (f.length() == 10)
        {
            long long num = stol(f);
            // cout<<"num: "<<num<<endl;
            long long mini = INT_MAX + 1LL, maxi = INT_MAX;
            // cout<<"mini: "<<mini<<endl;
            // cout<<"flag: "<<flag<<endl;
            if (flag && num >= maxi)
                return INT_MAX;
            else if (flag && num < maxi)
                return stoi(f);
            else if (flag == 0 && num >= mini)
                return INT_MIN;
            else if (flag == 0 && num < mini)
                return -stoi(f);
        }
        else
        {
            return flag ? INT_MAX : INT_MIN;
        }
        return 0;
    }
};
int main()
{

    return 0;
}