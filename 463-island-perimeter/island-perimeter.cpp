class Solution {
public:
    void dfs(vector<vector<int>> &grid, vector<vector<int>> &visited, int x,int y,int *ans){
        visited[x][y] = 1;

        int n = grid.size();
        int m = grid[0].size();

        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};

        for(int i=0;i<4;i++){
            int nr = x + dr[i];
            int nc = y + dc[i];

            if (nr < 0 || nr >= n || nc < 0 || nc >= m || grid[nr][nc] == 0) {
                (*ans)++;
            } else if (!visited[nr][nc]) {
                dfs(grid, visited, nr, nc, ans);
            }
        }
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j] == 1){
                    dfs(grid,visited,i,j,&ans);
                    return ans;
                }
            }
        }

        return ans;
    }
};