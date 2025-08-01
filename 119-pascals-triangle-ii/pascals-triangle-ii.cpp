class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        ans.push_back(1);
        long long int  k = 1;
        for(int i=1;i<=rowIndex;i++){
            k = k * (rowIndex-i+1);
            k = k / i;
            ans.push_back((int)k);
        }
        return ans;
    }
};