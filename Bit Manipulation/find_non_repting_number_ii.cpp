//  https://www.codingninjas.com/studio/guided-paths/competitive-programming/content/148629/offering/1792858
#include<bits/stdc++.h>
using namespace std;

/*
    ---example for get rightmost set bit---
    x:             01110000
    ~x:            10001111
    -x or ~x + 1:  10010000
    x & -x:        00010000
*/
vector<int> findNonRepeating(vector<int> a)
{
    int n = 0;
    for (auto i : a)
    {
        n ^= i;
    }
    int t = (n & (-n));  // find last set bit of n
    int num1 = 0;
    for (auto i : a)
    {
        if (i & t)       // find number who has bit set as t set then take xor
        {
            num1 ^= i;
        }
    }
    int num2 = (n ^ num1);
    return {num1, num2};
}
int main(){

return 0;
}