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
    bool solve(int sum,int targetSum,TreeNode* t){
        if(t == NULL){
            return false;
        }
        if (t->left == NULL && t->right == NULL) {
            return (sum + t->val == targetSum);
        }

        return solve(sum + t->val, targetSum, t->left) || solve(sum + t->val, targetSum, t->right);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
         return solve(0, targetSum, root);
    }
};