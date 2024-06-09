// https://www.codingninjas.com/studio/problems/ninja-and-the-second-order-elements_6581960
#include <bits/stdc++.h>
using namespace std;
vector<int> getSecondOrderElements(int n, vector<int> a)
{
    sort(a.begin(), a.end());
    return {a[n - 2], a[1]};
}
int main()
{

    return 0;
}