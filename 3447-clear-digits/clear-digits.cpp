class Solution {
public:
    bool isdigit(char c){
        return c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9' || c == '0' ;
    }
    string clearDigits(string s) {
        int n = s.length();
        stack<char> st;

        for(auto &a : s){
            if(!isdigit(a)){
                st.push(a);
            }else{
                st.pop();
            }
        }
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};