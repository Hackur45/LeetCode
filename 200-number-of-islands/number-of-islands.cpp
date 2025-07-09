class Solution {
private:
    void bfs(vector<vector<int>> &grid,vector<vector<int>> &visited,int x,int y){
        queue<pair<int,int>> q;
        int n = grid.size();
        int m = grid[0].size();
        q.push({x,y});
        visited[x][y] = 1;
        int dr[] = {1,-1,0,0};
        int dc[] = {0,0,1,-1};
        while(!q.empty()){
            pair<int,int> p = q.front();q.pop();

            for(int i=0;i<4;i++){
                int nr = p.first + dr[i];
                int nc = p.second + dc[i];

                if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1 && !visited[nr][nc]){
                    q.push({nr,nc});
                    visited[nr][nc] = 1;
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& gr) {

        int n = gr.size();
        int m = gr[0].size();
        vector<vector<int>> grid(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(gr[i][j] == '0') grid[i][j] = 0;
                else grid[i][j] = 1;
            }
        }
        vector<vector<int>> visited(n,vector<int>(m,0));

        int ans = 0;
        for(size_t i=0;i<n;i++){
            for(size_t j = 0 ;j<m;j++){
                if(grid[i][j] == 1 && !visited[i][j]){
                    bfs(grid,visited,i,j);
                    ans++;
                }
            }
        }

        return ans;
    }
};