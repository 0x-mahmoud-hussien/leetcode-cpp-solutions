
// https://leetcode.com/problems/balanced-binary-tree
#include <iostream>
#include <cmath>
using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isBalanced(TreeNode* root) 
    {
        return checkHeight(root) != -1;
    }

private:
    int checkHeight(TreeNode* node) 
    {
        if (!node) return 0;

        int leftHeight = checkHeight(node->left);   
        if (leftHeight == -1) return -1;      

        int rightHeight = checkHeight(node->right); 
        if (rightHeight == -1) return -1;        


        if (abs(leftHeight - rightHeight) > 1) return -1;

        return 1 + max(leftHeight, rightHeight); 
    }
};

int main() 
{
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution sol;
    if (sol.isBalanced(root))
        cout << "The tree is balanced." << endl;
    else
        cout << "The tree is NOT balanced." << endl;

    return 0;
}