class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> count(3, 0); 
        int l = 0, r = 0, ans = 0, n = s.length();

        for (r = 0; r < n; ++r) {
            count[s[r] - 'a']++;

            while (count[0] > 0 && count[1] > 0 && count[2] > 0) {
                ans += (n - r); 
                count[s[l] - 'a']--;
                l++;
            }
        }
        return ans;
    }
};