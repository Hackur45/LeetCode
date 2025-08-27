class Solution {
public:
    int dfs(vector<vector<int>> &dp, int m, int n, int i, int j){
        if(i == m-1 && j == n-1) return 1;

        if(i >= m || j >= n) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int rways = 0;
        int dways = 0;

        rways = dfs(dp,m,n,i,j+1); 
        dways = dfs(dp,m,n,i+1,j);

        return dp[i][j] = rways + dways;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        int ans = dfs(dp,m,n,0,0);
        return ans;
    }
};