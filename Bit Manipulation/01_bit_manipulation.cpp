// *** important bit operations ***
#include <bits/stdc++.h>
using namespace std;
// find if number is odd or not
bool isodd(int n)
{
    return (n & 1);
}
// get i th bit
int getbit(int n, int i)
{
    return (n & (1 << i));
}
// set i th bit
int setbit(int n, int i)
{
    return (n | (1 << i));
}
// flip i th bit
int flipbit(int n, int i)
{
    return (n ^= (1 << i));
}
// clear i th bit
int clrbit(int n, int i)
{
    return (n & (~(1 << i)));
}
// clear last i bit
int clrLastIBit(int n, int i)
{
    return (n & (~((1 << i) - 1)));
    // or
    int mask = (-1 << i); // -1 = all one bit = (~0) = ((1<<32)-1)
    return (n & (mask));
}
// clear range of bits
int clrRange(int n, int i, int j)
{                   // no. is 000011101011001 wnat clear i=3 to j=8
    int one = (~0); //   mask= 111111000000111
    int a = (one << (j + 1));
    int b = (1 << i) - 1;
    int mask = (a | b);
    return (n & (mask));
}
// checking power of two
bool isPowerOfTwo(int n)
{
    return (n & (n - 1)) == 0;
}
// count set bits
int countSetBits(int n)
{
    int count = 0;
    while (n)
    {
        count++;
        n = (n & (n - 1)); // (n&(n-1)) clears the last set bit
    }
    return count;
}
// unseting rightmost set bit
int unsetRightMostBit(int n)
{
    return (n & (n - 1));
}
// 2's complement of number
int twosComplement(int n)
{
    if (n == 0)
        return 0;
    if (n == -1)
        return 1;
    return (~n) + 1;
}
// getting rightmost set bit
int getRightMostSetBit(int n)
{
    return (n & (-n));
}
// set last cleared bit
int setLastclearedBit(int n)
{
    return (n | (n + 1));
}
// clear last tralling bit
int clearLastTrailingBit(int n)
{
    return (n & (n+1));  // 00110111 -> 00110000
}

int main()
{

    return 0;
}