// https://www.codingninjas.com/studio/problems/minimise-max-distance_7541449
#include <bits/stdc++.h>
using namespace std;
//**** brute force approch ****
double minimiseMaxDistance(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> howmany(n - 1, 0); // create array in which between we put how may gas stations
    for (int i = 1; i <= k; i++) // for each station we calulate which is largest area then that ind we put 
    {
        int ind = 0;
        double maxsection = 0;
        for (int i = 0; i < n - 1; i++)
        {
            double diff = arr[i + 1] - arr[i];
            double sectonlen = diff / (double)(howmany[i] + 1);
            if (sectonlen > maxsection)
            {
                maxsection = sectonlen;
                ind = i;
            }
        }
        howmany[ind]++;
    }
    double ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        double temp = (arr[i + 1] - arr[i]) / (double)(howmany[i] + 1);
        ans = max(ans, temp);
    }
    return ans;
}
//**** priority queue solution ***
double minimiseMaxDistance(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> howmany(n - 1, 0);
    priority_queue<pair<double, int>> pq;
    for (int i = 0; i < n - 1; i++)
    {
        pq.push({arr[i + 1] - arr[i], i});
    }
    for (int i = 1; i <= k; i++)
    {
        auto tp = pq.top();
        pq.pop();
        int secind = tp.second;
        howmany[secind]++;
        double inidiff = arr[secind + 1] - arr[secind];
        double newdiff = inidiff / (double)(howmany[secind] + 1);
        pq.push({newdiff, secind});
    }
    return pq.top().first;
}
// *****
int main()
{

    return 0;
}