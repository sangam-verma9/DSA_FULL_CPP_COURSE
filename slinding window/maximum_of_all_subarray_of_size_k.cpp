// https://www.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1
#include<bits/stdc++.h>
using namespace std;
// using map
class Solution
{
public:
    vector<int> max_of_subarrays(int *arr, int n, int k)
    {
        vector<int> ans;
        int i = 0, j = 0;
        map<int, int> mp;
        while (j <= n)
        {
            while (j - i + 1 <= k)
            {
                mp[arr[j]]++;
                j++;
            }
            ans.push_back((--mp.end())->first);
            mp[arr[i]]--;
            if (mp[arr[i]] == 0)
                mp.erase(arr[i]);
            if (j < n)
            {
                mp[arr[j]]++;
            }
            i++, j++;
        }
        return ans;
    }
};

// using deque
class Solution
{
public:
    // Function to find maximum of each subarray of size k.
    vector<int> max_of_subarrays(int *arr, int n, int k)
    {
        // your code here
        vector<int> ans;
        int i = 0, j = 0;
        deque<int> q;
        while (j <= n)
        {
            while (j - i + 1 <= k)
            {
                while (!q.empty() && arr[j] > q.back())
                {
                    q.pop_back();
                }
                q.push_back(arr[j]);

                j++;
            }
            ans.push_back(q.front());
            if (arr[i] == q.front())
                q.pop_front();
            if (j < n)
            {
                while (!q.empty() && arr[j] > q.back())
                {
                    q.pop_back();
                }
                q.push_back(arr[j]);
            }
            i++, j++;
        }
        return ans;
    }
};
int main() {

return 0;
}