class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        map<int,vector<int>> mp;

        if(n == 1){
            return 1;
        }
        for(auto &a : trust){
            mp[a[1]].push_back(a[0]);
        }

        vector<int> v;

        for(auto &a : mp){
            if(a.second.size() == n-1){
                v.push_back(a.first);
            }
        }

        map<int,vector<int>> op;
        for(auto &a : trust){
            op[a[0]].push_back(a[1]);
        }

        for(auto &a : v){
            if(op[a].empty()){
                return a;
            }
        }

        return -1;
    }
};