class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        unordered_map<int, int> postIndex;
        for (int i = 0; i < postorder.size(); i++) {
            postIndex[postorder[i]] = i;
        }
        
        int preIndex = 0;
        return construct(preorder, postorder, postIndex, preIndex, 0, postorder.size() - 1);
    }
    
private:
    TreeNode* construct(vector<int>& preorder, vector<int>& postorder, unordered_map<int, int>& postIndex, int& preIndex, int left, int right) {
        if (preIndex >= preorder.size() || left > right) return nullptr;
        
        TreeNode* root = new TreeNode(preorder[preIndex++]);
        
        if (preIndex < preorder.size() && left <= right) {
            int postPos = postIndex[preorder[preIndex]];
            if (postPos <= right) {
                root->left = construct(preorder, postorder, postIndex, preIndex, left, postPos);
                root->right = construct(preorder, postorder, postIndex, preIndex, postPos + 1, right - 1);
            }
        }
        
        return root;
    }
};