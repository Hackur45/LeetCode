class Solution {
public:
    void backtrack(int index, string &s, string &pattern, string &result, bool &found) {
        if (index == s.size()) {
            if (satisfies(s, pattern)) {
                result = s;
                found = true;
            }
            return;
        }

        for (int i = index; i < s.size(); i++) {
            swap(s[i], s[index]);
            if (!found)  
                backtrack(index + 1, s, pattern, result, found);
            swap(s[i], s[index]); 
        }
    }

    bool satisfies(string &perm, string &pattern) {
        for (int i = 0; i < pattern.size(); i++) {
            if (pattern[i] == 'I' && perm[i] > perm[i + 1]) return false;
            if (pattern[i] == 'D' && perm[i] < perm[i + 1]) return false;
        }
        return true;
    }

    string smallestNumber(string pattern) {
        string s = "123456789";
        s = s.substr(0, pattern.size() + 1); 
        string result = "";
        bool found = false;
        backtrack(0, s, pattern, result, found);
        return result;
    }

private:    
    void __b(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
};
