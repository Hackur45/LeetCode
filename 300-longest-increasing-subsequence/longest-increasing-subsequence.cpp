const int N = 1e5+10;
class Solution {
public:
    int dp[N];

    Solution() { 
        fill(dp, dp + N, -1); 
    }


    int lis(int i,vector<int> &nums){
        if(dp[i] != -1) return dp[i];
        int ans = 1;
        for(int j=0;j<i;j++){
            if(nums[i] > nums[j]){
                ans = max(ans,lis(j,nums)+1);
            }
        }
        return dp[i] = ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        //Recursive brute force
        for(int i=0;i<n;i++){
            ans = max(ans,lis(i,nums));
        }

        return ans;
    }
};