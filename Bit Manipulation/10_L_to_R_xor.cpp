// https://www.naukri.com/code360/problems/l-to-r-xor_8160412
#include <bits/stdc++.h>
using namespace std;
int fn(int x)
{
    if (x % 4 == 1)
        return 1;
    else if (x % 4 == 2)
        return x + 1;
    else if (x % 4 == 3)
        return 0;
    else
        return x;
}
int findXOR(int L, int R)
{
    // Write your code here.
    int ans = fn(L - 1) ^ fn(R);
    return ans;
}
int main()
{

    return 0;
}