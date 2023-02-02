#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {1, 4, 10, 13, 19, 21, 22};
    int n = sizeof(arr) / sizeof(int);
    int brr[] = {2, 3, 11, 12, 15, 19, 23, 29, 31, 34};
    int m = sizeof(brr) / sizeof(int);
    vector<int> v;
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (arr[i] < brr[j])
        {
            v.push_back(arr[i]);
            i++;
        }
        else
        {
            v.push_back(brr[j]);
            j++;
        }
    }
    for (int k = i; k < n; k++)
    {
        v.push_back(arr[k]);
    }
    for (int k = j; k < m; k++)
    {
        v.push_back(brr[k]);
    }
    for (int k = 0; k < v.size(); k++)
    {
        cout << v[k] << " ";
    }
    return 0;
}