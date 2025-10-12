
// https://leetcode.com/problems/diameter-of-binary-tree
#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    int maxDiameter = 0; 

    int depth(TreeNode* node)
    {
        if (!node) return 0; 

        int leftDepth = depth(node->left);
        int rightDepth = depth(node->right);

        int currentDiameter = leftDepth + rightDepth;

        maxDiameter = max(maxDiameter, leftDepth + rightDepth);

        return 1 + max(leftDepth, rightDepth);
    }

public:
    int diameterOfBinaryTree(TreeNode* root)
    {
        depth(root);
        return maxDiameter; 
    }
};

int main()
{
    TreeNode* root = new TreeNode(1,
        new TreeNode(2, new TreeNode(4), new TreeNode(5)),
        new TreeNode(3));

    Solution s;
    cout << "Diameter of tree = " << s.diameterOfBinaryTree(root) << endl;

    return 0;
}