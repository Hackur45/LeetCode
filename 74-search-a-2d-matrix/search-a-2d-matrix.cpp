class Solution {
private:
    bool bsearch(vector<vector<int>> &matrix, int rl, int rh, int cl, int ch, int target) {
        while (rl <= rh && cl <= ch) {
            int midRow = (rl + rh) / 2;
            int midCol = (cl + ch) / 2;
            int midVal = matrix[midRow][midCol];

            if (midVal == target) {
                return true;
            } else if (midVal > target) {
                if (bsearch(matrix, rl, midRow - 1, cl, ch, target)) return true;
                if (bsearch(matrix, midRow, rh, cl, midCol - 1, target)) return true;
                return false;
            } else {
                if (bsearch(matrix, midRow + 1, rh, cl, ch, target)) return true;
                if (bsearch(matrix, rl, midRow, midCol + 1, ch, target)) return true;
                return false;
            }
        }

        return false;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        return bsearch(matrix, 0, n - 1, 0, m - 1, target);
    }
};
