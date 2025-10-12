
// https://leetcode.com/problems/count-complete-tree-nodes
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
    int countNodes(TreeNode* root)
    {
        if (!root) return 0;

        int leftCount = countNodes(root->left);
        int rightCount = countNodes(root->right);

        return 1 + leftCount + rightCount;
    }
};

int main()
{
    TreeNode* root = new TreeNode(1,
        new TreeNode(2, new TreeNode(5), new TreeNode(6)),
        new TreeNode(4, new TreeNode(10), new TreeNode(8))
    );

    Solution s;

    int counter = s.countNodes(root);
    cout << counter << endl;

    return 0;
}