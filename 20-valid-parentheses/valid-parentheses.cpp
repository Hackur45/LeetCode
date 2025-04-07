class Solution {
public:
    bool is_open(char a){
        return a == '(' || a == '[' || a == '{';
    }
    bool isValid(string s) {
        stack<char> st;
        int n = s.length();
        map<char,char> mp;
        mp['}'] = '{';
        mp[')'] = '(';
        mp[']'] = '[';
        for(int i=0;i<n;i++){
            if(is_open(s[i])){
                st.push(s[i]);
            }else{
                if (st.empty() || st.top() != mp[s[i]]) {
                    return false;
                }
                st.pop();
            }
        }

        return st.empty();
    }
};