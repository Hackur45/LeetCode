class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();
        int ans = -1000;
        for(int i=0;i<n;i++){
            int dif = abs(nums[i] - nums[(i+1) % n]); 
            ans = max(dif , ans);
        }

        return ans;
    }
};