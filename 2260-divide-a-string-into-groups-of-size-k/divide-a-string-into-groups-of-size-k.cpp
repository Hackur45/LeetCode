class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.length();
        vector<string> ans;

        for(int i = 0; i < n; i += k){
            string temp = "";
            if(i + k <= n){
                temp = s.substr(i, k);
            } else {
                temp = s.substr(i, n - i);
                int z = k - temp.size();
                for(int j = 0; j < z; j++){
                    temp = temp + fill;
                }
            }
            ans.push_back(temp);
        }

        return ans;
    }
};
