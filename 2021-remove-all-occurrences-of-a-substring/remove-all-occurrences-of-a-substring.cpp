class Solution {
public:
    string removeOccurrences(string s, string part) {
        stack<char> st;
        int m = part.length();

        for(char c : s) {
            st.push(c);
            
            if (st.size() >= m) {
                string temp = "";
                for (int j = m - 1; j >= 0; j--) {
                    temp = st.top() + temp; 
                    st.pop();
                }

                if (temp != part) { 
                    for (char ch : temp) {
                        st.push(ch);
                    }
                }
            }
        }

        string ans = "";
        while (!st.empty()) {
            ans = st.top() + ans; 
            st.pop();
        }
        return ans;
    }
};
