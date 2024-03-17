// https://leetcode.com/problems/maximal-rectangle/
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> prevs(n), nexts(n);
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && heights[st.top()] >= heights[i])
            {
                st.pop();
            }
            if (st.empty())
            {
                prevs[i] = -1;
            }
            else
                prevs[i] = st.top();
            st.push(i);
        }
        stack<int> ss;
        for (int i = n - 1; i >= 0; i--)
        {
            while (!ss.empty() && heights[ss.top()] >= heights[i])
            {
                ss.pop();
            }
            if (ss.empty())
            {
                nexts[i] = n;
            }
            else
                nexts[i] = ss.top();
            ss.push(i);
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int temp = heights[i] * (nexts[i] - prevs[i] - 1);
            ans = max(ans, temp);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> arr(m, 0);
        for (int i = 0; i < m; i++)
        {
            if (matrix[0][i] == '1')
                arr[i] = 1;
        }
        int ans = largestRectangleArea(arr);
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == '1')
                    arr[j]++;
                else
                    arr[j] = 0;
            }
            ans = max(ans, largestRectangleArea(arr));
        }
        return ans;
    }
};
int main(){

return 0;
}