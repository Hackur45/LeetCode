class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int subsets = 1 << n; 
        int ans = 0;

        for (int set = 0; set < subsets; set++) {
            int xr = 0;
            for (int j = 0; j < n; j++) {
                if (set & (1 << j)) {
                    xr ^= nums[j];
                }
            }
            ans += xr;
        }

        return ans;
    }
};
