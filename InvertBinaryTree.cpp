
// https://leetcode.com/problems/invert-binary-tree
#include <iostream>
using namespace std;

struct TreeNode 
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode*right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) 
    {
        if (!root) return nullptr;

        
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        invertTree(root->left);
        invertTree(root->right);

        return root;
    }

};

void printPreOrder(TreeNode* root)
{
    if (!root) return;
    cout << root->val << "\t";
    printPreOrder(root->left);
    printPreOrder(root->right);

}

int main()
{
    TreeNode* root = new TreeNode(4,
                        new TreeNode(2, new TreeNode(1), new TreeNode(3)),
                        new TreeNode(7, new TreeNode(6), new TreeNode(9)));
    cout << "Before Invert (preOrder): ";
    printPreOrder(root);
    cout << endl;

    Solution s;
    root = s.invertTree(root);

    cout << "After Invert (preOrder): ";
    printPreOrder(root);
    cout << endl;

    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}