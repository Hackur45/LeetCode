class Solution {
public:
    bool isSubsequence(string s, string t) {
        int l = 0;
        int ans = 0;

        for(int i=0;i<t.size();i++){
            if(s[l] == t[i]){
                l++;
                ans++;
            }
        }
        if(ans  == s.size()) return true;

        return false;
    }
};