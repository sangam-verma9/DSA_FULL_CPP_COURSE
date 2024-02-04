#include <iostream>
using namespace std;
int main()
{
    int arr[] = {12, 34, 10, 56, 17, 39, 46, 22};
    int n = sizeof(arr) / sizeof(int);
    int min_index = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                swap(arr[i], arr[j]);
            }
        }
    }
    cout << "sorted array -> ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}