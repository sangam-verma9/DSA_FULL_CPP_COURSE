// https://www.codingninjas.com/studio/problems/replace-each-element-of-array-with-its-corresponding-rank_975384
#include <bits/stdc++.h>
using namespace std;
vector<int> replaceWithRank(vector<int> &arr, int n)
{
    vector<int> temp = arr;
    sort(temp.begin(), temp.end());
    unordered_map<int, int> hashMap;
    int rank = 1;
    for (int i = 0; i < n; i++)
    {
        if (!hashMap.count(temp[i]))
        {
            hashMap[temp[i]] = rank;
            rank++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = hashMap[arr[i]];
    }
    return arr;
}
int main()
{

    return 0;
}