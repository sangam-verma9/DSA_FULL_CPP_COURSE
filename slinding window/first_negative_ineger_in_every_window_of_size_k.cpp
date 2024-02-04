#include<bits/stdc++.h>
using namespace std;
// solution -1 usnig map
vector<long long> printFirstNegativeInteger(long long int A[],long long int N, long long int K)
{
    vector<long long> ans;
    int i = 0, j = 0;
    map<int, int> mp;
    while (j <= N)
    {
        while (j - i + 1 <= K)
        {
            if (A[j] < 0)
                mp[j] = A[j];
            j++;
        }
        if (mp.size() > 0)
        {
            ans.push_back(mp.begin()->second);
        }
        else
        {
            ans.push_back(0);
        }
        if (mp.find(i) != mp.end())
            mp.erase(i);
        if (j < N)
        {
            if (A[j] < 0)
                mp[j] = A[j];
        }
        i++, j++;
    }
    return ans;
}
// solution -2 using queue
vector<long long> printFirstNegativeInteger(long long int A[],long long int N, long long int K)
{
    vector<long long> ans;
    int i = 0, j = 0;
    queue<int> q;
    while (j <= N)
    {
        while (j - i + 1 <= K)
        {
            if (A[j] < 0)
                q.push(A[j]);
            j++;
        }
        if (q.size() > 0)
        {
            ans.push_back(q.front());
        }
        else
        {
            ans.push_back(0);
        }
        if (q.front() == A[i])
            q.pop();
        if (j < N)
        {
            if (A[j] < 0)
                q.push(A[j]);
        }
        i++, j++;
    }
    return ans;
}
int main() {

return 0;
}