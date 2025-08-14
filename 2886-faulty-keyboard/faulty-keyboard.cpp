class Solution {
public:
    string finalString(string s) {
        string ans = "";

        for(char a : s){
            if(a == 'i'){
                reverse(ans.begin(),ans.end());
            }else{
                ans =  ans + a;
            }
        }

        return ans;
    }
};