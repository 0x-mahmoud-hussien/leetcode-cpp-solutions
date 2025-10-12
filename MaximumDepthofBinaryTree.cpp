
// https://leetcode.com/problems/maximum-depth-of-binary-tree
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
public:
    int maxDepth(TreeNode* root) 
    {
        if (!root) return 0; 

        if (!root->left && !root->right) 
            return 1;

        if (!root->left)
            return 1 + maxDepth(root->right); 

        if (!root->right)
            return 1 + maxDepth(root->left); 

        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

int main() 
{
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution s;
    cout << "Maximum Depth: " << s.maxDepth(root) << endl;

    return 0;
}