
// https://leetcode.com/problems/binary-tree-postorder-traversal
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
    vector<int> postorderTraversal(TreeNode* root)
    {
        vector<int> nums;
        if(!root) return nums;
        printPostOrder(root, nums);
        return nums;
    }
private:
    void printPostOrder(TreeNode* node, vector<int>& nums)
    {
        if (!node) return;
        printPostOrder(node->left, nums);
        printPostOrder(node->right, nums);
        nums.push_back(node->val);
    }
};

int main()
{
    TreeNode* root = new TreeNode(1, nullptr, new TreeNode(2, new TreeNode(3), nullptr));

    Solution s;
    vector<int> result = s.postorderTraversal(root);
    vector<int>::iterator it = result.begin();
    for (; it != result.end(); it++)
    {
        cout << *it << " ";
    }

    cout << endl;
    return 0;
}