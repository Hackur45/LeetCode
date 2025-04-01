class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        long long n = questions.size();
        vector<long long> dp(n, 0);

        for (long long i = n - 1; i >= 0; i--) {
            long long index = i + questions[i][1] + 1;
            long long take = questions[i][0] + (index < n ? dp[index] : 0);
            long long skip = (i + 1 < n) ? dp[i + 1] : 0;
            dp[i] = max(take, skip);
        }

        return dp[0];
    }
};
