class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();
        int i = entrance[0];
        int j = entrance[1];

        queue<pair<pair<int, int>, int>> q;
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        q.push({{i, j}, 0});
        maze[i][j] = '+';

        while (!q.empty()) {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int d = q.front().second;
            q.pop();

            for (auto& dir : dirs) {
                int nx = x + dir[0];
                int ny = y + dir[1];

                if (nx >= 0 && nx < n && ny >= 0 && ny < m && maze[nx][ny] == '.') {
                    if ((nx == 0 || ny == 0 || nx == n - 1 || ny == m - 1) &&
                        !(nx == entrance[0] && ny == entrance[1])) {
                        return d + 1;
                    }
                    maze[nx][ny] = '+';
                    q.push({{nx, ny}, d + 1});
                }
            }
        }

        return -1;
    }
};
