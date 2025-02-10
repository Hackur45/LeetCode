class Solution {
public:
    string longestPalindrome(string s) {
        ___b();
        int n = s.length();
        if (n == 1) return s;
        if (n == 2) {
            if (s[0] == s[1]) return s;
            return string(1, s[0]);
        }
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        int start = 0;
        int ml = 1;

        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }

        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                start = i;
                ml = 2;
            }
        }

        for (int k = 3; k <= n; k++) {
            for (int i = 0; i < n - k + 1; i++) {
                int j = i + k - 1;

                if (dp[i + 1][j - 1] && s[i] == s[j]) {
                    dp[i][j] = true;
                    if (k > ml) {
                        start = i;
                        ml = k;
                    }
                }
            }
        }

        return s.substr(start, ml);
    }

private:
    void ___b(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
};