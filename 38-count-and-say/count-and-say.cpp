class Solution {
public:
    string helper(int k , string s){
        if(k == 0){
            return s;
        }

        string ns ="";
        int n = s.length();
        int i = 0;
        while(i < n){
            int ct = 1;

            while( ((i + 1) < n) && s[i] == s[i+1]){
                ct++;
                i++;
            }
            ns = ns + to_string(ct) + s[i];
            i++;
        }
        return helper(k-1,ns);
    }
    string countAndSay(int n) {
        return helper(n-1, "1");
    }
};