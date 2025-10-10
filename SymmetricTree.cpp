
// https://leetcode.com/problems/symmetric-tree
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) 
    {
        if (!root) return true;
        return check(root->left, root->right);
    }

private:
    bool check(TreeNode* left, TreeNode* right) 
    {
        if (!left && !right) return true;   
        if (!left || !right) return false; 
        if (left->val != right->val) return false;
        
        return check(left->left, right->right) && check(left->right, right->left);
    }
};

int main() 
{

    TreeNode* root = new TreeNode(1,new TreeNode(2, new TreeNode(3), new TreeNode(4)),new TreeNode(2, new TreeNode(4), new TreeNode(3)));

    Solution sol;
    if (sol.isSymmetric(root))
        cout << "The tree is symmetric." << endl;
    else
        cout << "The tree is NOT symmetric." << endl;

    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}