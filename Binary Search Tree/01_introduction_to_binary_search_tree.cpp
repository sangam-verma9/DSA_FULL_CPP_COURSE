// https://www.geeksforgeeks.org/problems/binary-search-trees/1
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isBSTTraversal(vector<int> &arr)
    {
        // your code here
        for (int i = 0; i < arr.size() - 1; i++)
        {
            if (arr[i] >= arr[i + 1])
                return false;
        }
        return true;
    }
};
int main()
{

    return 0;
}