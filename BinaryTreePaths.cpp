
// https://leetcode.com/problems/binary-tree-paths
#include <iostream>
#include <vector>
#include <string>
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
    vector<string> binaryTreePaths(TreeNode* root)
    {
        vector<string> result;
        if (!root) return result;

        string path = to_string(root->val);
        dfs(root, path, result);
        return result;
    }
private:
    void dfs(TreeNode* node, string path, vector<string>& result)
    {
        if (!node->left && !node->right)
        {
            result.emplace_back(path);
            return;
        }

        if (node->left)
            dfs(node->left, path + "->" + to_string(node->left->val), result);
        if (node->right)
            dfs(node->right, path + "->" + to_string(node->right->val), result);
    }
};

int main()
{
    TreeNode* root = new TreeNode(1,
                        new TreeNode(2, nullptr, new TreeNode(5)),
                        new TreeNode(3));

    Solution s;
    vector<string> str = s.binaryTreePaths(root);
    vector<string>::iterator it = str.begin();
    for (; it != str.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}

