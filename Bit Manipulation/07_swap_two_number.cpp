// https://www.codingninjas.com/studio/problems/swap-two-numbers_1380853
#include<bits/stdc++.h>
using namespace std;
void swapNumber(int &a, int &b)
{
    a = (a ^ b);
    b = (a ^ b);
    a = (a ^ b);
}
int main(){

return 0;
}