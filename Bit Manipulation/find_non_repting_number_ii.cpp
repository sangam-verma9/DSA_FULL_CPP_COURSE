//  https://www.codingninjas.com/studio/guided-paths/competitive-programming/content/148629/offering/1792858
#include<bits/stdc++.h>
using namespace std;
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