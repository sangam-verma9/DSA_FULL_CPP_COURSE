#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void dfs(vector<vector<int>> &ans, vector<vector<int>> &image, int sr, int sc, int &newColor, vector<int> &delr, vector<int> &delc, int &initCol)
    {
        ans[sr][sc] = newColor;
        int n = image.size();
        int m = image[0].size();
        for (int i = 0; i < 4; i++)
        {
            int newr = sr + delr[i];
            int newc = sc + delc[i];
            if (newr < n && newr >= 0 && newc < m && newc >= 0 && image[newr][newc] == initCol && ans[newr][newc] != newColor)
            {
                dfs(ans, image, newr, newc, newColor, delr, delc, initCol);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        vector<vector<int>> ans = image;
        vector<int> delr = {-1, 0, +1, 0};
        vector<int> delc = {0, +1, 0, -1};
        int initCol = image[sr][sc];
        dfs(ans, image, sr, sc, newColor, delr, delc, initCol);
        return ans;
    }
};
int main()
{

    return 0;
}