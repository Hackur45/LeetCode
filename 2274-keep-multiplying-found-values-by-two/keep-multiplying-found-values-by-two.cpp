class Solution {
public:
    int findFinalValue(vector<int>& v, int tf) {
        int n = v.size();
        set<int> st;
        for(auto &a : v){
            st.insert(a);
        }

        while(st.find(tf) != st.end()){
            tf *= 2;
        }

        return tf;
    }
};