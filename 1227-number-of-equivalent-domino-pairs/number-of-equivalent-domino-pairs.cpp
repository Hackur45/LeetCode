class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int ans = 0;
        map<pair<int, int>, int> mp;
        
        for (auto &a : dominoes) {
            int x = min(a[0], a[1]);
            int y = max(a[0], a[1]);
            ans += mp[{x, y}];  
            mp[{x, y}]++;   
        }

        return ans;
    }
};
