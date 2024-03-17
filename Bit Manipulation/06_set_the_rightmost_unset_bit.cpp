// https://www.codingninjas.com/studio/problems/set-the-rightmost-unset-bit_8160456
#include<bits/stdc++.h>
using namespace std;
//** first method ****
int setBits(int N)
{

    int n = N;
    int cnt = 0;
    while (n)
    {
        if (!(n & 1))
        {
            N = (N | (1 << cnt));
            break;
        }
        cnt++;
        n >>= 1;
    }
    return N;
}
//** second method ****
int setBits(int N)
{
    // Check if there's any unset bits.
    if ((N & (N + 1)) == 0)
        return N;

    // Set the least significant unset bit of ‘N’ to 1 and return.
    return N | (N + 1);
}
//*** third method ***
int setBits(int N)
{
    int x = N;

    // Find the position of the lest significant unset bit.
    while (x & 1 != 0)
    {
        x = x >> 1;
    }

    // Check if there's any unset bit, if not return 'N'
    if (x == 0)
    {
        return N;
    }

    // Set the least significant unset bit of ‘N’ to 1 and return.
    return N | (N + 1);
}
int main(){

return 0;
}