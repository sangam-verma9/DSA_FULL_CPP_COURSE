/*There is one meeting room in a firm. There are N meetings in the form of (S[i], F[i]) where S[i] is the start time of meeting i and F[i] is the finish time of meeting i. The task is to find the maximum number of meetings that can be accommodated in the meeting room. You can accommodate a meeting if the start time of the meeting is strictly greater than the finish time of the previous meeting. Print all meeting numbers.*/
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    static bool comp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
    {
        return a.first < b.first;
    }
    vector<int> maxMeetings(int N, vector<int> &S, vector<int> &F)
    {
        vector<pair<int, pair<int, int>>> v;
        for (int i = 0; i < N; i++)
        {
            pair<int, pair<int, int>> p = make_pair(F[i], make_pair(S[i], i + 1));
            v.push_back(p);
        }
        sort(v.begin(), v.end(), comp);
        vector<int> ans;
        ans.push_back(v[0].second.second);
        int endmeet = v[0].first;
        for (int i = 1; i < N; i++)
        {
            if (v[i].second.first > endmeet)
            {
                ans.push_back(v[i].second.second);
                endmeet = v[i].first;
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> S(n), F(n);
        for (int i = 0; i < n; i++)
        {
            cin >> S[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> F[i];
        }
        Solution ob;
        vector<int> ans = ob.maxMeetings(n, S, F);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i];
            if (i != ans.size() - 1)
            {
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends