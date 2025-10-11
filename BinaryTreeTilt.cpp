
// https://leetcode.com/problems/binary-tree-tilt
#include <iostream>
#include <cmath>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};

class Solution {
private:
    int totalTilt = 0;

    int dfs(TreeNode* node) 
    {
        if (!node) return 0;

        int leftSum = dfs(node->left);
        int rightSum = dfs(node->right);

        int tilt = abs(leftSum - rightSum);
        totalTilt += tilt;

        return leftSum + rightSum + node->val;
    }

public:
    int findTilt(TreeNode* root) 
    {
        dfs(root);
        return totalTilt;
    }
};

int main() 
{
    TreeNode* root = new TreeNode(4,
        new TreeNode(2, new TreeNode(3), new TreeNode(5)),
        new TreeNode(9, nullptr, new TreeNode(7))
    );

    Solution s;
    cout << "Total Tilt = " << s.findTilt(root) << endl;
    return 0;
}