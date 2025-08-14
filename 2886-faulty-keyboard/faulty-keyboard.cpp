class Solution {
public:
    string finalString(string s) {
        int i = 0;
        string ans = "";
        for(char &a : s){
            if(a == 'i'){
                i++;
            }else if(i%2 == 0){
                ans = ans + a;
            }else{
                ans = a + ans;
            }
        }
        if(i % 2 == 1){
            reverse(ans.begin(),ans.end());
        }
        return ans;
    }
};