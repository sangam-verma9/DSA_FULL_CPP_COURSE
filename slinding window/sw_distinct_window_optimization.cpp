// https://practice.geeksforgeeks.org/contest/job-a-thon-33-hiring-challenge/problems
#include <bits/stdc++.h>
using namespace std;
/*
Geek received an array arr[] of size n from his teacher and was tasked with making all elements distinct using two types of operations:
 1- Remove the first element of arr[] and place any element of his choice at the last position.
 2- Remove the last element of arr[] and place any element of his choice at the first position.
 Geek's goal is to minimize the number of operations required to ensure that all elements in arr[] are distinct.
*/
class Solution
{
public:
    int arrayOptimization(int n, vector<int> &arr)
    {
        unordered_map<int, int> mp;
        int right = 0, left = 0, ans = INT_MAX;

        while (right < n)
        {
            mp[arr[right]]++;
            while (mp[arr[right]] > 1 && left < right)
            {
                mp[arr[left]]--;
                left++;
            }

            ans = min(ans, min(2 * left + (n - 1 - right), 2 * (n - 1 - right) + left));
            right++;
        }

        return ans;
    }
};
int main()
{

    return 0;
}