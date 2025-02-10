class Solution {
public:
    bool isdigit(char c){
        return c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9' || c == '0' ;
    }
    string clearDigits(string s) {
        int n = s.length();
        vector<char> v;

        for(auto &a : s){
            if(!isdigit(a)){
                v.push_back(a);
            }else{
                v.pop_back();
            }
        }
        string ans = "";
        for(auto &a:v){
            ans += a;
        }
        return ans;
    }
};