class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        ___b();
        unordered_map<string,vector<string> > mp;

        for(auto &a : strs){
           string str = a;
           sort(str.begin(),str.end());
           mp[str].push_back(a);
        }

        vector<vector<string>> ans;
        for(auto &[key,val] : mp){
            ans.push_back(val);
        }

        return ans;
    }
private: 
    void ___b(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
};
