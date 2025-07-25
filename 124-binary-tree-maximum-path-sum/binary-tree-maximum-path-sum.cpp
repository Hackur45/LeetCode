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
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        int a = helper(root,ans);
        return ans;
    }

    int helper(TreeNode* node, int& ans){
        if(node == nullptr) return 0;

        int lsum = max(0,helper(node->left,ans));
        int rsum = max(0,helper(node->right,ans));
        ans = max(ans,node->val+lsum+rsum);

        return node->val + max(lsum,rsum);
    }
};