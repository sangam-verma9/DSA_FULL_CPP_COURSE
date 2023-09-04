#include <bits/stdc++.h>
using namespace std;
void generatesubseq(int arr[], int n, vector<vector<int>> &ans, int ind, vector<int> temp)
{
    if (ind >= n)
    {
        ans.push_back(temp);
        temp.clear();
        return;
    }
    temp.push_back(arr[ind]);
    generatesubseq(arr, n, ans, ind + 1, temp);
    temp.pop_back();
    generatesubseq(arr, n, ans, ind + 1, temp);
}
int main()
{
    int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(int);
    vector<vector<int>> ans;
    vector<int> temp;
    int ind = 0;
    int cnt = 0;
    generatesubseq(arr, n, ans, ind, temp);
    cout << "[";
    for (auto i : ans)
    {
        cout << "[";
        cnt++;
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << "]";
    }
    cout << "]";
    cout << endl
         << cnt << endl;
    return 0;
}