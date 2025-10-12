
// https://leetcode.com/problems/evaluate-boolean-binary-tree
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};

class Solution {
public:
    bool evaluateTree(TreeNode* root)
    {

        if (!root) return false;


        if (root->val == 0) return false;
        if (root->val == 1) return true;

        bool leftVal = evaluateTree(root->left);
        bool rightVal = evaluateTree(root->right);

        if (root->val == 2)
            return leftVal || rightVal;

        return leftVal && rightVal;
    }
};

int main()
{

    TreeNode* root = new TreeNode(2,
                        new TreeNode(1),
                        new TreeNode(3,
                            new TreeNode(0),
                            new TreeNode(1)
                        )
                    );

    Solution s;
    cout << boolalpha << s.evaluateTree(root) << endl;  
}