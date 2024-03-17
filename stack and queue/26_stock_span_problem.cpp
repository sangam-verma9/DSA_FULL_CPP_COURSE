// https://leetcode.com/problems/online-stock-span/
#include<bits/stdc++.h>
using namespace std;
class StockSpanner
{
public:
    stack<pair<int, int>> s;
    StockSpanner()
    {
    }

    int next(int price)
    {
        int curspan = 1;
        while (!s.empty() && s.top().first <= price)
        {
            int prevspan = s.top().second;
            s.pop();
            curspan += prevspan;
        }
        s.push({price, curspan});
        return curspan;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
int main(){

return 0;
}