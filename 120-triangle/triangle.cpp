class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
        int n = t.size();
        // vector<vector<int>> dp(n,vector<int>(n,-1));
        vector<int> prev(n,0);

        for(int i=0;i<n;i++){
            prev[i] = t[n-1][i];
        }
        vector<int> curr(n,0);
        for(int i = n-2; i>= 0; i--){
            for(int j=0;j<=i;j++){
                curr[j] = min(prev[j]+t[i][j],prev[j+1] +t[i][j]);
            }
            prev = curr;
        }

        return prev[0];
    }
};