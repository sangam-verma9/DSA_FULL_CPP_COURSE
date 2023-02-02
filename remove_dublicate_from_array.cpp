#include <bits/stdc++.h>
using namespace std;
int removeDuplicates(vector<int> &nums)
{
    int size = nums.size();
    if (size == 0)
    {
        return 0;
    }
    else if (size == 1)
    {
        return 1;
    }

    else
    {
        int p1 = 0;
        int p2 = 1;
        while (p2 < size)
        {
            while (nums[p1] < nums[p2] && p2 < size)
            {
                p1++;
                p2++;
            }

            while (nums[p1] >= nums[p2] && p2 < size)
            {
                p2++;
            }
            if (nums[p1] != nums[p2] && p2 < size)
            {
                p1++;
                swap(nums[p1], nums[p2]);
            }
        }
        return p1 + 1;
    }
}
int main()
{
     vector<int>nums={1,1,1,2,3,4,5,5,9};
     int k=removeDuplicates(nums);
     for(int i=0; i<k; i++){
        cout<<nums[i]<<" ";
     }
    return 0;
}