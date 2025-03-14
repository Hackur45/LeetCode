class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diff(n + 1, 0);

        for (auto& query : queries) {
            int li = query[0];
            int ri = query[1];

            diff[li]++; 
            if (ri + 1 < n) diff[ri + 1]--;  
        }

        int activeDecrements = 0;
        for (int i = 0; i < n; i++) {
            activeDecrements += diff[i];  
            if (activeDecrements < nums[i]) return false;  
        }

        return true;  
    }
};
