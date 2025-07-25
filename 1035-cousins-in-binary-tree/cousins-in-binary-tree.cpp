class Solution {
public:
    int helper(TreeNode* node, int tgt, vector<TreeNode*>& arr, TreeNode* parent, int idx) {
        if (node == nullptr) return -1;
        if (node->val == tgt) {
            arr[idx] = parent;
            return 0;
        }
        int ld = helper(node->left, tgt, arr, node, idx);
        if (ld != -1) return ld + 1;
        int rd = helper(node->right, tgt, arr, node, idx);
        if (rd != -1) return rd + 1;
        return -1;
    }

    bool isCousins(TreeNode* root, int x, int y) {
        vector<TreeNode*> arr(2, nullptr);
        int depthX = helper(root, x, arr, nullptr, 0);
        int depthY = helper(root, y, arr, nullptr, 1);
        return (depthX == depthY) && (arr[0] != arr[1]);
    }
};
