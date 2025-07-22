class Solution {
private:
    int dfs(vector<vector<int>> &grid,vector<vector<int>> &visited,int r,int c){
        int n = grid.size();
        int m = grid[0].size();

        if(r < 0 || r >= n || c < 0 || c >= m){
            return INT_MAX;
        }
        if(r == n-1 && c == m-1){
            return grid[r][c];
        }
        if(visited[r][c] != -1){
            return  visited[r][c];
        }
        int sum = grid[r][c];
        // int dr[] = {1,0};
        // int dc[] = {0,1};

        // for(int i=0;i<2;i++){
        //     int nr = dr[i] + r;
        //     int nc = dc[i] + c;
        // }

        sum += min(dfs(grid,visited,r+1,c), dfs(grid,visited,r,c+1));
        visited[r][c] = 0;

        return visited[r][c] = sum;
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,-1));
        return dfs(grid,visited,0,0);
    }
};