class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {}; 

        int l = 0;
        int r = matrix[0].size(); 
        int t = 0;
        int b = matrix.size(); 
        vector<int> ans;

        while (l < r && t < b) {
            for (int i = l; i < r; i++) {
                ans.push_back(matrix[t][i]);
            }
            t++;

            for (int i = t; i < b; i++) {
                ans.push_back(matrix[i][r - 1]);
            }
            r--;

            if (t < b) {
                for (int i = r - 1; i >= l; i--) {
                    ans.push_back(matrix[b - 1][i]);
                }
                b--;
            }

            if (l < r) {
                for (int i = b - 1; i >= t; i--) {
                    ans.push_back(matrix[i][l]);
                }
                l++;
            }
        }

        return ans;
    }
};
