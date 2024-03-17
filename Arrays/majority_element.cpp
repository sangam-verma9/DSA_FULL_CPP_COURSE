// https://www.codingninjas.com/studio/problems/majority-element_6783241
#include<bits/stdc++.h>
using namespace std;
// moore's voting algorithm
int majorityElement(vector<int> v)
{
    int cnt = 0;
    int num = 0;
    for (auto i : v)
    {
        if (cnt == 0)
        {
            num = i;
            cnt++;
        }
        else if (i == num)
            cnt++;
        else
        {
            cnt--;
        }
    }
    int cnt1 = 0; 
    for (auto i : v)
        if (i == num)
            cnt1++;
    if (cnt1 > v.size() / 2) // this condition has to be check because there may be not sure about array is majority is present or not if make sure present then not need to check this condition
        return num;
    return -1;
}
int main() {

return 0;
}