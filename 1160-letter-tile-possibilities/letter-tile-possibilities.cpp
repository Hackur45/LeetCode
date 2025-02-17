class Solution {
public:
    set<string> st;
    
    void find(string s, map<char, int> mp, string main) {
        if (st.find(s) != st.end()) {
            return;
        }

        st.insert(s);

        for (auto &[key, val] : mp) {
            if (val > 0) {
                mp[key]--; 
                find(s + key, mp, main);  
                find(key + s, mp, main); 
                mp[key]++; 
            }
        }
    }

    int numTilePossibilities(string tiles) {
        map<char, int> mp;
        for (char tile : tiles) {
            mp[tile]++;
        }

        find("", mp, tiles); 
        return st.size() - 1;
    }
};
