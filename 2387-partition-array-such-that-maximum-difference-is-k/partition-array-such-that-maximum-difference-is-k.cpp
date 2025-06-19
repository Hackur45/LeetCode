class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans = 1;
        int t = nums[0];
        for(auto &a : nums){
            if(a - t > k){
                ans++;
                t = a;
            }
        }
        return ans;
    }
};