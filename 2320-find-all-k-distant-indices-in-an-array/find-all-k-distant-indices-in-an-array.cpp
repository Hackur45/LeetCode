class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        set<int> res;
        vector<int> pos;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == key) pos.push_back(i);
        }
        for (int j : pos) {
            int l = max(0, j - k);
            int r = min(n - 1, j + k);
            for (int i = l; i <= r; ++i) {
                res.insert(i);
            }
        }
        return vector<int>(res.begin(), res.end());
    }
};
