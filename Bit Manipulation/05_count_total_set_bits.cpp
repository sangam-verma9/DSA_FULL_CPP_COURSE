// https://www.codingninjas.com/studio/problems/count-total-set-bits_784
#include<bits/stdc++.h>
using namespace std;
int countSetBits(int N)
{
    if (N == 0)
        return 0;
    int n = N;
    int x = 0;
    while (n)
    {
        x++;
        n /= 2;
    }
    x -= 1;
    int bit0tomax2topower = x * (1 << (x - 1));
    int bitmax2ton = N - (1 << x) + 1;
    int remain = N - (1 << x);
    return bit0tomax2topower + bitmax2ton + countSetBits(remain);
}
int main(){

return 0;
}