#include<bits/stdc++.h>
using namespace std;
// this will work when all numbers are positive
class Solution
{
public:
    int lenOfLongSubarr(int A[], int N, int K)
    {
        int ans = 0;
        int i = 0, j = 0;
        int sum = 0;
        while (j < N)
        {
            sum += A[j];
            if (sum < K)
            {
                j++;
            }
            else if (sum == K)
            {
                ans = max(ans, j - i + 1);
                j++;
            }
            else
            {
                while (sum > K)
                {
                    sum -= A[i];
                    i++;
                }
                if (sum == K)
                    ans = max(ans, j - i + 1);
                j++;
            }
        }
        return ans;
    }
};
int main() {

return 0;
}