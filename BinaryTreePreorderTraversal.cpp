
// https://leetcode.com/problems/binary-tree-preorder-traversal
#include <iostream>
#include <vector>
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
    vector<int> preorderTraversal(TreeNode* root) 
    {
        vector<int> nums;

        if (!root) return nums;
        printPreOrder(root, nums);
        return nums;
    }
private:
    void printPreOrder(TreeNode* node, vector<int>& nums)
    {
        if (!node) return;
        nums.emplace_back(node->val);
        printPreOrder(node->left, nums);
        printPreOrder(node->right, nums);
    }
};

int main()
{
    TreeNode* root = new TreeNode(1, nullptr, new TreeNode(2, new TreeNode(3), nullptr));

    Solution s;
    vector<int> result = s.preorderTraversal(root);
    vector<int>::iterator it = result.begin();
    for (; it != result.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}
