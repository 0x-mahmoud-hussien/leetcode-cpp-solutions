
// https://leetcode.com/problems/univalued-binary-tree
#include <iostream>
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
    bool isUnivalTree(TreeNode* root)
    {
        if (!root) return true;

        return check(root, root->val);
    } 
private:
    bool check(TreeNode* node, int value)
    {
        if (!node) return true;

        if (node->val != value) return false;

        return check(node->left, value) && check(node->right, value);
    }
};

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(1);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(1);
    root->right->right = new TreeNode(1);

    Solution s;
    cout << boolalpha << s.isUnivalTree(root) << endl;

    TreeNode* root2 = new TreeNode(2);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(5);
    cout << boolalpha << s.isUnivalTree(root2) << endl;

    return 0;
}