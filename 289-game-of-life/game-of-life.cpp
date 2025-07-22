class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                int ocs = 0;
                for (int dr = -1; dr <= 1; dr++) {
                    for (int dc = -1; dc <= 1; dc++) {
                        if (i + dr >= 0 && i + dr < n && j + dc >= 0 &&
                            j + dc < m) {
                            if (dr == 0 && dc == 0)
                                continue;
                            if (abs(board[i + dr][j + dc]) == 1)
                                ocs++;
                        }
                    }
                }

                if (board[i][j] == 1 && (ocs < 2 || ocs > 3)) { //dead or extenstion
                    board[i][j] = -1;
                } else if (board[i][j] == 0 && ocs == 3) { // regeneration and retention
                    board[i][j] = 2;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == -1)
                    board[i][j] = 0;
                else if (board[i][j] == 2)
                    board[i][j] = 1;
            }
        }
    }
};