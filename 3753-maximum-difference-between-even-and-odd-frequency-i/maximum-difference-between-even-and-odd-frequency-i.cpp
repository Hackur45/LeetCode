class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char,int> mp;
        for(auto &a : s){
            mp[a]++;
        }

        int a1 = 0 , a2 = INT_MAX;
        for(auto &[key,val] : mp){
            if(val % 2 == 1)
                a1 = max(a1,val);
            else
                a2 = min(a2,val);
        }        

        return a1 - a2;
    }
};