// https://www.naukri.com/code360/problems/unique-binary-tree_8180906
#include <bits/stdc++.h>
using namespace std;
// if both are either (inorder, preorder) or (inorder ,postorder)
int uniqueBinaryTree(int a, int b)
{
    if (a + b == 5 || a + b == 3)
        return true;
    return false;
}
int main()
{

    return 0;
}