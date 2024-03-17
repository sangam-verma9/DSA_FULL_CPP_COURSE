// https://www.codingninjas.com/studio/guided-paths/competitive-programming/content/148629
#include<bits/stdc++.h>
using namespace std;
int elementThatAppearsOnce(vector<int> arr)
{
    // Write your code here.
    vector<int> a(32, 0);
    for (int i = 0; i <= 31; i++)
    {
        for (int j = 0; j < arr.size(); j++)
        {
            if (arr[j] & (1 << i))
                a[i]++;
        }
    }
    for (int i = 0; i < 32; i++)
    {
        a[i] %= 3;
    }
    int x = 0;
    for (int i = 0; i < 32; i++)
    {
        if (a[i])
        {
            x |= (1 << i);
        }
    }
    return x;
}
int main(){

return 0;
}
