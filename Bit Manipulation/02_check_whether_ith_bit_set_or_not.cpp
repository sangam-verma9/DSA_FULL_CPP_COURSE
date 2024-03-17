// https://www.codingninjas.com/studio/problems/check-whether-k-th-bit-is-set-or-not_5026446
#include<bits/stdc++.h>
using namespace std;
bool isKthBitSet(int n, int k)
{
    // Write your code here.
    if (n & (1 << (k - 1)))
        return 1;
    return 0;
}
int main(){

return 0;
}