class Solution {
public:
    vector<string> findSub(string &s,int k){
        vector<string> subStrs;
        int n = s.length();

        for(int i=0;i<=n-k;i++){
            subStrs.push_back(s.substr(i,k));
        }
        return subStrs;
    }
    int minimumRecolors(string blocks, int k) {
        vector<string> subStrs = findSub(blocks,k);
        int bc = 0;
        for(string &s : subStrs){
            int count=0;
            for(auto &a : s){
                if(a == 'B') count++;
            }
            bc = max(bc,count);
        }

        return k-bc;
    }
};