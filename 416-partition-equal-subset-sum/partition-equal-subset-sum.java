class Solution {
    public static boolean dfs(int[] arr,int x,int sum,int[][] dp){
        if(sum == 0) return true;

        if(sum < 0 || x >= arr.length) return false;

        if(dp[x][sum] != -1){
            if(dp[x][sum] == 1) return true;
            else return false;
        }
        boolean ans = dfs(arr,x+1,sum,dp) || dfs(arr,x+1,sum-arr[x],dp);
        dp[x][sum] = ans ? 1 : 0;
        return ans;
    }
    public boolean canPartition(int[] nums) {
        int n = nums.length;
        int sum = 0;
        
        for(int i=0;i<n;i++){
            sum += nums[i];
        }
        if(sum % 2 == 1) return false;
        int[][] dp = new int[n][sum+1];
        for(int i=0;i<n;i++){
            Arrays.fill(dp[i],-1);
        }

        return dfs(nums,0,sum/2,dp);
    }
}