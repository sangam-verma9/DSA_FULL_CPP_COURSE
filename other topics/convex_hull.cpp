#include <bits/stdc++.h>
using namespace std;
// graham scan algorithm for convex hull
bool cw(pair<int, int> a, pair<int, int> b, pair<int, int> c)
{
    return a.first * (b.second - c.second) + b.first * (c.second - a.second) + c.first * (a.second - b.second) > 0;
}
bool ccw(pair<int, int> a, pair<int, int> b, pair<int, int> c)
{
    return a.first * (b.second - c.second) + b.first * (c.second - a.second) + c.first * (a.second - b.second) < 0;
}
bool colliner(pair<int, int> a, pair<int, int> b, pair<int, int> c)
{
    return a.first * (b.second - c.second) + b.first * (c.second - a.second) + c.first * (a.second - b.second) == 0;
}
void convex_hull(vector<pair<int, int>> &p)
{
    int n = p.size();
    sort(p.begin(), p.end());
    auto p1 = p[0], p2 = p[n - 1];
    vector<pair<int, int>> up, down;
    up.push_back(p1);
    down.push_back(p1);
    for (int i = 1; i < n; i++)
    {
        if (i == n - 1 || !ccw(p1, p[i], p2))
        {
            while (up.size() >= 2 && ccw(up[up.size() - 2], up[up.size() - 1], p[i]))
            {
                up.pop_back();
            }
            up.push_back(p[i]);
        }
        if (i == n - 1 || !cw(p1, p[i], p2))
        {
            while (down.size() >= 2 && cw(down[down.size() - 2], down[down.size() - 1], p[i]))
            {
                down.pop_back();
            }
            down.push_back(p[i]);
        }
    }
    // now up and down vectors are contains all the points including repeatedly
    p.clear();
    for (auto it : up)
        p.push_back(it);
    for (auto it : down)
        p.push_back(it);
    sort(p.begin(), p.end());
    p.resize(unique(p.begin(), p.end()) - p.begin());
    return;
}
int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        p[i] = {a, b};
    }
    convex_hull(p);
    for (auto it : p)
    {
        cout << it.first << " " << it.second << endl;
    }
    return 0;
}