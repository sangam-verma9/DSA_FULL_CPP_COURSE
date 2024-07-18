// https://leetcode.com/problems/find-median-from-data-stream/
#include <bits/stdc++.h>
using namespace std;
class MedianFinder
{
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int n;
    MedianFinder()
    {
        n = 0;
    }

    void addNum(int num)
    {
        pq.push(num);
        n++;
    }

    double findMedian()
    {
        if (n == 1)
            return pq.top();

        int p = n / 2;
        int q = (n + 1) / 2;
        int ele1 = 0, ele2 = 0;
        vector<int> v;
        for (int i = 0; i < p; ++i)
        {
            ele1 = pq.top();
            v.push_back(ele1);
            pq.pop();
        }
        ele2 = pq.top();
        pq.pop();
        v.push_back(ele2);
        for (auto i : v)
            pq.push(i);

        if (n & 1)
        {
            return ele2;
        }
        else
        {
            return (ele1 + ele2) / 2.0;
        }
    }
};

// ****** optimized approcah ******

class MedianFinder
{
public:
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (left.empty() || num <= left.top())
        {
            left.push(num);
        }
        else
        {
            right.push(num);
        }
        // balence
        if (left.size() > right.size() + 1)
        {
            right.push(left.top());
            left.pop();
        }
        else if (right.size() > left.size())
        {
            left.push(right.top());
            right.pop();
        }
    }

    double findMedian()
    {
        if (left.size() == right.size())
        {
            return (left.top() + right.top()) / 2.0;
        }
        else
        {
            return left.top();
        }
    }
};

int main()
{

    return 0;
}