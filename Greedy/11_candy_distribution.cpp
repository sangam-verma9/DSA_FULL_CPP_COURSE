// https://leetcode.com/problems/candy/
#include<bits/stdc++.h>
using namespace std;
// first approach
class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int n = ratings.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        left[0] = 1, right[n - 1] = 1;
        for (int i = 1; i < n; i++)
        {
            if (ratings[i] > ratings[i - 1])
            {
                left[i] = left[i - 1] + 1;
            }
            else
                left[i] = 1;
        }
        for (int i = n - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1])
            {
                right[i] = right[i + 1] + 1;
            }
            else
                right[i] = 1;
        }
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += max(left[i], right[i]);
        }
        return sum;
    }
};

// ***second approach*** //
// can be implemented using only using one array and for 
//right array we take two variables and take max value and take sum as well at same time 

// ***** third approach ****// 
//(using slope concept when we have +ve then adding +1 to curr val ,
// if negative then -1 to curr val and if 0 slope then add +1 to ans )

class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int ans = 1;
        int n = ratings.size();
        int i = 1;
        while (i < n)
        {
            if (ratings[i] == ratings[i - 1])
            {
                ans += 1;
                i++;
                continue;
            }
            int peak = 1;
            while (i < n && ratings[i] > ratings[i - 1])
            {
                peak++;
                ans += peak;
                i++;
            }
            int down = 1;
            while (i < n && ratings[i] < ratings[i - 1])
            {
                ans += down;
                down++;
                i++;
            }
            if (down > peak)
            {
                ans += (down - peak);
            }
        }
        return ans;
    }
};

int main(){

return 0;
}