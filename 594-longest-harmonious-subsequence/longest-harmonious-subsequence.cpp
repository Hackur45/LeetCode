class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int ans = 0;
        int l = 0;

        for(int i=0;i<n;i++){
            while(nums[i] - nums[l] > 1){
                l++;
            }

            if(nums[i] - nums[l] == 1){
                ans = max(ans, i-l+1);
            }
        }

        return ans;
    }
};