class Solution {
public:
    bool hasSpecialSubstring(string s, int k) {
        int n = s.size();
        if (k > n) return false;
        for (int i = 0; i <= n - k; i++) {
            char c = s[i];
            bool allSame = true;
            for (int j = i + 1; j < i + k; j++) {
                if (s[j] != c) {
                    allSame = false;
                    break;
                }
            }
            if (!allSame) continue;
            if (i > 0 && s[i - 1] == c) continue;  
            if (i + k < n && s[i + k] == c) continue;  
            return true;
        }

        return false;
    }
};
