class Solution {
public:
    int dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int x,
            int y) {
        visited[x][y] = 1;
        int count = 1;

        int dr[] = {0, 0, 1, -1};
        int dc[] = {1, -1, 0, 0};

        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < 4; i++) {
            int nr = x + dr[i];
            int nc = y + dc[i];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m && !visited[nr][nc] &&
                grid[nr][nc] == 1) {
                count += dfs(grid, visited, nr, nc);
            }
        }

        return count;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && grid[i][j] == 1)
                    ans = max(ans, dfs(grid, visited, i, j));
            }
        }

        return ans;
    }
};