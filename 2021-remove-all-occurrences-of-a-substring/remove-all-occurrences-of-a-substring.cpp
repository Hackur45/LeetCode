class Solution {
public:
    string removeOccurrences(string s, string part) {
        string ans="";
        int k = part.length();
        for(auto &c : s){
            ans.push_back(c);

            if(ans.length() >= k && ans.substr(ans.size() - k) == part){
                ans.erase(ans.size() - k);
            }
        }

        return ans;
    }
};