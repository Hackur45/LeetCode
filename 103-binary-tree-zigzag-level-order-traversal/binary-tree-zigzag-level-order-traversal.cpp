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
    /*
    * Deque aur flag use kiya har level ka direction toggle karne ke liye.
    * Root null hone par crash kyunki nullptr deque me gaya aur curr->val dereference hua.
    * Hamesha push\_front use kiya is wajah se children ka order bigad gaya, zigzag ka sequence galat hoga.
    * Idea sahi tha: deque se front/back nikalna aur direction badalna.
    * Fix chahiye: root null check karo aur direction ke hisaab se kabhi push\_back, kabhi push\_front use karo
    */
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr) return ans;
        deque<TreeNode*> q;
        q.push_front(root);
        bool flag = false;
        
        vector<int> temp;

        while(!q.empty()){
            int n = q.size();
            while(n--){
                if(flag){
                    TreeNode* curr = q.back(); q.pop_back();
                    temp.push_back(curr->val);

                    if(curr->right) q.push_front(curr->right);
                    if(curr->left) q.push_front(curr->left);
                }else{
                    TreeNode* curr = q.front(); q.pop_front();
                    temp.push_back(curr->val);
                    if(curr->left) q.push_back(curr->left);
                    if(curr->right) q.push_back(curr->right);
                }
            }
            ans.push_back(temp);
            flag = !flag;
            temp.clear();
        }

        return ans;
    }
};