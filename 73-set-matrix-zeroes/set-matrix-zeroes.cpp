class Solution {
public:
    void setCol(vector<vector<int>> &matrix, int col){

        for(int row = 0 ; row < matrix.size();row++){
            matrix[row][col] = 0;
        }
    }

    void setRow(vector<vector<int>> &matrix, int row){
        for(int col = 0; col < matrix[0].size();col++){
            matrix[row][col] = 0;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j] == 0){
                    v.push_back({i,j});
                }
            }
        }

        for(auto &[a,b] : v){
            setRow(matrix,a);
            setCol(matrix,b);
        }
    }
};