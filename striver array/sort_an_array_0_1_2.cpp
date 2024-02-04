#include<bits/stdc++.h>
using namespace std;
// better
void sortArray(vector<int> &arr, int n)
{
    // Write your code here
    int one = 0, two = 0, zero = 0;
    for (auto i : arr)
    {
        if (i == 1)
            one++;
        else if (i == 2)
            two++;
        else
            zero++;
    }
    for (int i = 0; i < zero; i++)
        arr[i] = 0;
    for (int i = zero; i < one + zero; i++)
        arr[i] = 1;
    for (int i = one + zero; i < n; i++)
        arr[i] = 2;
}

// optimized (duch national flag algorightm)

void sortArray(vector<int> &arr, int n)
{
    // Write your code here
    int low = 0, mid = 0, high = n - 1;
    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[mid], arr[low]);
            mid++;
            low++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}
int main() {

return 0;
}