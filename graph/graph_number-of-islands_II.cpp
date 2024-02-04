/*
You are given a n,m which means the row and column of the 2D matrix and
 an array of  size k denoting the number of operations. Matrix elements
  is 0 if there is water or 1 if there is land. Originally, the 2D matrix
   is all 0 which means there is no land in the matrix. The array has k
    operator(s) and each operator has two integer A[i][0], A[i][1] means
     that you can change the cell matrix[A[i][0]][A[i][1]] from sea to island.
      Return how many island are there in the matrix after each operation.
      You need to return an array of size k.
*/

/*Inorder to solve this q we check each query how many are island now become
with uniquely which is solved by disjointset datastructure , here fisrt we add as indivisual
island then check if there is island prensent at neighbour then reduce the count accordingly
*/

#include <bits/stdc++.h>
using namespace std;
class Disjointset
{
public:
    vector<int> parent, size;
    Disjointset(int n)
    {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }
    int findUPar(int node) // find ultimate parent
    {
        if (node == parent[node])
        {
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }
    void unionBYSize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution
{
private:
    bool isvalid(int newr, int newc, int n, int m)
    {
        return newr >= 0 && newr < n && newc >= 0 && newc < m;
    }

public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators)
    {
        // code here
        Disjointset ds(n * m);
        int visited[n][m];
        memset(visited, 0, sizeof(visited));
        int cnt = 0;
        vector<int> ans;
        for (auto it : operators)
        {
            int row = it[0];
            int col = it[1];
            if (visited[row][col] == 1)
            {
                ans.push_back(cnt);
                continue;
            }
            visited[row][col] = 1;
            cnt++;
            int delr[] = {-1, 0, +1, 0};
            int delc[] = {0, +1, 0, -1};
            for (int i = 0; i < 4; i++)
            {
                int newr = row + delr[i];
                int newc = col + delc[i];
                if (isvalid(newr, newc, n, m))
                {
                    if (visited[newr][newc] == 1)
                    {
                        int nodeno = row * m + col;
                        int adjnodeno = newr * m + newc;
                        if (ds.findUPar(nodeno) != ds.findUPar(adjnodeno))
                        {
                            cnt--;
                            ds.unionBYSize(nodeno, adjnodeno);
                        }
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};
int main()
{

    return 0;
}