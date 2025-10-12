
// https://leetcode.com/problems/binary-tree-level-order-traversal
#include <iostream>
#include <vector>
#include <queue>
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
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> result;
        if (!root) return result;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int levelSize = q.size();
            vector<int> level;

            for (int i = 0; i < levelSize; i++)
            {
                TreeNode* node = q.front();
                q.pop();

                level.emplace_back(node->val);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            result.emplace_back(level);
        }

        return result;
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
    vector<vector<int>> result = s.levelOrder(root);

    for (auto num : result)
    {
        cout << "[ ";
        for (int val : num)
            cout << val << " ";
        cout << "]\n";
    }

    return 0;
}
