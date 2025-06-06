class Solution {
public:
    string robotWithString(string s) {
        unordered_map<char, int> ct;
        for (char ch : s) {
            ct[ch]++;
        }

        stack<char> st;
        string ans;
        char sc = 'a';

        for (char ch : s) {
            st.push(ch);
            ct[ch]--;

            while (sc <= 'z' && ct[sc] == 0) {
                sc++;
            }

            while (!st.empty() && st.top() <= sc) {
                ans.push_back(st.top());
                st.pop();
            }
        }

        return ans;
    }
};
