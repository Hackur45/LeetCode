class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> ans(n, vector<int>(m, -1));
        vector<vector<int>> visited(n, vector<int>(m, 0));
        queue<pair<int, int>> q;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 0) {
                    q.push({i, j});
                    visited[i][j] = 1;
                    ans[i][j] = 0;
                }
            }
        }

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while(!q.empty()) {
            auto [x, y] = q.front(); q.pop();

            for(int i = 0; i < 4; i++) {
                int nx = x + dr[i];
                int ny = y + dc[i];

                if(nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny]) {
                    ans[nx][ny] = ans[x][y] + 1;
                    visited[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }

        return ans;
    }
};
