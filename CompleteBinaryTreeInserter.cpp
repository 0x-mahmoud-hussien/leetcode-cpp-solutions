
// https://leetcode.com/problems/complete-binary-tree-inserter
#include <iostream>
#include <queue>
using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};


class CBTInserter {
private:
    TreeNode* root;            
    queue<TreeNode*> q;      

public:
    CBTInserter(TreeNode* r) {
        root = r;
        if (!root) return;

        queue<TreeNode*> temp;
        temp.push(root);

        while (!temp.empty()) {
            TreeNode* node = temp.front();
            temp.pop();

            if (!node->left || !node->right) {
                q.push(node);
            }

            if (node->left)  temp.push(node->left);
            if (node->right) temp.push(node->right);
        }
    }

  
    int insert(int v) {
        TreeNode* parent = q.front();     
        TreeNode* newNode = new TreeNode(v);

     
        if (!parent->left) {
            parent->left = newNode;
        } else {
            parent->right = newNode;
            q.pop();      
        }


        q.push(newNode);

        return parent->val;  
    }


    TreeNode* get_root() {
        return root;
    }
};


int main() 
{
    TreeNode* root = new TreeNode(1, new TreeNode(2), nullptr);

    CBTInserter inserter(root);

    cout << "insert(3) returned parent = " << inserter.insert(3) << endl; 
    cout << "insert(4) returned parent = " << inserter.insert(4) << endl; 

    TreeNode* r = inserter.get_root();
    cout << "root = " << r->val << ", left = " << (r->left? r->left->val : -1)
         << ", right = " << (r->right? r->right->val : -1) << endl;

    return 0;
}