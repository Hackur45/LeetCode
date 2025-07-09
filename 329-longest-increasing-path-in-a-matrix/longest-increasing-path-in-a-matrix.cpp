class Solution {
public:
    int dfs(vector<vector<int>> &matrix, vector<vector<int>> &dp, int x,int y){
        if(dp[x][y] != 0) return dp[x][y];

        int n = matrix.size();
        int m = matrix[0].size();

        int ans = 1;
        int dr[] = {1,-1,0,0};
        int dc[] = {0,0,1,-1};

        for(int i=0;i<4;i++){
            int nr = dr[i] + x;
            int nc = dc[i] + y;

            if(nr >= 0 && nr < n && nc < m & nc >= 0 && matrix[x][y] < matrix[nr][nc]){
                ans = max(ans , 1 + dfs(matrix,dp,nr,nc));
            }
        } 

        return dp[x][y] = ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n,vector<int>(m,0));

        int ans = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans = max(ans,dfs(matrix,dp,i,j));
            }
        }

        return ans;
    }
};