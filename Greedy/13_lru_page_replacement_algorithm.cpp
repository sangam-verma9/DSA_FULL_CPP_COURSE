// https://www.geeksforgeeks.org/problems/page-faults-in-lru5603/1
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int pageFaults(int N, int C, int pages[])
    {
        // code here
        vector<int> v;
        int fault = 0;
        for (int i = 0; i < N; i++)
        {
            int x = pages[i];
            if (find(v.begin(), v.end(), x) == v.end())
            {
                fault++;
                if (v.size() == C)
                {
                    v.erase(v.begin());
                    v.push_back(x);
                }
                else
                {
                    v.push_back(x);
                }
            }
            else
            {
                v.erase(find(v.begin(), v.end(), x));
                v.push_back(x);
            }
        }
        return fault;
    }
};
int main(){

return 0;
}