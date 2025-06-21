class Solution {
public:
    int minimumDeletions(string w, int k) {
        map<char,int> m;
        for(auto &c : w) m[c]++;
        
        vector<int> f;
        for(auto &p : m) f.push_back(p.second);
        
        sort(f.begin(), f.end());
        int n = f.size(), res = INT_MAX;

        for(int i = 0; i < n; ++i) {
            int x = f[i], cur = 0;
            for(int j = 0; j < n; ++j) {
                if(f[j] < x) cur += f[j];
                else if(f[j] > x + k) cur += f[j] - (x + k);
            }
            res = min(res, cur);
        }
        return res;
    }
};

