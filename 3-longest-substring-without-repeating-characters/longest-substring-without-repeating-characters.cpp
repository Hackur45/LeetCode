class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;

        int n = s.length();
        int l = 0;
        int r = 0;
        int ans = 0;

        while (r < n) {
            if (mp[s[r]] == 0) {
                mp[s[r]]++;
                r++;
                ans = max(ans, r - l); 
            } 
            else {
                mp[s[l]]--;  
                l++;
            }
        }

        return ans;
    }
};
