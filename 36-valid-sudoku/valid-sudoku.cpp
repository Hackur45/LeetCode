class Solution {
public:
    bool boxSafe(int i, int j, char val, vector<vector<char>>& board) {
        int x = i - (i % 3); 
        int y = j - (j % 3);

        for (int k = x; k < x + 3; k++) {
            for (int l = y; l < y + 3; l++) {
                if (board[k][l] == val) { 
                    return false;
                }
            }
        }
        return true;
    }

    bool rowSafe(int i, char val, vector<vector<char>>& board) {
        for (int k = 0; k < 9; k++) {
            if (board[i][k] == val) {
                return false;
            }
        }
        return true;
    }

    bool colSafe(int j, char val, vector<vector<char>>& board) {
        for (int k = 0; k < 9; k++) {
            if (board[k][j] == val) {
                return false;
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        cin.tie(NULL);
        cout.tie(NULL);
        ios_base::sync_with_stdio(false);
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') { 
                    char val = board[i][j];
                    board[i][j] = '.';
                    if (!colSafe(j, val, board) || 
                        !rowSafe(i, val, board) || 
                        !boxSafe(i, j, val, board)) {
                        return false;
                    }
                    board[i][j] = val; 
                }
            }
        }
        return true;
    }
};
