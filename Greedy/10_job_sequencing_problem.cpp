// https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1
#include <bits/stdc++.h>
using namespace std;
/*
struct Job
{
    int id;     // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline
};
*/

class Solution
{
private:
    static bool cmp(Job a, Job b)
    {
        return (a.profit > b.profit);
    }

public:
    vector<int> JobScheduling(Job arr[], int n)
    {
        sort(arr, arr + n, cmp);
        bool temp[n + 1] = {false};
        int noOfJOb = 0, maxProfit = 0;
        vector<int> result;
        for (int i = 0; i < n; i++)
        {
            for (int j = arr[i].dead; j >= 1; j--)
            {
                if (temp[j] == false)
                {
                    noOfJOb++;
                    temp[j] = true;
                    maxProfit += arr[i].profit;
                    break;
                }
            }
        }

        return {noOfJOb, maxProfit};
    }
};
int main()
{

    return 0;
}