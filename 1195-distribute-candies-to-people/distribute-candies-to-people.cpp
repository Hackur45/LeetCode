class Solution {
public:
    vector<int> distributeCandies(int cd, int n) {
        vector<int> ans(n,0);
        int k = 0;
        int to_give = 0;
        int i = 0;
        int m = 1;
        while(cd > 0){
            to_give = min(m, cd);
            cd = cd - to_give;
            ans[i] += to_give;
            i = (i+1) % n;
            m++;
        }
        return ans;
    }
};
