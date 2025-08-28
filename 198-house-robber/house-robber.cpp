class Solution {    
public:
    int dfs(vector<int> &dp, vector<int> &nums,int n){
        if(n == 0) return nums[0];

        if(n < 0) return 0;

        if(dp[n] != -1) return dp[n];

        int take = nums[n] + dfs(dp,nums,n-2);
        int not_take = dfs(dp,nums,n-1) + 0;

        return dp[n] = max(take,not_take);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);

        return dfs(dp,nums,n-1);
    }
};