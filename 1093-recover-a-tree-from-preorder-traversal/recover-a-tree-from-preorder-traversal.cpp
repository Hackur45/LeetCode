/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* recover(string &traversal , int &i, int depth){
        if(i >= traversal.size()) return nullptr;

        int dash = 0;
        while(i + dash < traversal.size() && traversal[i + dash] == '-'){
            dash++;
        }

        if(dash != depth) return nullptr;

        i += dash;

        int val = 0;

        while(i < traversal.size() && isdigit(traversal[i])){
            val = val * 10 + (traversal[i] - '0');
            i++;
        }

        TreeNode* node = new TreeNode(val);

        node->left = recover(traversal,i,depth+1);
        node->right = recover(traversal,i,depth+1);

        return node;
    }
    TreeNode* recoverFromPreorder(string traversal) {
        int i = 0;
        return recover(traversal,i,0);
    }
};