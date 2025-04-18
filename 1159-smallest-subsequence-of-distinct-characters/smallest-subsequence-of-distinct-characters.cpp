class Solution {
public:
    string smallestSubsequence(string s) {
        unordered_map<char,int> mp;
        unordered_set<char> res;
        stack<char> st;
        for(auto &a : s){
            mp[a]++;
        }

        for(char &c : s){
            mp[c]--;

            if(res.count(c) > 0) continue;

            while(!st.empty() && mp[st.top()] > 0 && c < st.top()){
                res.erase(st.top());
                st.pop();
            }

            st.push(c);
            res.insert(c);
        }

        string ans = "";
        while(!st.empty()){
            ans = ans + st.top();
            st.pop();
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};


