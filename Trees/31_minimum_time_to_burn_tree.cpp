// https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    TreeNode *mappingandtarget(TreeNode *root, int target, map<TreeNode *, TreeNode *> &nodeToParent)
    {
        TreeNode *result = NULL;
        queue<TreeNode *> q;
        q.push(root);
        nodeToParent[root] = NULL;
        while (!q.empty())
        {
            TreeNode *front = q.front();
            q.pop();
            if (front->val == target)
            {
                result = front;
            }
            if (front->left)
            {
                nodeToParent[front->left] = front;
                q.push(front->left);
            }
            if (front->right)
            {
                nodeToParent[front->right] = front;
                q.push(front->right);
            }
        }
        return result;
    }
    int burntree(map<TreeNode *, TreeNode *> &nodeToParent, TreeNode *targetNode)
    {
        int ans = 0;
        map<TreeNode *, bool> visited;
        queue<TreeNode *> q;
        q.push(targetNode);
        visited[targetNode] = 1;
        while (!q.empty())
        {
            int size = q.size();
            bool flag = 0;
            for (int i = 0; i < size; i++)
            {
                TreeNode *front = q.front();
                q.pop();
                if (front->left && !visited[front->left])
                {
                    q.push(front->left);
                    visited[front->left] = 1;
                    flag = 1;
                }
                if (front->right && !visited[front->right])
                {
                    q.push(front->right);
                    visited[front->right] = 1;
                    flag = 1;
                }
                if (nodeToParent[front] && !visited[nodeToParent[front]])
                {
                    q.push(nodeToParent[front]);
                    visited[nodeToParent[front]] = 1;
                    flag = 1;
                }
            }
            if (flag == 1)
            {
                ans++;
            }
        }
        return ans;
    }
    int amountOfTime(TreeNode *root, int start)
    {
        // step1- create node to parent mapping
        // step2- find target node
        // burn tree
        map<TreeNode *, TreeNode *> nodeToParent;
        TreeNode *targetNode = mappingandtarget(root, start, nodeToParent);
        int ans = burntree(nodeToParent, targetNode);
        return ans;
    }
};
int main(){

return 0;
}